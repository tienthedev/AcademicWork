import matplotlib.pyplot as plt
import numpy as np

A = np.array([[1, -2],
              [-4, 1]])

eigenvalues, eigenvectors = np.linalg.eig(A)

fig, ax = plt.subplots()

ax.quiver(0, 0, 1, 0, angles='xy', scale_units='xy', scale=1, color='r', label='Standard basis e1')
ax.quiver(0, 0, 0, 1, angles='xy', scale_units='xy', scale=1, color='g', label='Standard basis e2')

ax.quiver(0, 0, A[0, 0], A[1, 0], angles='xy', scale_units='xy', scale=1, color='b', label='A column 1')
ax.quiver(0, 0, A[0, 1], A[1, 1], angles='xy', scale_units='xy', scale=1, color='y', label='A column 2')

for i in range(len(eigenvalues)):
    eigvec = eigenvectors[:, i].real
    ax.quiver(0, 0, eigvec[0], eigvec[1], angles='xy', scale_units='xy', scale=1, alpha=0.5,
              label=f'Eigenvector {i + 1}')

ax.set_aspect('equal')

plt.xlim(-5, 5)
plt.ylim(-5, 5)

plt.grid(True)
plt.legend()
plt.title('Standard basis, columns of A, and eigenvectors')
plt.xlabel('X-axis')
plt.ylabel('Y-axis')

plt.show()
