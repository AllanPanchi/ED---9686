#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Producto.cpp"

template <typename T>
class Nodo{
	private:
		T valor;
        Nodo<T> *anterior;
		Nodo<T> *siguiente;
	public:
    
		Nodo(T valor, Nodo<T> *sig=NULL, Nodo<T> *ant=NULL);

        void setValor(T valor);

		T getValor();

        void setSiguiente(Nodo<T> *sig);

		Nodo<T>* getSiguiente();

        void setAnterior(Nodo<T> *ant);

        Nodo<T>* getAnterior();
};