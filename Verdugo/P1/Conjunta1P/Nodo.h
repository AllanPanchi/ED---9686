#pragma once
#include "Producto.h"

class Nodo{
	private:
		Producto producto;
        Nodo *anterior;
		Nodo *siguiente;
	public:
    
		Nodo(Producto product, Nodo *sig=NULL, Nodo *ant=NULL);

        void setProducto(Producto product);

		Producto getProducto();

        void setSiguiente(Nodo *sig);

		Nodo* getSiguiente();

        void setAnterior(Nodo *ant);

        Nodo* getAnterior();
		
	    friend class ListaProducto;
};