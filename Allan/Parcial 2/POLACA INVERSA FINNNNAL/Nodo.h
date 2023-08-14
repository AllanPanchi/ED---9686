#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
	private:
		T dato;
		Nodo<T>* siguiente;
	public:
		Nodo(T dato);
		void setDato(T dato);
		T getDato();
		void setSiguiente(Nodo<T>* sig);
		Nodo<T>* getSiguiente();

};

#endif