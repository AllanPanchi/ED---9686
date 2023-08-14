#include "Nodo.h"
template <typename T>
Nodo<T>::Nodo() {
	this->valor;
	this->siguiente = nullptr;
}

template <typename T>
Nodo<T>::Nodo(T valor) {
	this->valor = valor;
	this->siguiente = nullptr;
}

template <typename T>
Nodo<T>::~Nodo() {
	delete siguiente;
}

template <typename T>
T Nodo<T>::getValor() {
	return valor;
}

template <typename T>
void Nodo<T>::setValor(T valor) {
	this->valor = valor;
}

template <typename T>
Nodo<T>* Nodo<T>::getSiguiente() {
	return this->siguiente;
}

template <typename T>
void Nodo<T>::setSiguiente(Nodo* siguiente) {
	this->siguiente = siguiente;
}
