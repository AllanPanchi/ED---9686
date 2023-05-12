/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
			 Allan Panchi
			 Sebastian Verdugo
			 Alejandro Andrade
Fecha de inicio: 04/05/2023
Fecha de modificación: 11/05/2023

Imprementar la interface en una clase y llamar a esta clase en el main
*/

#include <iostream>
#include "Fraccion.cpp"
#include "IOperaciones.cpp"

int main(int argc, char const *argv[])
{
	Fraccion fraccion;
	Fraccion obj1(2, 0);
	Fraccion obj2(6, 3);
	fraccion = fraccion.proceso(obj1, obj2);
	fraccion.toString();

	obj1.toString();
	obj2.toString();

	
	IOperaciones* op = new Operaciones();

	float a = 2.3;
	std::cout << "Operacion con parametros float y TDA ->\n";
	op->operacion(a, obj1);
	std::cout << "float + numerador de fraccion de obj1 -> " << a << std::endl;

	std::cout << "Operacion con parametros TDA\n";
	std::cout << "Numerador 1 * Numerador 2 -> " << op->operacion(obj1, obj2) << std::endl;

	std::cout << "Operacion con parametros float\n";
	std::cout << "Numerador de fraccion = flotante1*flotante2 y Denominador = flotante1-flotante2 -> ";
	op->operacion(4.1, 2.3).toString();

	system("pause");

	return 0;
}