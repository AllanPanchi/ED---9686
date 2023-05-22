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

#include <iostream>
#include "Fraccion.h"
#include "IOperaciones.h"

//Definición
template <typename T>
IOperaciones<T>::IOperaciones(T obj1, T obj2) : objeto1(obj1), objeto2(obj2) {};

template <typename T>
T IOperaciones<T>::operacion()
{
	if ((typeid(objeto1) == typeid(Fraccion)) && (typeid(objeto2) == typeid(Fraccion))){
		std::cout << "Fraccion" << std::endl;
	} else if ((typeid(objeto1) == typeid(float)) && (typeid(objeto2) == typeid(float)))	{
		std::cout << "Float" << std::endl;
	} else {
		std::cout << "No se puede realizar la operacion" << std::endl;
	}
	return objeto1;
}