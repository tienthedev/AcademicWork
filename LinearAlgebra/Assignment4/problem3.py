import sympy as sp


def find_basis_dimension():

    a, b, c = sp.symbols('a b c')

    vectors = [
        sp.Matrix([2 * b + 3 * c, a + b - 2 * c, 4 * a + b, 3 * a - b - c])
    ]

    matrix_A = sp.Matrix(vectors)

    row_echelon_form, pivot_columns = matrix_A.T.rref()

    dimension = len(pivot_columns)

    basis = [vectors[i] for i in pivot_columns]

    return dimension, basis


if __name__ == "__main__":
    dimension, basis = find_basis_dimension()

    print(f"Dimension of the set: {dimension}")
    print("Basis for the set:")
    for vector in basis:
        print(vector)
