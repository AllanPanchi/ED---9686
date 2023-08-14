/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Allan Panchi
                Alex Trejo 
                Sebastian Verdugo
Fecha de inicio: 15/06/2023
Fecha de modificación: 15/06/2023

Ordenamiento de lista circular doblemente enlazadas
*/
#include "Nodo.h"

template <typename T>
Nodo<T>::Nodo(T valor, Nodo<T> *sig, Nodo<T> *ant){
    this->valor = valor;
    this->siguiente = sig;
    this->anterior = ant;
}

template <typename T>
void Nodo<T>::setValor(T valor){
	this->valor = valor;
}

template <typename T>
T Nodo<T>::getValor(){
	return this->valor;
}

template <typename T>
void Nodo<T>::setSiguiente(Nodo<T> *sig){
	this->siguiente=sig;
}

template <typename T>
Nodo<T>* Nodo<T>::getSiguiente(){
	return this->siguiente;
}

template <typename T>
void Nodo<T>::setAnterior(Nodo<T> *ant){
    this->anterior=ant;
}

template <typename T>
Nodo<T>* Nodo<T>::getAnterior(){
    return this->anterior;
}