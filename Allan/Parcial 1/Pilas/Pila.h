/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Allan Panchi
                Alex Trejo 
                Sebastian Verdugo
Fecha de inicio: 09/05/2023
Fecha de modificación: 09/06/2023

Proyecto sobre registros utlizando listas doblemente enlazadas
*/
#pragma once
#include "Nodo.h"
class Pila
{
private:
	Nodo<int>* tope;
public:
	Pila();
	~Pila();
	void push(int dato);
	int pop();
	int peek();
	bool isEmpty();
};

