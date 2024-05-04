# Load the new dataset
import numpy as np
from matplotlib import pyplot as plt

data2 = np.loadtxt('dataset2.txt')

# Separate the dataset into x (independent variable) and y (dependent variable)
x2 = data2[:, 0]
y2 = data2[:, 1]

# We need to add a column of ones to x to account for the bias term in the linear model
X2 = np.vstack([x2, np.ones(len(x2))]).T

# Find the least squares solution
theta2, residuals2, rank2, s2 = np.linalg.lstsq(X2, y2, rcond=None)

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(x2, y2, 'ro', label='Original data')  # Original data points
plt.plot(x2, X2.dot(theta2), 'b-', label='Fitted line')  # Fitted line
plt.xlabel('x')
plt.ylabel('y')
plt.title('Data and Least Squares Solution for Dataset 2')
plt.legend()
plt.show()
