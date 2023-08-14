#ifndef OPERACIONES_H
#define OPERACIONES_H

#include "Pila.h"
#include <string>
using namespace std;


class Operaciones
{
	public:
		bool operadores(string c);
		bool funTrigonometrica(string c);
		int prioridad(string c);
		Pila<string> copiarPila(Pila<string> datos);
		string sustraer(string cad, int posInicial, int numCaracter);
		bool numero(string cad);
		Pila<string> invertirPila(Pila<string> datos);
		double calcular(Pila<string> prefija);
		Pila<string> ingresarDatos();
		bool validarExpresion(Pila<string> datos1);
		Pila<string> expresionAPila(string& expresion);
		
	protected:
};

#endif