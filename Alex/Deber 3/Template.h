/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
			 Allan Panchi
			 Sebastian Verdugo
			 Alejandro Andrade
Fecha de inicio: 12/05/2023
Fecha de modificación: 22/05/2023

Templates implementados en C++
*/

#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <iostream>

// Declaración
template <typename T>
class Calculadora {
	private:
		T num1, num2;
	public:
		Calculadora(T n1, T n2);
		void operaciones();
		T suma();
		T resta();
		T producto();
		T division();
};

#endif