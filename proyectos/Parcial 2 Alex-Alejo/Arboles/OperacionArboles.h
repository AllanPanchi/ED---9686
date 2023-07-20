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