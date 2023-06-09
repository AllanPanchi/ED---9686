/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Allan Panchi
                Alex Trejo 
                Sebastian Verdugo
Fecha de inicio: 02/05/2023
Fecha de modificación: 08/06/2023

Proyecto sobre registros utlizando listas doblemente enlazadas
*/
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