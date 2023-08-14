#include <iostream>
#include <vector>

using namespace std;

// Función para realizar la multiplicación de matrices
vector<vector<int>> matrix_multiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    int m = A[0].size();
    int p = B[0].size();
    
    vector<vector<int>> result(n, vector<int>(p, 0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < m; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return result;
}

int main() {
    // Definir las matrices A y B
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> B = {{7, 8}, {9, 10}, {11, 12}};
    
    // Realizar la multiplicación de matrices
    vector<vector<int>> result = matrix_multiply(A, B);
    
    // Imprimir la matriz resultante
    cout << "Resultado de la multiplicación de matrices:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
