#pragma once

#include "ListaCircularDoble.h"
#include "Opcion.h"
#include <string>
#include <functional>
template <typename T>
class NodoDoble;

class Menu{
	public:
		//Constructor
		Menu(std::string);
		
		//Operaciones
		void setTitulo(std::string newTitulo);
		void desplegarMenu();
		void moverArriba();
		void moverAbajo();
		Opcion getOpcionSeleccionada(void);
		void correr();
		void insertarOpcion(std::string, const std::function<void()>&);
		
	private:
	    ListaCircularDoble<Opcion> opciones;
	    NodoDoble<Opcion>* opcionSeleccionada;
	    std::string titulo;

};

