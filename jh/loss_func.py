import numpy as np

def mean_squared_error(y, t):
	return 0.5 * np.sum((y - t) ** 2);

def cross_entropy_error(y, t):
	delta = 1e-7
	return -np.sum(t * np.log(y + delta))

y1 = [.1, .05, .6, 0, .05, .1, 0, .1, 0, 0]
y2 = [.1, .05, .1, 0, .05, .1, 0, .6, 0, 0]
t = [0, 0, 1, 0, 0, 0, 0, 0, 0, 0]

print("==== mean squared error ====")
print("output for 2", mean_squared_error(np.array(y1), np.array(t)))
print("output for 6", mean_squared_error(np.array(y2), np.array(t)))

print()

print("==== cross entropy error ====")
print("output for 2", cross_entropy_error(np.array(y1), np.array(t)))
print("output for 6", cross_entropy_error(np.array(y2), np.array(t)))
