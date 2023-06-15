#pragma once
class Nodo{
	public:
		int valor;
		Nodo* siguiente;

		Nodo(int val , Nodo* sig=NULL){
			valor=val;
			siguiente=sig;
		}
	friend class Lista;
};
