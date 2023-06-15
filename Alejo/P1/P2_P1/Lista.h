
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

	void alterarValores() {
        if (primero == nullptr || primero->siguiente == nullptr) {
            return;
        }

        Nodo* actual = primero;
        Nodo* siguienteNodo = primero->siguiente;

        while (actual != nullptr && siguienteNodo != nullptr) {
            swap(actual->valor, siguienteNodo->valor);
            actual = siguienteNodo->siguiente;
            if (actual != nullptr) {
                siguienteNodo = actual->siguiente;
            }
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