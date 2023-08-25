#pragma once
#include "NodoDoble.h"
#include "OperacionListas.h"
template <typename T>
class ListaCircularDoble:public OperacionListas<T>{
	public:
		//Contructor y destructor
		ListaCircularDoble();
		~ListaCircularDoble();
		//Getters y Setters
		NodoDoble<T>* getCabeza();
		NodoDoble<T>* getCola();
		void setCabeza(NodoDoble<T>*);
		void setCola(NodoDoble<T>*);
		//Operaciones
		bool estaVacia()override;
		void insertar(T)override ;
		bool eliminar(T)override;
		bool buscar(T)override;
		void mostrar()override;
		void mostrarRepetidos(T) override;
		T extraerDato(T)override;
		NodoDoble<T>* extraerNodo(T)override;
		//void ordenarPorIntercambio(int)override;
	private:
		NodoDoble<T>* cabeza;
		NodoDoble<T>* cola;
};                        

	

