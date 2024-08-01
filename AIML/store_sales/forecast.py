import os

import pandas as pd
import numpy as np

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler

import torch
import torch.nn as nn
import torch.functional as F
from torch.utils.data import DataLoader, TensorDataset


home_dir = "./data"

test = pd.read_csv(os.path.join(home_dir, "test.csv"))
train = pd.read_csv(os.path.join(home_dir, "train.csv"))
oil = pd.read_csv(os.path.join(home_dir, "oil.csv"))
stores = pd.read_csv(os.path.join(home_dir, "stores.csv"))
transactions = pd.read_csv(os.path.join(home_dir, "transactions.csv"))
holidays_events = pd.read_csv(os.path.join(home_dir, "holidays_events.csv"))

train['date'] = pd.to_datetime(train['date'])
test['date'] = pd.to_datetime(test['date'])
oil['date'] = pd.to_datetime(oil['date'])
transactions['date'] = pd.to_datetime(transactions['date'])
holidays_events['date'] = pd.to_datetime(holidays_events['date'])

train.drop('id', axis=1, inplace=True)
test.drop('id', axis=1, inplace=True)


# holiday events
def set_holiday(x):
    if x['type'] == 'Holiday' or x['type'] == 'Event':
        return f"{x['locale']}_{x['type']}"
    else:
        return f"{x['locale']}_Holiday"


holidays_events['holiday_type'] = holidays_events.apply(set_holiday, axis=1)
holidays_events.drop(holidays_events[holidays_events.loc[:, 'transferred'] == True].index, inplace=True)
holidays_events.drop(holidays_events.columns.difference(['date', 'holiday_type']), axis=1, inplace=True)

# oil
oil.ffill(inplace=True)

# merge
# train
train_merged_data = pd.merge(train, stores, on='store_nbr', how='left')
train_merged_data = pd.merge(train_merged_data, oil, on='date', how='left')
train_merged_data = pd.merge(train_merged_data, holidays_events, on='date', how='left', suffixes=('', '_holiday'))
train_merged_data = pd.merge(train_merged_data, transactions, on=['date', 'store_nbr'], how='left')

train_merged_data['holiday_type'] = train_merged_data['holiday_type'].fillna('NA')
train_merged_data['holiday'] = train_merged_data.apply(lambda x: x['holiday_type'] if x['holiday_type'] != 'NA' else ('Weekdays' if x['date'].weekday() == 1 else 'Weekends'), axis=1)

# test
test_merged_data = pd.merge(test, stores, on='store_nbr', how='left')
test_merged_data = pd.merge(test_merged_data, oil, on='date', how='left')
test_merged_data = pd.merge(test_merged_data, holidays_events, on='date', how='left', suffixes=('', '_holiday'))
test_merged_data = pd.merge(test_merged_data, transactions, on=['date', 'store_nbr'], how='left')

test_merged_data['holiday_type'] = test_merged_data['holiday_type'].fillna('NA')
test_merged_data['holiday'] = test_merged_data.apply(lambda x: x['holiday_type'] if x['holiday_type'] != 'NA' else ('Weekdays' if x['date'].weekday() == 1 else 'Weekends'), axis=1)


train_merged_data = train_merged_data[train_merged_data['date'] >= '2013-01-02']

train_merged_data = train_merged_data.drop('holiday_type', axis=1)
test_merged_data = test_merged_data.drop('holiday_type', axis=1)

train_merged_data['dcoilwtico'] = train_merged_data['dcoilwtico'].ffill()
train_merged_data['transactions'] = train_merged_data['transactions'].fillna(0)

test_merged_data['dcoilwtico'] = test_merged_data['dcoilwtico'].ffill()
test_merged_data['transactions'] = test_merged_data['transactions'].fillna(0)


train_data = pd.get_dummies(train_merged_data.set_index(['date', 'store_nbr', 'family']))
test_data = pd.get_dummies(test_merged_data.set_index(['date', 'store_nbr', 'family']))

# split test validation set
X = train_data.loc[:, train_data.columns.difference(['sales'])]
y = train_data.loc[:, 'sales']
test_data = test_data.reindex(columns = X.columns, fill_value=0)
X_train, X_valid, y_train, y_valid = train_test_split(X, y, test_size=0.2, shuffle=False)


