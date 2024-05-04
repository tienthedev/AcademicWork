import numpy as np


def rotation_matrix(angle, axis):

    axis = axis / np.linalg.norm(axis)

    I = np.eye(3)
    cross_matrix = np.array([[0, -axis[2], axis[1]],
                             [axis[2], 0, -axis[0]],
                             [-axis[1], axis[0], 0]])

    R = I + np.sin(angle) * cross_matrix + (1 - np.cos(angle)) * cross_matrix @ cross_matrix

    return R


angle = np.pi / 4
rotation_axis = np.array([1, 0, 0])

resulting_matrix = rotation_matrix(angle, rotation_axis)
print("Rotation Matrix:")
print(resulting_matrix)
