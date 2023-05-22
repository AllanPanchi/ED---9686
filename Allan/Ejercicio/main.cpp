/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Allan Panchi
Fecha de inicio: 22/05/2023
Fecha de modificación: 22/05/2023

Suma de los elementos entre matrices
*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define dimension 5
using namespace std;

int sumarElementosMatriz(int** mat1, int filas, int columnas, int filaActual, int columnaActual)
{
    if(filaActual==filas)
    {
        return 0;
    }
int elemento = mat1[filaActual][columnaActual];
    int Fila = filaActual;
    int Columna = columnaActual + 1;

    if (Columna == columnas)
    {
        Fila++;
        Columna = 0;
    }

    int sumaRestante = sumarElementosMatriz(mat1, filas, columnas, Fila, Columna);
    int sumaTotal = elemento + sumaRestante;

    if (sumaTotal > 9)
    {
        int sumaDigitos = 0;
        while (sumaTotal > 0) {
        sumaDigitos += sumaTotal % 10;
        sumaTotal /= 10;
    }
        return sumaDigitos;
    }

    return sumaTotal;
}

int main(int argc, char** argv) {
	int** mat1 = nullptr;

	mat1 = (int**)malloc(dimension * sizeof(int*));
	for (int j = 0; j < dimension; j++) {
		*(mat1 + j) = (int*)malloc(dimension * sizeof(int*));
	}

	srand(time(NULL));
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			*(*(mat1 + i) + j) = (int)(rand() % 10);
		}
	}

	cout << "\nLa matriz 1 es:\n";
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			printf("%d", *(*(mat1 + i) + j));
			printf("%*s", j + 5, "");
		}
		cout << "\n";
    }
	cout << "\n";

	cout << "La suma de todos los elementos encriptados es: ";
	int resultado = sumarElementosMatriz(mat1, dimension, dimension, 0, 0);
	cout << resultado << endl;

	return 0;
}
