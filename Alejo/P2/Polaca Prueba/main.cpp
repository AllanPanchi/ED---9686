
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

    std::cin >> expresion;

    OperacionPolaca::funcion(expresion);

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

    //operacion = validador.validarEntradaOperacion();

    // OperacionPolaca::operacionPolacaPostfija(expresion);
    // OperacionPolaca::operacionPolacaPrefija(expresion);

    return 0;

}