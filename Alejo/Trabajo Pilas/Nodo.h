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
	T getDato();
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
T Nodo<T>::getDato()
{
	return this->dato;
}

template <typename T>
Nodo<T>* Nodo<T>::getSiguiente()
{
	return this->siguiente;
}



