/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
			 Allan Panchi
			 Sebastian Verdugo
			 Alejandro Andrade
Fecha de inicio: 19/05/2023
Fecha de modificación: 22/05/2023

Memoria Dinamica en una matriz, uso de punteros y templates  
*/


#pragma once
#include <iostream>

template <class T>
class Matriz{
	private:
		T** matriz;
		int dim;
	public:
		Matriz();
		Matriz(T** ,int);
		int getDim();
		void setDim(int);
		T **getMatriz();
		void setMatriz(T** );
};