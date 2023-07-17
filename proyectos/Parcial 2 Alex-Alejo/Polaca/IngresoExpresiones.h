/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Alex Trejo 
                
Fecha de inicio: 30/06/2023
Fecha de modificación: 16/07/2023

Proyecto sobre Calculadora polaca infija, posfija y prefija
*/
#ifndef INGRESOEXPRESIONES_H
#define INGRESOEXPRESIONES_H
#include <string>

class IngresoExpresiones {
	public:
		static std::string ingresoExpresion(void);
		static bool esEspecial(char);
		static bool esOperador(char);
		static bool esParentesis(char);
	protected:
};

#endif