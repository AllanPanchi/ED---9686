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

#ifndef OPERACIONES_H
#define OPERACIONES_H
#include "Matriz.h"

template <typename T> 
class Operaciones{
	private:
		
		Matriz<T> m_matriz;

	public:
		Operaciones();
		Operaciones(Matriz<T>&);
		void segmentar();
		void encerar();
		void generar();
		void procesarPot(T exponente, T **matriz);
		void procesarMulti(Matriz<T>& matriz1, Matriz<T>& matriz1_2);
		void imprimir();
	
};


#include "Operaciones.cpp"

#endif