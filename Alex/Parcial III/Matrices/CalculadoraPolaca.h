#pragma once

#include <string>
#include "ArbolBinario.h"
#include "ListaSimple.cpp"
#include "Matriz.h"

class CalculadoraPolaca
{
public:
   CalculadoraPolaca(std::string expresionInfijo);
   ~CalculadoraPolaca();
   std::string getExpresionInfijo(void);
   void setExpresionInfijo(std::string newExpresionInfijo);
   std::string getExpresionPostfijo(void);
   void setExpresionPostfijo(std::string newExpresionPostfijo);
   std::string removerParentesis(std::string expresion);
   NodoArbol<std::string>* crearArbol(std::string expresion);
   Matriz evaluarExpresionPostfija(ListaSimple<Matriz> matrices);
   std::string eliminarEspaciosConsecutivos(std::string cadena);

protected:
private:
   std::string expresionInfijo;
   std::string expresionPostfijo;


};

