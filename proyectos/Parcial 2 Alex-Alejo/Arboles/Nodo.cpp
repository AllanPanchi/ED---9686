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

// Constructor de la clase Nodo
/**
 * @brief Construct a new Nodo< T>:: Nodo object
 * 
 * @tparam T 
 * @param registro 
 * @param sig 
 * @param ant 
 */
template <typename T>
Nodo<T>::Nodo(T registro, Nodo<T> *sig, Nodo<T> *ant){
    this->valor = registro;
    this->siguiente = sig;
    this->anterior = ant;
}

// Sett de valor
/**
 * @brief Set the Valor object
 * 
 * @tparam T 
 * @param registro 
 */
template <typename T>
void Nodo<T>::setValor(T registro){
	this->valor = registro;
}

// Get de valor
/**
 * @brief Get the Valor object
 * 
 * @tparam T 
 * @return T 
 */
template <typename T>
T Nodo<T>::getValor(){
	return this->valor;
}

// Sett de siguiente
/**
 * @brief Set the Siguiente object
 * 
 * @tparam T 
 * @param sig 
 */
template <typename T>
void Nodo<T>::setSiguiente(Nodo<T> *sig){
	this->siguiente=sig;
}

// Get de siguiente
/**
 * @brief Get the Siguiente object
 * 
 * @tparam T 
 * @return Nodo<T>* 
 */
template <typename T>
Nodo<T>* Nodo<T>::getSiguiente(){
	return this->siguiente;
}

// Sett de anterior
/**
 * @brief Set the Anterior object
 * 
 * @tparam T 
 * @param ant 
 */
template <typename T>
void Nodo<T>::setAnterior(Nodo<T> *ant){
    this->anterior=ant;
}

// Get de anterior
/**
 * @brief Get the Anterior object
 * 
 * @tparam T 
 * @return Nodo<T>* 
 */
template <typename T>
Nodo<T>* Nodo<T>::getAnterior(){
    return this->anterior;
}