#pragma once
#include <iostream>

template <typename T>
class Nodo{
	private:
		T valor;
		Nodo* siguiente;
	
	public:
		Nodo();
		Nodo(T);
		~Nodo();
		T getValor();
		void setValor(T valor);
		Nodo<T>* getSiguiente();
		void setSiguiente(Nodo* siguiente);
		
};