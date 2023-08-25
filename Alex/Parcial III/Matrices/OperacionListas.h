#pragma once

template <typename T>
class OperacionListas{
	public:
		virtual bool estaVacia()=0;
		virtual void insertar(T)=0;
		virtual bool eliminar(T)=0;
		virtual bool buscar(T)=0;
		virtual void mostrar()=0;
		virtual T extraerDato(T dato)=0;
		virtual NodoDoble<T>* extraerNodo(T)=0;
		//virtual void ordenarPorIntercambio(int)=0;
		virtual void mostrarRepetidos(T) = 0;
};
