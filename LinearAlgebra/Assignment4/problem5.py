import numpy as np
import matplotlib.pyplot as plt


def cosine_similarity_matrix(matrix):

    dot_product_matrix = np.dot(matrix, matrix.T)

    norms = np.linalg.norm(matrix, axis=1, keepdims=True)

    similarity_matrix = dot_product_matrix / (norms @ norms.T)

    return similarity_matrix


def generate_random_matrix(M, N):

    return np.random.rand(M, N)


def plot_similarity_matrix(similarity_matrix):

    plt.matshow(similarity_matrix, cmap='viridis')
    plt.colorbar()
    plt.title('Cosine Similarity Matrix')
    plt.show()


if __name__ == "__main__":
    M, N = 5, 3
    random_matrix = generate_random_matrix(M, N)

    similarity_matrix = cosine_similarity_matrix(random_matrix)

    plot_similarity_matrix(similarity_matrix)
