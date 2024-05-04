
import numpy as np

# Set random seed for reproducibility
np.random.seed(0)

# (a) Create a Python program that generates a random N x M matrix X.
N, M = 5, 3
X = np.random.randn(N, M)

# (b) Compute the eigendecomposition of the covariance matrix X^T X.
Covariance_Matrix = X.T @ X
eigenvalues, eigenvectors = np.linalg.eig(Covariance_Matrix)

# (c) Project the computed eigenvectors onto the data via matrix multiplication and normalize them.
eigenvectors_normalized = eigenvectors / np.linalg.norm(eigenvectors, axis=0)

# (d) Compute the singular value decomposition of the matrix X.
U, S, Vt = np.linalg.svd(X, full_matrices=False)

# Observations for comparison:
# - The columns of U are the eigenvectors of XX^T.
# - The columns of V (from SVD) are the eigenvectors of X^TX.
# - The singular values in S are the square roots of the eigenvalues of X^TX (or XX^T).
# - The eigenvectors (columns of U and V) are normalized to have unit length.

# The following lines will print the comparisons for analysis.
print("Eigenvalues:", eigenvalues)
print("Normalized eigenvectors:\n", eigenvectors_normalized)
print("U matrix from SVD:\n", U)

# Comparing the singular values and the square roots of the eigenvalues
singular_values_sqrt = np.sqrt(S**2)
print("Singular values (squared and square-rooted):", singular_values_sqrt)
print("Eigenvalues:", eigenvalues)

# The U matrix should be similar to the normalized eigenvectors of XX^T and
# the square root of the singular values should be similar to the eigenvalues of X^TX.

# NOTE: There can be a sign difference in corresponding eigenvectors from SVD and eigendecomposition
# due to the fact that eigenvectors are only determined up to a sign. They are still valid as long
# as they are consistent within their respective decompositions.
