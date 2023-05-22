/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
			 Allan Panchi
			 Sebastian Verdugo
			 Alejandro Andrade
Fecha de inicio: 19/05/2023
Fecha de modificación: 22/05/2023

Memoria Dinamica en una matriz, uso de punteros y templates  
*/

#include <iostream>
#include "Matriz.h"

template <class T>
Matriz<T>::Matriz(){
}

template <class T>
Matriz<T>::Matriz(T** matriz, int dim ){
	this->matriz=matriz;
	this->dim=dim;
}

template <class T>
int Matriz<T>::getDim(){
	return dim;
}

template <class T>
void Matriz<T>::setDim(int dim){
	this->dim=dim;
}



template <class T>
T** Matriz<T>::getMatriz(){
	return matriz;
}



template <class T>
void Matriz<T>::setMatriz(T** matriz1){
	this-> matriz = matriz1;

}

template class Matriz<int>;
template class Matriz<float>;
template class Matriz<double>;