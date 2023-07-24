/**
 * @file OperacionArboles.h
 * @author Alejandro Andrade - Alex Trejo
 * @brief 
 * @version 1.0
 * @date 2023-07-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef OPERACIONARBOLES_H
#define OPERACIONARBOLES_H
#include <string>

#include "NodoArbol.cpp"

template <typename T>
class OperacionArboles{
	public:
		virtual void insertarNodo(T)=0;
	    virtual NodoArbol<T>* buscarNodo(T)=0;
	    virtual void eliminarNodo(T)=0;
	    virtual void mostrarArbol()=0;
	    virtual void mostrarRepetidos(T)=0;
};
#endif