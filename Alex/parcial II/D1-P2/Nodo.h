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

#include "Producto.h"

template <typename T>
class Nodo{
	private:
		T producto;
        Nodo<T> *anterior;
		Nodo<T> *siguiente;
	public:
    
		Nodo(T product, Nodo<T> *sig=NULL, Nodo<T> *ant=NULL);

        void setProducto(T product);

		T getProducto();

        void setSiguiente(Nodo<T> *sig);

		Nodo<T>* getSiguiente();

        void setAnterior(Nodo<T> *ant);

        Nodo<T>* getAnterior();
		
	    friend class ListaProducto;
};