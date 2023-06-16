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
Nodo<T>::Nodo(T registro, Nodo<T> *sig, Nodo<T> *ant){
    this->registro = registro;
    this->siguiente = sig;
    this->anterior = ant;
}

template <typename T>
void Nodo<T>::setRegistro(T registro){
	this->producto = registro;
}

template <typename T>
T Nodo<T>::getRegistro(){
	return this->registro;
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