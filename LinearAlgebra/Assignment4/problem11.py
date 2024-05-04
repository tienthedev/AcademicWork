import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


def homogeneous_rotation_matrix(angle, axis):
    axis = axis / np.linalg.norm(axis)
    R = np.eye(4)
    R[:3, :3] = np.array([
        [1, 0, 0],
        [0, np.cos(angle), -np.sin(angle)],
        [0, np.sin(angle), np.cos(angle)]
    ])
    return R


def inverse_homogeneous_rotation_matrix(angle, axis):
    return homogeneous_rotation_matrix(-angle, axis)


x = np.array([1, 2, 1, 1])

rotation_angle = -np.pi / 2
rotation_axis = np.array([1, 0, 0])

M = inverse_homogeneous_rotation_matrix(rotation_angle, rotation_axis)

reversed_point = M @ homogeneous_rotation_matrix(rotation_angle, rotation_axis) @ x

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.scatter(x[0], x[1], x[2], color='red', marker='o', label='Original Point')
ax.scatter(reversed_point[0], reversed_point[1], reversed_point[2], color='green', marker='^', label='Reversed Point')

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.legend()
plt.title('Homogeneous Rotation Reversed')

plt.show()
