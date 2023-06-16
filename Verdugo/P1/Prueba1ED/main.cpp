/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Estudiante: Sebastian Verdugo
Fecha de inicio: 20/05/2023
Fecha de modificaci�n: 22/05/2023

Suma de filas de matrices recursiva
*/
#include <iostream>
#include <cstdlib>  // Para la funci�n rand()
#include <ctime>    // Para la funci�n time()

using namespace std;

// Funci�n recursiva para sumar los d�gitos de un n�mero
int sumarDigitos(int num) {
  if (num < 10) {
    return num;
  }
  return sumarDigitos(num % 10 + num / 10);
}

// Funci�n recursiva para sumar los elementos de una fila
int sumarFila(int matriz[][3], int fila, int columna = 0, int suma = 0) {
  if (columna == 3) {
    // Verificar si la suma es un n�mero de dos cifras
    if (suma > 9) {
      return sumarDigitos(suma);
    }
    return suma;
  }

  return sumarFila(matriz, fila, columna + 1, suma + matriz[fila][columna]);
}

// Funci�n recursiva para sumar todas las filas de la matriz
int sumarFilas(int matriz[][3], int fila = 0, int sumaTotal = 0) {
  if (fila == 3) {
    // Verificar si la suma total es un n�mero de dos cifras
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
  int dimension;

  // Obtener la dimensi�n de la matriz
  std::cout << "Ingrese la dimensi�n de la matriz: ";
  std::cin >> dimension;

  // Verificar si la dimensi�n es v�lida
  if (dimension <= 0) {
    std::cout << "La dimensi�n debe ser un n�mero entero positivo." << std::endl;
    return 1;
  }

  // Generar la matriz cuadrada aleatoriamente
  int matriz[dimension][dimension];

  // Semilla para generar n�meros aleatorios
  srand(time(0));

  // Llenar la matriz con n�meros aleatorios entre 10 y 99
  for (int i = 0; i < dimension; i++) {
    for (int j = 0; j < dimension; j++) {
      matriz[i][j] = rand() % 90 + 10;
    }
  }

  // Mostrar la matriz generada
  std::cout << "Matriz generada:\n";
  for (int i = 0; i < dimension; i++) {
    for (int j = 0; j < dimension; j++) {
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
