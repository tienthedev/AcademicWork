import numpy as np


def perspective_matrix(focal_length, image_plane_distance):

    M = np.array([
        [focal_length / image_plane_distance, 0, 0, 0],
        [0, focal_length / image_plane_distance, 0, 0],
        [0, 0, -1 / image_plane_distance, -1],
        [0, 0, 0, 0]
    ])
    return M


def transform_point(M, point):

    transformed_point = M @ point
    return transformed_point[:2] / transformed_point[2]


if __name__ == "__main__":
    x1 = np.array([1, 1, 0, 1])
    x2 = np.array([4, 3, 0, 1])
    x3 = np.array([5, 0, 0, 1])

    focal_length = 1.0
    image_plane_distance = 1.0

    M = perspective_matrix(focal_length, image_plane_distance)

    x1_prime = transform_point(M, x1)
    x2_prime = transform_point(M, x2)
    x3_prime = transform_point(M, x3)

    print("Perspective Matrix M:")
    print(M)

    print("\nTransformed Points:")
    print("x1' =", x1_prime)
    print("x2' =", x2_prime)
    print("x3' =", x3_prime)
