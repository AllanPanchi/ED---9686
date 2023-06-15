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

#include "Pila.h"
#include <iostream>

using namespace std;

//constructor y destructor
Pila::Pila()
{
	tope = NULL;
}

Pila::~Pila()
{
	while (!isEmpty())
	{
		pop();
	}
}

//metodos
void Pila::push(int dato)
{
	Nodo<int>* nuevo = new Nodo<int>(dato);
	nuevo->setSiguiente(tope);
	tope = nuevo;
}

int Pila::pop()
{
	if (!isEmpty())
	{
		int dato = tope->getDato();
		Nodo<int>* aux = tope;
		tope = tope->getSiguiente();
		delete aux;
		return dato;
	}
	else
	{
		return -1;
	}
}

int Pila::peek()
{
	if (!isEmpty())
	{
		return tope->getDato();
	}
	else
	{
		return -1;
	}
}

bool Pila::isEmpty()
{
	return tope == NULL;
}


