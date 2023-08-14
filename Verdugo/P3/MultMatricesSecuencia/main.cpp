#include <iostream>
#include <vector>
#include <limits>

// Función para imprimir la matriz
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << "\t";
        }
        std::cout << "\n";
    }
}

// Función para multiplicar la cadena de matrices
int matrixChainOrder(const std::vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            m[i][j] = std::numeric_limits<int>::max();
            for (int k = i; k < j; ++k) {
                int cost = m[i][k] + m[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                }
            }
        }
    }

    std::cout << "Matriz de costo mínimo:\n";
    printMatrix(m); // Llama a la función para imprimir la matriz

    return m[0][n - 1];
}

int main() {
    // A es 1x2, B es 2x3, C es 3x4, D es 4x5
    std::vector<int> dimensions = {1, 2, 3, 4, 5};

    int result = matrixChainOrder(dimensions);
    std::cout << "El costo mínimo de multiplicación es " << result << std::endl;
    return 0;
}
