/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Nombre: Alejandro Andrade
Fecha de inicio: 22/05/2023
Fecha de modificación: 22/05/2023

Prueba 1, Cifrado con Recursividad
*/

#include <iostream>
#include "Operaciones.cpp"
#include <stdlib.h>


int main(int argc, char* argv[])
{
    int dim = 4;
    int** _matriz = nullptr;

	_matriz = (int**)malloc(dim * sizeof(int*));
	for (int j = 0; j < dim; j++) {
		*(_matriz + j) = (int*)malloc(dim * sizeof(int*));
	}

    srand(time(NULL));
    for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			*(*(_matriz + i) + j) = (int)((rand() % 10));
		}
	}

    std::cout << "\nLa matriz es:\n";
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			printf("%d", *(*(_matriz + i) + j));
			printf("%*s", j + 5, "");
		}
		std::cout << "\n";
	}

	int cifrado = sumarMatrizRecursivamente(_matriz, 0, 0, 0);
	std::cout << "\nEl cifrado es: " << cifrado << "\n";

    system("pause");
    
    return 0;
}