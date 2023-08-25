#pragma once
template <typename>
class NodoSimple;

template <typename T>
class ListaSimple {
	public:
		//Constructor
	    ListaSimple();
		//Funciones
	    void insertarAlFinal(const T& valor);
	    NodoSimple<T>* obtenerNodoPorPosicion(int posicion);
	    int obtenerElementoEnPosicion(int posicion);
	    void mostrar(); // Declaración del método mostrar
	    bool estaVacia();
	    int obtenerTamanio() const;
	    void vaciar();
	    //Sobrecarca de operadores
	    T& operator[](int posicion);
	
	private:
	    NodoSimple<T>* cabeza;
};

