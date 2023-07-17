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

class ValidacionDatos
{
public:
    virtual std::string validarEntradaOperacion()=0;
    virtual bool esParentesisEquilibrado(const std::string& expresion)=0;
    virtual bool esCaracterValido(char c)=0;
    virtual bool esExpresionValida(const std::string& expresion)=0;
    virtual bool esExpresionBalanceada(const std::string& expresion)=0;


};