/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Estudiante: Sebastian Verdugo
Fecha de inicio: 20/05/2023
Fecha de modificación: 22/05/2023

Suma de filas de matrices recursiva
*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

// Función recursiva para sumar los dígitos de un número
int sumarDigitos(int num) {
  if (num < 10) {
    return num;
  }
  return sumarDigitos(num % 10 + num / 10);
}

// Función recursiva para sumar los elementos de una fila
int sumarFila(int matriz[ROWS][COLS], int fila, int columna = 0, int suma = 0) {
  if (columna == COLS) {
    // Verificar si la suma es un número de dos cifras
    if (suma > 9) {
      return sumarDigitos(suma);
    }
    return suma;
  }

  return sumarFila(matriz, fila, columna + 1, suma + matriz[fila][columna]);
}

// Función recursiva para sumar todas las filas de la matriz
int sumarFilas(int matriz[ROWS][COLS], int fila = 0, int sumaTotal = 0) {
  if (fila == ROWS) {
    // Verificar si la suma total es un número de dos cifras
    if (sumaTotal > 9) {
      return sumarDigitos(sumaTotal);
    }
    return sumaTotal;
  }

  int sumaFila = sumarFila(matriz, fila);
  std::cout << "La suma de la fila " << fila + 1 << " es: " << sumaFila << std::endl;
  return sumarFilas(matriz, fila + 1, sumaTotal + sumaFila);
}

int main() {
  int matriz[ROWS][COLS] = {
    {2, 3, 4},
    {5, 6, 7},
    {8, 9, 1}
  };

  // Mostrar la matriz generada
  std::cout << "Matriz generada:\n";
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      std::cout << matriz[i][j] << " ";
    }
    std::cout << std::endl;
  }

  // Calcular la suma de las filas y mostrar la suma de cada fila
  int sumaTotal = sumarFilas(matriz);

  // Mostrar el resultado
  std::cout << "La suma total de las filas es: " << sumaTotal << std::endl;

  return 0;
}
