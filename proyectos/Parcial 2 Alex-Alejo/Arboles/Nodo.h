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

/**
 * @file Nodo.h
 * @author Alejandro Andrade - Alex Trejo
 * @version 1.0
 * @date 15/06/2023
 * @title Nodo
 * @brief Clase Nodo
 */


#include "Registro.cpp"

template <typename T>
class Nodo{
	private:
		T valor;
        Nodo<T> *anterior;
		Nodo<T> *siguiente;
	public:
    
		Nodo(T registro, Nodo<T> *sig=NULL, Nodo<T> *ant=NULL);

        void setValor(T registro);

		T getValor();

        void setSiguiente(Nodo<T> *sig);

		Nodo<T>* getSiguiente();

        void setAnterior(Nodo<T> *ant);

        Nodo<T>* getAnterior();
};