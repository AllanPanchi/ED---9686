#pragma once
class Nodo{
	private:
		int valor;
		Nodo *siguiente;
	public:
		Nodo(int val, Nodo *sig=NULL){
			this->valor=val;
			this->siguiente=sig;
		}

		int getValor(){
			return this->valor;
		}

		Nodo* getSiguiente(){
			return this->siguiente;
		}
		
	friend class Lista;
};