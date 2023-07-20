#ifndef NODOARBOL_H
#define NODOARBOL_H

#include <iostream>
#include <stdio.h>

template <typename T>
class NodoArbol{
	public:
		//Constructor
		NodoArbol(T);
		//Getters
		T getDato();
		NodoArbol<T>*& getDerecho();
		NodoArbol<T>*& getIzquierdo();
		//Setters
		void setDato(T);
		void setDerecho(NodoArbol<T>*);
		void setIzquierdo(NodoArbol<T>*);
	private:
		T dato;
		NodoArbol<T>* derecho;
		NodoArbol<T>* izquierdo;
};
#endif