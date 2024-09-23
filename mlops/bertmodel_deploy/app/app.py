from fastapi import FastAPI
import os
from scripts import s3
from scripts.data_model import BertInput, BertOuput

app = FastAPI(debug=True)

model_name = "tinybert-sentiment-analysis"
local_path = os.path.join("ml-models", model_name)

if not os.path.isdir(local_path):
    s3.download_dir(local_path, model_name)


import torch
from transformers import pipeline
# device = torch.device("cuda") if torch.cuda.is_available() else torch.device("cpu")
device = torch.device("mps") if torch.backends.mps.is_available() else torch.device("cpu")
model = pipeline("text-classification", model=local_path, device=device)


@app.get("/")
def index():
    return {"Hello": "FastAPI"}

@app.post("/api/v1/sentiment")
def sentiment_analysis(data: BertInput):
    pass