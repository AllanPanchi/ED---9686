#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;
class Lista{
	private:
		Nodo* primero;
		Nodo *actual;
	public:
		Lista(){
			primero=NULL;
			this->actual=NULL;
		}

		void insertar(int val){
			Nodo* nuevo = new Nodo(val);
			if (primero == nullptr){
				primero = nuevo;
			}else{
					this->actual = primero;
					while (this->actual->siguiente != nullptr){
						this->actual = this->actual->siguiente;
					}
			}
			this->actual = nuevo;
		}

		void cambiarValoresLista(){
			while(this->actual != nullptr && actual->siguiente != nullptr){
				int temp = this->actual->valor;
				this->actual->valor = this->actual->siguiente->valor;
				this->actual->siguiente->valor = temp;

				this->actual = this->actual->siguiente->siguiente;
			}
		}

		void mostrarLista(){
			Nodo* tmp= primero;
			while(tmp != nullptr){
				cout<<tmp->valor<<"-->";
				tmp=tmp->siguiente;
			}
			cout<<"NULL"<<endl;
		}

		~Lista() {
			Nodo* tmp = primero;
			while (tmp != nullptr) {
				Nodo* siguiente = tmp->siguiente;
				delete tmp;
				tmp = siguiente;
			}
		}
};
