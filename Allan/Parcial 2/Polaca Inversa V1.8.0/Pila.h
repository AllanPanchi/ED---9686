#pragma once
#include "Nodo.h"

template <typename T>
class Pila {
	private:
		Nodo<T>* primero;
		Nodo<T>* actual;
		int ingresos;
	public:
		Pila();
		bool PilaVacia();
		Nodo<T>* getPrimero();
		void setPrimero(Nodo<T>* primero);
		Nodo<T>* getActual();
		void setActual(Nodo<T>* actual);
		int getIngresos();
		void setIngresos(int ingresos);
		void Push(T valor);
		void Pop();
		void mostrarPila();
		void mostrarNotacion();
		void mostrarIngreso();

};