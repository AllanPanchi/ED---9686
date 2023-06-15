#pragma once
#include "Nodo.h"
template <typename T>
class Pila
{
	private:
		Nodo<T>* tope;
	public:
		Pila();
		~Pila();
		void push(T dato);
		T pop();
		T peek();
		bool isEmpty();
		int size();
};

template <typename T>
Pila<T>::Pila() : tope(nullptr){}

template<typename T>
Pila<T>::~Pila()
{
	while (!isEmpty())
		pop();
}

template<typename T>
void Pila<T>::push(T dato)
{
	Nodo<T>* nuevoNodo = new Nodo<T>(dato);
	nuevoNodo->setSiguiente(tope);
	tope = nuevoNodo;
}

template<typename T>
T Pila<T>::pop()
{
	if (isEmpty())
		throw "La pila está vacía.";

	T dato = tope->getDato();
	Nodo<T>* nodoAEliminar = tope;
	tope = tope->getSiguiente();
	delete nodoAEliminar;

	return dato;
}

template <typename T>
T Pila<T>::peek(){

	if (isEmpty()) {
        throw "La pila está vacía";
    }

    return tope->getDato();	
}


template<typename T>
bool Pila<T>::isEmpty() 
{

	return tope ==nullptr;
}

template<typename T>
int Pila<T>::size()
{

	auto contarElementos = [](Pila<T>* pila) {
		int contador = 0;
		Nodo<T>* aux = pila->tope;
		while (aux)
		{
			contador++;
			aux = aux->getSiguiente();
		}
		return contador;
	};

	int contador = contarElementos(this);
	return contador;
}