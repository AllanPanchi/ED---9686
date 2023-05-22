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
	Fraccion obj1(12, 5);
	Fraccion obj2(18, 4);
	fraccion = fraccion.proceso(obj1, obj2);
	fraccion.toString();

	obj1.toString();
	obj2.toString();

	IOperaciones* op = new Operaciones();

	std::cout << "Operacion 1: "<< op->operacion1(obj1, obj2);
	std::cout << "\nOperacion 2: ";
	op->operacion2(obj1, obj2).toString();
	std::cout << "Operacion 3: ";
	op->operacion3(5.1, 2).toString();
	std::cout << "Operacion 4: "<< op->operacion4(1.4, 4);

	return 0;
}
