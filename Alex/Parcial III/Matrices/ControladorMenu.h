#pragma once
#include "CalculadoraPolaca.h"
#include "Matriz.h"
#include <string>

class ControladorMenu{
	public:
		ControladorMenu(){};
		void correrMenu();
	private:
		int cantidadMatrices;
		ListaSimple<Matriz> matrices;
		std::string expresion;
		//Funciones de control de personal
		void ingresarMatrices();
		void multiplicarMatrices();
		void verOptimizacion();
		void generarMatricesAleatorias();
		void mostrarMatrices();
		
		//Salir
		void salir();
		
		bool menuEjecutando = false;
};

