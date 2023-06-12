// #pragma once
// #include "Pila.h"
// #include <iostream>

// using namespace std;

// //constructor y destructor
// template <typename T>
// Pila<T>::Pila() : tope(nullptr){}

// template<typename T>
// Pila<T>::~Pila()
// {
// 	while (!isEmpty())
// 		pop();
// }

// template<typename T>
// void Pila<T>::push(T dato)
// {
// 	Nodo<T>* nuevoNodo = new Nodo<T>(dato);
// 	nuevoNodo->setSiguiente(tope);
// 	tope = nuevoNodo;
// }

// template<typename T>
// T Pila<T>::pop()
// {
// 	if (isEmpty())
// 		throw "La pila está vacía.";

// 	T dato = tope->getDato();
// 	Nodo<T>* nodoAEliminar = tope;
// 	tope = tope->getSiguiente();
// 	delete nodoAEliminar;

// 	return dato;
// }

// template <typename T>
// T Pila<T>::peek(){

// 	if (isEmpty()) {
//         throw "La pila está vacía";
//     }

//     return tope->getDato();	
// }


// template<typename T>
// bool Pila<T>::isEmpty() 
// {

// 	return tope ==nullptr;
// }