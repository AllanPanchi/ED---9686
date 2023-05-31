#pragma once
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

	void mostrarLista(){
		Nodo *tmp=this->primero;
		while(tmp){
			cout<<tmp->valor<<"-->";
			tmp=tmp->siguiente;
		}
		cout << "NULL" << std::endl;
	}
};