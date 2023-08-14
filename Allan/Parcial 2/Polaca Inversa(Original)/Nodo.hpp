/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
		INGENIERA DE SOFTWARE
                
	AUTORES:
		-Luis Burbano
        -Mateo Condor
        -Camila Morales
        -Ricardo Rivadeneira
        -Steven Pozo
        -Jairo Quilumbaquin
        -Edwin Cantuña

	FECHA DE CREACION:
		26/12/2022       	
	FECHA DE MODIFICACION:
		05/01/2023
*/

#pragma once
#include <iostream>

using namespace std;

template <typename T>

class Nodo {

private:
    T valor;
    Nodo* siguiente;

public:
    //Constructores
    Nodo() {
        this->valor;
        this->siguiente = nullptr;
    }

    Nodo(T _valor, Nodo* _siguiente = nullptr) {
        this->valor = _valor;
        this->siguiente = _siguiente;
    }

    //Destructor
    ~Nodo() {
        free(siguiente);
    }

    //Metodos Get - Set
    T getValor() {
        return valor;
    }

    void setValor(T _valor) {
        valor = _valor;
    }

    Nodo<T>* getSiguiente() {
        return this->siguiente;
    }

    void setSiguiente(Nodo* _siguiente) {
        siguiente = _siguiente;
    }

};