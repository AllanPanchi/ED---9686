/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
			 Allan Panchi
			 Sebastian Verdugo
			 Alejandro Andrade
Fecha de inicio: 04/05/2023
Fecha de modificaci�n: 09/05/2023

Realizar 4 operaciones en una interface que incluyan datos abstractos
*/

#include <iostream>
#include "Fraccion.cpp"
#include "InterfaceOperaciones.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
	Fraccion fraccion;
	Fraccion obj1(2.22, 17.44);
	Fraccion obj2(4.00, 3.44);
	Fraccion obj3(4.87, 7.98);
	fraccion = fraccion.proceso(obj1, obj2);
	fraccion.toString();

	obj1.toString();
	obj2.toString();

	InterfaceOperaciones* op = new Operaciones();

	float flotante_funcion = 3.00F;

	cout << "Operacion con flotante y TDA, no retorna nada: "; 
	op->operacion(flotante_funcion, obj2);
	cout << flotante_funcion << endl;

	cout << "\nOperacion con dos fracciones pero retorna un flotante : "
	<< op->operacion(obj1, obj2) << endl;

	cout << "\nOperacion con 2 flotantes y me retorna una Fraccion: "; 
	op->operacion(-3.9F, 73.9F).toString();

	cout << "\nOpreacion con 3 flotantes y me retorna un flotante : "
	<<op->operacion(2.3, 4.1, flotante_funcion)<< endl;

	system("pause");

	return 0;
	
}
