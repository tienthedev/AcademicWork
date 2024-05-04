import numpy as np
import sympy

# Given matrix A
A = np.array([[4, 8, -5],
              [-3, -6, -7],
              [2, 4, 2]])

# Given vector b
b = np.array([-1, -1, 3])

# (a) Compute the reduced echelon form of A and convert the result back to a numpy array
reduced_echelon_form, pivot_columns = sympy.Matrix(A).T.rref()
reduced_echelon_form_A = np.array(reduced_echelon_form).T

# Print the reduced echelon form of A
print("Reduced Echelon Form of A:")
print(reduced_echelon_form_A)

# (b) Find the column space of A
column_space_A = A[:, pivot_columns]

# Print the column space of A
print("\nColumn Space of A:")
print(column_space_A)

# (c) Solve the regularized matrix equation Ax = b
epsilon = 1e-10  # Small positive value for regularization
solution_x = np.linalg.solve(A.T @ A + epsilon * np.identity(A.shape[1]), A.T @ b)

# Print the solution x for Ax = b
print("\nSolution x for Ax = b:")
print(solution_x)

# (d) Compute Nul A (Null space of A)
nul_A = sympy.Matrix(A).nullspace()
nul_A_np = [np.array(vec).reshape(-1, 1) for vec in nul_A]

# Print the null space of A
print("\nNull space of A:")
for vec in nul_A_np:
    print(vec)
