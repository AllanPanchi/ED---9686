#pragma once

template <typename T>
class NodoSimple {
	public:
	    //Constructor
	    NodoSimple(const T& valor) : dato(valor), siguiente(nullptr) {}
		//Getters y Setters
	    T getDato() const { return dato; }
	    T& getDato() {return dato;}
        //const T& getDato() const {return dato;}
	    NodoSimple* getSiguiente() const { return siguiente; }
	    void setDato(const T& nuevoDato) { dato = nuevoDato; }
	    void setSiguiente(NodoSimple* nuevoSiguiente) { siguiente = nuevoSiguiente; }
	private:
		T dato;
	    NodoSimple* siguiente;
		
};


