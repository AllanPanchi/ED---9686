/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
          Allan Panchi
          Sebastian Verdugo
          Alejandro Andrade
Fecha de inicio: 20/05/2023
Fecha de modificación: 21/05/2023

Recursividad: Operaciones con matrices
*/

#include "Operaciones.cpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 3

using namespace std;

int main(int argc, char** argv) {
	int** mat1 = nullptr;
	int** mat2 = nullptr;
	int** matR = nullptr;

	mat1 = (int**)malloc(3 * sizeof(int*));
	mat2 = (int**)malloc(3 * sizeof(int*));
	matR = (int**)malloc(3 * sizeof(int*));
	for (int j = 0; j < 3; j++) {
		*(mat1 + j) = (int*)malloc(3 * sizeof(int*));
		*(mat2 + j) = (int*)malloc(3 * sizeof(int*));
		*(matR + j) = (int*)malloc(3 * sizeof(int*));
	}

	srand(time(NULL));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			*(*(mat1 + i) + j) = (int)((rand() % 10));
			*(*(mat2 + i) + j) = (int)((rand() % 10));
			*(*(matR + i) + j) = 0;
		}
	}

	cout << "\nLa matriz 1 es:\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d", *(*(mat1 + i) + j));
			printf("%*s", j + 5, "");
		}
		cout << "\n";
	}
	cout << "\n";

	cout << "\nLa matriz 2 es:\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d", *(*(mat2 + i) + j));
			printf("%*s", j + 5, "");
		}
		cout << "\n";
	}

	cout << "\nSuma de Matrices es: ";
	
	Operaciones::cifrarMatriz(mat1, mat2, matR, 2, 2);

	cout << "\nLa matriz R es:\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d", *(*(matR + i) + j));
			printf("%*s", j + 5, "");
		}
		cout << "\n";
	}

	cout << "\nMultiplicacion de Matrices es: ";
	
	Operaciones::multiplicacionDeMatrices(mat1, mat2, matR, 2, 2);

	cout << "\nLa matriz R es:\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d", *(*(matR + i) + j));
			printf("%*s", j + 5, "");
		}
		cout << "\n";
	}

	return 0;
}