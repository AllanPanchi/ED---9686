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

/// @brief Constructor por defecto de la clase Nodo
/// @tparam T 
/// @param dato 
template <typename T>
Nodo<T>::Nodo(T dato)
{
    this->dato = dato;
    this->siguiente = nullptr;
}

/// @brief Constructor de la clase Nodo
/// @tparam T 
/// @param dato 
/// @param siguiente 
template <typename T>
Nodo<T>::Nodo(T dato, Nodo<T>* siguiente)
{
    this->dato = dato;
    this->siguiente = siguiente;
}

/// @brief Retorna el dato del nodo
/// @tparam T 
/// @return T
template <typename T>
T Nodo<T>::getDato()
{
    return this->dato;
}

/// @brief Retorna el siguiente nodo
/// @tparam T 
/// @return Nodo<T>*
template <typename T>
Nodo<T>* Nodo<T>::getSiguiente()
{
    return this->siguiente;
}

/// @brief Guarda el dato del nodo
/// @tparam T 
/// @param dato 
template <typename T>
void Nodo<T>::setDato(T dato)
{
    this->dato = dato;
}

/// @brief Guarda el siguiente nodo
/// @tparam T 
/// @param siguiente 
template <typename T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente)
{
    this->siguiente = siguiente;
}