/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Allan Panchi
                Alex Trejo 
                Sebastian Verdugo
Fecha de inicio: 09/05/2023
Fecha de modificación: 09/06/2023

Proyecto sobre registros utlizando listas doblemente enlazadas
*/
#pragma once

template <typename T>
class Nodo
{
private:
	T dato;
	Nodo<T>* siguiente;
public:
	Nodo(T dato);
	~Nodo();
	void setDato(T dato);
	void setSiguiente(Nodo<T>* siguiente);
	T getValor();
	Nodo<T>* getSiguiente();
};

//constructor
template <typename T>
Nodo<T>::Nodo(T dato)
{
	this->dato = dato;
	this->siguiente = nullptr;
}

template <typename T>
Nodo<T>::~Nodo()
{
}

//seters
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

//geters
template <typename T>
T Nodo<T>::getValor()
{
	return this->dato;
}

template <typename T>
Nodo<T>* Nodo<T>::getSiguiente()
{
	return this->siguiente;
}



