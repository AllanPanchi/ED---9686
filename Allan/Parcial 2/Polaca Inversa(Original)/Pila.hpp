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
#include "Nodo.hpp"

using namespace std;

template <typename T>

class Pila {
private:
	Nodo<T>* primero;
	Nodo<T>* actual;
	int ingresos;

public:
	
	//Constructor
	Pila() {
		this->primero = nullptr;
		this->actual = nullptr;
		this->ingresos = 0;
	}

	//Pila Vacia
	bool PilaVacia() {
		return (this->primero == nullptr && ingresos == 0);
	}

	//Metodos Get - Set
	Nodo<T>* getPrimero() {
		return this->primero;
	}

	void setPrimero(Nodo<T>* _primero) {
		primero = _primero;
	}

	Nodo<T>* getActual() {
		return this->actual;
	}

	void setActual(Nodo<T>* _actual) {
		actual = _actual;
	}

	int getIngresos() {
		return this->ingresos;
	}

	void setIngresos(int _ingresos) {
		ingresos = _ingresos;
	}

	//Ingresar datos a Pila
	void Push(T valor) {
		Nodo<T>* nuevo = new Nodo<T>(valor);

		if (PilaVacia()) {
			this->actual = nuevo;
		}
		else {
			nuevo->setSiguiente(this->primero);
		}
		this->primero = nuevo;
	}

	//Eliminar datos a Pila
	void Pop() {
		if (!PilaVacia()) {
			Nodo<T>* temp;
			temp = this->primero;
			this->primero = this->primero->getSiguiente();
			free(temp);
		}
	}

	//Mostrar datos a Pila
	void mostrarPila() {
		Nodo<T>* tmp = this->primero;
		while (tmp) {
			cout << tmp->getValor() << "-->";
			tmp = tmp->getSiguiente();
		}
		cout << "NULL\n";
	}

	//Mostrar expresion algebraica
	void mostrarNotacion(){
		Nodo<T>* tmp = this->primero;
		while (tmp) {
			cout << tmp->getValor() << " ";
			tmp = tmp->getSiguiente();

		}
		cout << endl;
	}


	//Mostrar expresion algebraica invertida
	void mostrarIngreso(){
		Pila<T> copia;
		Nodo<T>* tmp = this->primero;

		while (tmp) {
			copia.Push(tmp->getValor());
			tmp = tmp->getSiguiente();
		}
		tmp = copia.getPrimero();
		while (tmp) {
			cout << tmp->getValor() << " ";
			tmp = tmp->getSiguiente();
		}
		cout << endl;
	}

};

