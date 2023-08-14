#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H

#include "NodoDoble.h"
#include "OperacionesListaCircularDoble.h"

template <typename T>
class ListaCircularDoble{
	private:
		NodoDoble<T>* cabeza;
		NodoDoble<T>* cola;

	public:
		ListaCircularDoble();
		~ListaCircularDoble();

		NodoDoble<T>* getCabeza();
		NodoDoble<T>* getCola();
		void setCabeza(NodoDoble<T>*);
		void setCola(NodoDoble<T>*);

		bool esListaVacia();
		void insertar(T);
		void eliminar(T);
		bool buscar(T);
		void mostrarRepetidos(T);
		T extraer(T);
		NodoDoble<T>* extraerNodo(T);
		void imprimir();
		void ordenarPorIntercambio(int);



	protected:
};

#endif