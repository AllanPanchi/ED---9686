/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Sebastian Verdugo
             Alex Trejo
			 Allan Panchi
			 Alejandro Andrade
Fecha de inicio: 04/05/2023
Fecha de modificación: 09/05/2023

Crear 4 operaciones en una interface que incluyan datos abstractos
*/

#include <iostream>
#include "Fraccion.cpp"
#include "IOperaciones.cpp"

int main(int argc, char const *argv[])
{
	Fraccion fraccion;
	Fraccion obj1(2, 1);
	Fraccion obj2(6, 3);
	fraccion = fraccion.proceso(obj1, obj2);
	fraccion.toString();

	obj1.toString();
	obj2.toString();

	IOperaciones* op = new Operaciones();

	std::cout << "Operacion 1: "<< op->operacion1(obj1, obj2);
	std::cout << "\nOperacion 2: ";
	op->operacion2(obj1, obj2).toString();
	std::cout << "Operacion 3: ";
	op->operacion3(-3.9, 3.9).toString();
	std::cout << "Operacion 4: "<< op->operacion4(2.3, 4.1);

	return 0;
}