device = torch.device("cuda" if torch.cuda.is_available() else ("mps" if torch.backends.mps.is_available() else "cpu"))

scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_valid_scaled = scaler.transform(X_valid)

X_train_tensor = torch.tensor(X_train_scaled, dtype=torch.float32).to(device)
y_train_tensor = torch.tensor(y_train.values, dtype=torch.float32).to(device)
X_valid_tensor = torch.tensor(X_valid_scaled, dtype=torch.float32).to(device)
y_valid_tensor = torch.tensor(y_valid.values, dtype=torch.float32).to(device)

train_dataset = TensorDataset(X_train_tensor, y_train_tensor)
valid_dataset = TensorDataset(X_valid_tensor, y_valid_tensor)

train_loader = DataLoader(train_dataset, batch_size=64, shuffle=False)
valid_loader = DataLoader(valid_dataset, batch_size=64, shuffle=False)


class SalesLSTM(nn.Module):
    def __init__(self, input_dim, hidden_dim, num_layers, output_dim):
        super(SalesLSTM, self).__init__()
        self.hidden_dim = hidden_dim
        self.num_layers = num_layers
        self.lstm = nn.LSTM(input_dim, hidden_dim, num_layers, batch_first=True)
        self.fc = nn.Linear(hidden_dim, output_dim)
        self.epsilon = 1e-6

    def forward(self, x):
        batch_size = x.size(0)
        h0 = torch.zeros(self.num_layers, batch_size, self.hidden_dim).to(x.device)
        c0 = torch.zeros(self.num_layers, batch_size, self.hidden_dim).to(x.device)
        out, (hn, cn) = self.lstm(x, (h0.detach(), c0.detach()))
        out = self.fc(out[:, -1, :])
        return torch.clamp(out, min=self.epsilon)


class RMSLELoss(nn.Module):
    def __init__(self, epsilon=1e-6):
        super().__init__()
        self.mse = nn.MSELoss()
        self.epsilon = epsilon

    def forward(self, pred, actual):
        pred = torch.clamp(pred, min=self.epsilon)
        actual = torch.clamp(actual, min=self.epsilon)
        return torch.sqrt(self.mse(torch.log(pred + 1), torch.log(actual + 1)))


input_dim = X_train_tensor.shape[1]
hidden_dim = 100
num_layers = 2
output_dim = 1

model = SalesLSTM(input_dim, hidden_dim, num_layers, output_dim).to(device)

criterion = RMSLELoss()
optimizer = torch.optim.Adam(model.parameters(), lr=0.01)

num_epochs = 20
for epoch in range(num_epochs):
    model.train()
    for inputs, labels in train_loader:
        inputs, labels = inputs.to(device), labels.to(device)
        inputs = inputs.unsqueeze(1)

        optimizer.zero_grad()
        outputs = model(inputs)
        loss = criterion(outputs, labels.view(-1, 1))
        loss.backward()
        optimizer.step()

    model.eval()
    val_loss = 0
    with torch.no_grad():
        for inputs, labels in valid_loader:
            inputs, labels = inputs.to(device), labels.to(device)
            inputs = inputs.unsqueeze(1)

            outputs = model(inputs)
            loss = criterion(outputs, labels.view(-1, 1))
            val_loss += loss.item()

    print(f'Epoch [{epoch+1}/{num_epochs}] Loss: {loss.item()}, Validation Loss: {val_loss/len(valid_loader)}')

X_test_scaled = scaler.transform(test_data[X.columns])
X_test_tensor = torch.tensor(X_test_scaled, dtype=torch.float32).to(device)

test_dataset = TensorDataset(
    X_test_tensor, torch.zeros(len(X_test_tensor)).to(device))
test_loader = DataLoader(test_dataset, batch_size=64, shuffle=False)

model.eval()
predictions = []
with torch.no_grad():
    for inputs, _ in test_loader:
        inputs = inputs.to(device)
        inputs = inputs.unsqueeze(1)
        outputs = model(inputs)
        predictions.append(outputs.cpu().numpy())

predictions = np.concatenate(predictions, axis=0)

output = pd.read_csv(os.path.join(home_dir, "test.csv"))[['id']]
output['sales'] = predictions
output.to_csv('./data/output.csv')
