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

Rcursividad: Operaciones con matrices
*/

#pragma once
#include <iostream>
class Matriz{
	private:
		int **matriz;
		int dim;
	public:
		Matriz();
		Matriz(int** ,int);
		int getDim();
		void setDim(int);
		int **getMatriz();
		void setMatriz(int **);
};