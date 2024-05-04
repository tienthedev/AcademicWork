import numpy as np
from scipy.linalg import solve


def change_basis(vector, in_standard_basis=True, basis_B=None):
    if in_standard_basis:
        return vector
    else:
        if basis_B is None:
            raise ValueError("Basis vectors 'basis_B' are required when in_standard_basis is False.")

        coefficients = solve(basis_B.T, vector)
        transformed_vector = basis_B @ coefficients

        return transformed_vector


basis_B = np.array([[0, -4, 6],
                    [-1, 0, 6],
                    [-1, 0, 3]])

x = np.array([[-18],
              [8],
              [5]])

x_B = np.array([[-2],
                [6],
                [1]])

transformed_x_to_B = change_basis(x, in_standard_basis=True, basis_B=basis_B)
transformed_x_B_to_standard = change_basis(x_B, in_standard_basis=False, basis_B=basis_B)

print("Vector x in basis B:")
print(transformed_x_to_B)

print("\nVector [x]_B in the standard basis:")
print(transformed_x_B_to_standard)
