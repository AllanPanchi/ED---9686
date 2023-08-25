 
#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
template <typename>
class NodoSimple;

template <typename T>
class ListaSimple {
	public:
		//Constructor
	    ListaSimple();
	    //Getters
	    NodoSimple<T>* getCabeza();
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
#endif // LISTA_H
