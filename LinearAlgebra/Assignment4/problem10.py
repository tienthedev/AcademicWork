import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


def homogeneous_rotation_matrix(angle, axis):

    axis = axis / np.linalg.norm(axis)

    T1 = np.eye(4)
    T1[:3, 3] = -np.array([1, -2, 2])

    R = np.eye(4)
    R[:3, :3] = np.array([
        [1, 0, 0],
        [0, np.cos(angle), -np.sin(angle)],
        [0, np.sin(angle), np.cos(angle)]
    ])

    T2 = np.eye(4)
    T2[:3, 3] = np.array([1, -2, 2])

    T = T2 @ R @ T1

    return T


x = np.array([1, 2, 1, 1])

rotation_angle = -np.pi / 2
rotation_axis = np.array([1, 0, 0])

T = homogeneous_rotation_matrix(rotation_angle, rotation_axis)

resulting_point = T @ x

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.scatter(x[0], x[1], x[2], color='red', marker='o', label='Original Point')
ax.scatter(resulting_point[0], resulting_point[1], resulting_point[2], color='blue', marker='x', label='Rotated Point')

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.legend()
plt.title('Homogeneous Rotation')

plt.show()
