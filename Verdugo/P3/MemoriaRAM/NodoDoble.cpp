#include "NodoDoble.h"

template <typename T>
NodoDoble<T>::NodoDoble(T dato){
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}


template <typename T>
NodoDoble<T>::~NodoDoble(){
}

template <typename T>
void NodoDoble<T>::setDato(T dato){
	this->dato = dato;
}

template <typename T>
T NodoDoble<T>::getDato(){
	return this->dato;
}

template <typename T>
void NodoDoble<T>::setSiguiente(NodoDoble<T>* siguiente){
	this->siguiente = siguiente;
}

template <typename T>
NodoDoble<T>* NodoDoble<T>::getSiguiente(){
	return this->siguiente;
}

template <typename T>
void NodoDoble<T>::setAnterior(NodoDoble<T>* anterior){
	this->anterior = anterior;
}

template <typename T>
NodoDoble<T>* NodoDoble<T>::getAnterior(){
	return this->anterior;
}