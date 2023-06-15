
#include "Nodo.h"
#include <iostream>
using namespace std;
class Lista{
	private:
		Nodo *primero;
		Nodo *actual;
	public:

	Nodo* getPrimero(){
		return this->primero;
	}

	Nodo* getActual(){
		return this->actual;
	}

	void setPrimero(Nodo *primero){
		this->primero=primero;
	}

	void setActual(Nodo *actual){
		this->actual=actual;
	}

	int size(){
		int cont=0;
		Nodo *tmp=this->primero;
		while(tmp){
			cont++;
			tmp=tmp->siguiente;
		}
		return cont;
	}

	bool listaVacia(){
		return (this->actual==NULL);
	}

	Lista(){
		this->primero=NULL;
		this->actual=NULL;
	}

	void insertarPorCabeza(int val){
		Nodo *nuevo=new Nodo(val);
		if (listaVacia()){
			this->primero=nuevo;
		}
		else{
			this->actual->siguiente=nuevo;
		}
		this->actual=nuevo;
	}

	void insertarPorCola(int val){
		Nodo *nuevo=new Nodo(val);
		if (listaVacia()){
			this->primero=nuevo;
		}
		else{
			nuevo->siguiente=this->primero;
		}
		this->primero=nuevo;
	}

	Nodo* buscar(int valor){
        Nodo *tmp = this->primero;
        while(tmp){
            if(tmp->getValor() == valor){
                return tmp;
            }
            tmp = tmp->getSiguiente();
        }
        return NULL;
    }

	// funcion para eliminar un elemento de una lista
	void eliminar(int valor){
		Nodo *tmp = this->primero;
		Nodo *ant = NULL;
		while(tmp){
			if(tmp->getValor() == valor){
				if(ant == NULL){
					this->primero = tmp->getSiguiente();
				}else{
					ant->setSiguiente(tmp->getSiguiente());
				}
				delete tmp;
				return;
			}
			ant = tmp;
			tmp = tmp->getSiguiente();
		}
	}

	void mostrarLista(){
		Nodo *tmp=this->primero;
		while(tmp){
			cout<<tmp->valor<<"-->";
			tmp=tmp->siguiente;
		}
		cout << "NULL" << std::endl;
	}
};