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
#include "OperacionPolaca.cpp"
#include "Validacion.cpp"
#include "IngresoExpresiones.cpp"

int main()
{
    Validacion validador;
    std::string operacion;
    

    std::cout<<"Ingrese la Expresion en Notacion Infija: "<<std::endl;
	std::string expresion;

    operacion = validador.validarEntradaOperacion();

    OperacionPolaca::operacionPolacaPostfija(expresion);
    OperacionPolaca::operacionPolacaPrefija(expresion);

    //expresion = IngresoExpresiones::ingresoExpresion();

    // if (!validador.esExpresionValida(expresion)) {
    //     std::cout << "La expresion contiene caracteres no validos." << std::endl;
    //     return 0;
    // }
    
    // if (!validador.esParentesisEquilibrado(expresion)) {
    //     std::cout << "La expresion tiene desequilibrio de parentesis." << std::endl;
    //     return 0;
    // }
    
    // std::cout << "La expresion es valida y esta balanceada." << std::endl;


    return 0;

}