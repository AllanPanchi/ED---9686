/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Alex Trejo 
                
Fecha de inicio: 30/06/2023
Fecha de modificación: 16/07/2023

Proyecto sobre Calculadora polaca infija, posfija y prefija
*/
#include "Nodo.h"

template <typename T>
Nodo<T>::Nodo(T dato)
{
    this->dato = dato;
    this->siguiente = nullptr;
}

template <typename T>
Nodo<T>::Nodo(T dato, Nodo<T>* siguiente)
{
    this->dato = dato;
    this->siguiente = siguiente;
}

template <typename T>
T Nodo<T>::getDato()
{
    return this->dato;
}

template <typename T>
Nodo<T>* Nodo<T>::getSiguiente()
{
    return this->siguiente;
}

template <typename T>
void Nodo<T>::setDato(T dato)
{
    this->dato = dato;
}

template <typename T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente)
{
    this->siguiente = siguiente;
}