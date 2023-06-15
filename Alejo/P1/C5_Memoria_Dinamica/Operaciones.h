/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
          Allan Panchi
          Sebastian Verdugo
          Alejandro Andrade
Fecha de inicio: 20/05/2023
Fecha de modificación: 21/05/2023

Memoria Dinamica: Operaciones con matrices
*/

#pragma once
#include "Matriz.h"
class Operaciones{
	public:
		Operaciones();
		Operaciones(Matriz);
		void segmentar();
		void encerar();
		void generar();
		void procesarPot(int);
		void procesarMulti();
		void imprimir();
	private:
		Matriz _matriz;
};