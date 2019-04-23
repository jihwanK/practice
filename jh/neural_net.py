import numpy as np

def sigmoid(x):
  return 1 / (1 + np.exp(-x))

def identify_function(x):
  return x

def softmax_old(x):
  exp_x = np.exp(x)
  sum_exp_x = np.sum(exp_x)
  y = exp_x / sum_exp_x
  return y

def softmax(x):
  c = np.max(x)
  exp_x = np.exp(x - c)
  sum_exp_x = np.sum(exp_x)
  y = exp_x / sum_exp_x
  return y

def init_network():
  network = {}
  network['W1'] = np.array([[.1, .3, .5], [.2, .4, .6]])
  network['W2'] = np.array([[.1, .4], [.2, .5], [.3, .6]])
  network['W3'] = np.array([[.1, .3], [.2, .4]])

  network['b1'] = np.array([.1, .2, .3])
  network['b2'] = np.array([.1, .2])
  network['b3'] = np.array([.1, .2])

  return network


def forward(network, x):
  W1, W2, W3 = network['W1'], network['W2'], network['W3']
  b1, b2, b3 = network['b1'], network['b2'], network['b3']

  a1 = np.dot(x, W1) + b1
  z1 = sigmoid(a1)
  a2 = np.dot(z1, W2) + b2
  z2 = sigmoid(a2)
  a3 = np.dot(z2, W3) + b3
  y = identify_function(a3)

  return y


##################################################################
##################################################################

if __name__ == "__main__":
  '''    
  network = init_network()
  x = np.array([1, .5])
  y = forward(network, x)
  print(y)
  '''

  a = np.array([1010, 1000, 990])
  print(softmax_old(a))
  print(softmax(a))
