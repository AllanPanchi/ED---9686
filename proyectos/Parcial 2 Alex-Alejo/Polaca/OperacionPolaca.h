/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Alex Trejo 
                
Fecha de inicio: 30/06/2023
Fecha de modificación: 16/07/2023

Proyecto sobre Calculadora polaca infija, posfija y prefija
*/
#include <iostream>
#include "Lista.cpp"

class OperacionPolaca
{
public:

    static void funcion(const std::string& entrada);
    static void operacionPolacaPrefija(std::string operacion);
    static void operacionPolacaPostfija(std::string operacion);
};