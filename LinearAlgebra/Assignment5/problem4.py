import numpy as np
import matplotlib.pyplot as plt

# Load the dataset
data = np.loadtxt('dataset1.txt')

# Separate the dataset into x (independent variable) and y (dependent variable)
x = data[:, 0]
y = data[:, 1]

# We need to add a column of ones to x to account for the bias term in the linear model
X = np.vstack([x, np.ones(len(x))]).T

# Find the least squares solution
theta, residuals, rank, s = np.linalg.lstsq(X, y, rcond=None)

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(x, y, 'ro', label='Original data')  # Original data points
plt.plot(x, X.dot(theta), 'b-', label='Fitted line')  # Fitted line
plt.xlabel('x')
plt.ylabel('y')
plt.title('Data and Least Squares Solution')
plt.legend()
plt.show()
