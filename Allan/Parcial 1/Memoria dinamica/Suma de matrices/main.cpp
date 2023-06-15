#include <iostream>

// Función para sumar matrices de forma recursiva
int** sumarMatricesRecursivo(int** matriz1, int** matriz2, int filas, int columnas) {
    // Caso base: matriz de 1x1
    if (filas == 1 && columnas == 1) {
        int** resultado = new int*[1];
        resultado[0] = new int[1];
        resultado[0][0] = matriz1[0][0] + matriz2[0][0];
        return resultado;
    }

    // Dividir las matrices en submatrices de tamaño reducido
    int half_filas = filas / 2;
    int half_columnas = columnas / 2;

    int** a11 = new int*[half_filas];
    int** a12 = new int*[half_filas];
    int** a21 = new int*[filas - half_filas];
    int** a22 = new int*[filas - half_filas];
    int** b11 = new int*[half_filas];
    int** b12 = new int*[half_filas];
    int** b21 = new int*[filas - half_filas];
    int** b22 = new int*[filas - half_filas];

    for (int i = 0; i < half_filas; i++) {
        a11[i] = new int[half_columnas];
        a12[i] = new int[half_columnas];
        b11[i] = new int[half_columnas];
        b12[i] = new int[half_columnas];
        for (int j = 0; j < half_columnas; j++) {
            a11[i][j] = matriz1[i][j];
            a12[i][j] = matriz1[i][j + half_columnas];
            b11[i][j] = matriz2[i][j];
            b12[i][j] = matriz2[i][j + half_columnas];
        }
    }

    for (int i = half_filas; i < filas; i++) {
        a21[i - half_filas] = new int[half_columnas];
        a22[i - half_filas] = new int[half_columnas];
        b21[i - half_filas] = new int[half_columnas];
        b22[i - half_filas] = new int[half_columnas];
        for (int j = 0; j < half_columnas; j++) {
            a21[i - half_filas][j] = matriz1[i][j];
            a22[i - half_filas][j] = matriz1[i][j + half_columnas];
            b21[i - half_filas][j] = matriz2[i][j];
            b22[i - half_filas][j] = matriz2[i][j + half_columnas];
        }
    }

    // Calcular las submatrices de forma recursiva
    int** c11 = sumarMatricesRecursivo(a11, b11, half_filas, half_columnas);
    int** c12 = sumarMatricesRecursivo(a12, b12, half_filas, half_columnas);
    int** c21 = sumarMatricesRecursivo(a21, b21, filas - half_filas, half_columnas);
    int** c22 = sumarMatricesRecursivo(a22, b22, filas - half_filas, half_columnas);

    // Combinar las submatrices para obtener la matriz resultante
    int** resultado = new int*[filas];
    for (int i = 0; i < filas; i++) {
        resultado[i] = new int[columnas];
        for (int j = 0; j < columnas; j++) {
            if (i < half_filas && j < half_columnas) {
                resultado[i][j] = c11[i][j];
            } else if (i < half_filas && j >= half_columnas) {
                resultado[i][j] = c12[i][j - half_columnas];
            } else if (i >= half_filas && j < half_columnas) {
                resultado[i][j] = c21[i - half_filas][j];
            } else {
                resultado[i][j] = c22[i - half_filas][j - half_columnas];
            }
        }
    }

    // Liberar la memoria de las submatrices
    for (int i = 0; i < half_filas; i++) {
        delete[] a11[i];
        delete[] a12[i];
        delete[] b11[i];
        delete[] b12[i];
        delete[] c11[i];
        delete[] c12[i];
    }
    for (int i = half_filas; i < filas; i++) {
        delete[] a21[i - half_filas];
        delete[] a22[i - half_filas];
        delete[] b21[i - half_filas];
        delete[] b22[i - half_filas];
        delete[] c21[i - half_filas];
        delete[] c22[i - half_filas];
    }

    delete[] a11;
    delete[] a12;
    delete[] a21;
    delete[] a22;
    delete[] b11;
    delete[] b12;
    delete[] b21;
    delete[] b22;
    delete[] c11;
    delete[] c12;
    delete[] c21;
    delete[] c22;

    return resultado;
}

// Función para imprimir una matriz
void imprimirMatriz(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Definir las matrices
    int filas, columnas;
    std::cout << "Ingrese las dimensiones de las matrices (filas columnas): ";
    std::cin >> filas >> columnas;

    // Crear las matrices
    int** matriz1 = new int*[filas];
    int** matriz2 = new int*[filas];
    for (int i = 0; i < filas; i++) {
        matriz1[i] = new int[columnas];
        matriz2[i] = new int[columnas];
    }

    // Leer los elementos de las matrices
    std::cout << "Ingrese los elementos de la primera matriz:" << std::endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cin >> matriz1[i][j];
        }
    }

    std::cout << "Ingrese los elementos de la segunda matriz:" << std::endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cin >> matriz2[i][j];
        }
    }

    // Sumar las matrices de forma recursiva
    int** matrizSuma = sumarMatricesRecursivo(matriz1, matriz2, filas, columnas);

    // Imprimir la matriz resultante
    std::cout << "Matriz resultante:" << std::endl;
    imprimirMatriz(matrizSuma, filas, columnas);

    // Liberar la memoria de las matrices
    for (int i = 0; i < filas; i++) {
        delete[] matriz1[i];
        delete[] matriz2[i];
        delete[] matrizSuma[i];
    }
    delete[] matriz1;
    delete[] matriz2;
    delete[] matrizSuma;

    return 0;
}
