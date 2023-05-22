/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
			 Allan Panchi
			 Sebastian Verdugo
			 Alejandro Andrade
Fecha de inicio: 12/05/2023
Fecha de modificación: 14/05/2023

Templates implementados en C++
*/

#include <iostream>
#include <stdlib.h>
#include "Fraccion.cpp"
#include "IOperaciones.cpp"
#include "template.cpp"
#include "Imprimir.h"

int main() {

	Fraccion fraccion1(1.2F, 2.5F);
	Fraccion fraccion2(3.4F, 5.6F);

	IOperaciones<Fraccion> operFraccion(fraccion1, fraccion2);
	IOperaciones<float> operFloat(1.2F, 2.5F);

	operFraccion.operacion().toString();
	std::cout << operFloat.operacion() << std::endl;

    system("pause");
}
