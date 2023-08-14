#pragma once
#include "Nodo.cpp"

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
	
	void setPrimero(Nodo<T>* _primero);
	
	Nodo<T>* getActual();
	
	void setActual(Nodo<T>* _actual);
	
	int getIngresos();
	
	void setIngresos(int _ingresos);
	
	void Push(T valor);
	
	void Pop();
	
	void mostrarPila();
	
	void mostrarNotacion();

	void mostrarIngreso();
};

