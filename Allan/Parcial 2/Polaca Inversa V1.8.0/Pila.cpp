#include "Pila.h"
#include <iostream>

template <typename T>
Pila<T>::Pila():primero(nullptr),actual(nullptr),ingresos(0) {}

//Funcion para saber si la Pila está vacía
template <typename T>
bool Pila<T>::PilaVacia() {
	return primero == nullptr && ingresos == 0;
}

//Setters y getters
template <typename T>
Nodo<T>* Pila<T>::getPrimero() {
	return this->primero;
}

template <typename T>
void Pila<T>::setPrimero(Nodo<T>* primero) {
	this->primero = primero;
}

template <typename T>
Nodo<T>* Pila<T>::getActual() {
	return this->actual;
}

template <typename T>
void Pila<T>::setActual(Nodo<T>* actual) {
	this->actual = actual;
}

template <typename T>
int Pila<T>::getIngresos() {
	return this->ingresos;
}

template <typename T>
void Pila<T>::setIngresos(int ingresos) {
	this->ingresos = ingresos;
}

//Ingresar datos a la Pila
template <typename T>
void Pila<T>::Push(T valor) {
	Nodo<T>* nuevo = new Nodo<T>(valor);
	if (PilaVacia()) {
		this->actual = nuevo;
	} else {
		nuevo->setSiguiente(this->primero);
	}
	this->primero = nuevo;
}

//Eliminar datos a Pila
template <typename T>
void Pila<T>::Pop() {
	if (!PilaVacia()) {
		Nodo<T>* temp;
		temp = this->primero;
		this->primero = this->primero->getSiguiente();
		free(temp); // aquí funciona el free porque no estamos utilizando el new
	}
}

//Mostrar datos a Pila
template <typename T>
void Pila<T>::mostrarPila() {
	Nodo<T>* tmp = this->primero;
	while (tmp) {
		std::cout << tmp->getValor() << " --> ";
		tmp = tmp->getSiguiente();
	}
	std::cout << "NULL\n";
}

//Mostrar expresion algebraica
template <typename T>
void Pila<T>::mostrarNotacion() {
	Nodo<T>* tmp = this->primero;
	while (tmp) {
		std::cout << tmp->getValor()<< " ";
		tmp = tmp->getSiguiente();
	}
	std::cout << std::endl;
}


//Mostrar expresion algebraica invertida
template <typename T>
void Pila<T>::mostrarIngreso() {
	Pila<T> copia;
	Nodo<T>* tmp = this->primero;

	while (tmp) { //ES UNA FORMA DE ESCRIBIR while(tmp==nullptr), mientras sea diferente de nulo, será verdadero.
		copia.Push(tmp->getValor());
		tmp = tmp->getSiguiente();
	}
	tmp = copia.getPrimero();
	while (tmp) {
		std::cout << tmp->getValor();//se borra: <<" "
		tmp = tmp->getSiguiente();
	}
	std::cout << std::endl;
}
