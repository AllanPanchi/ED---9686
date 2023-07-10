
#include <iostream>
#include "OperacionPolaca.cpp"
#include "Validacion.cpp"

int main()
{
    //std::string operacion;
    Validacion validador;
   

    //std::cout << "Ingrese la operacion infija: " << std::endl;
    //std::cin >> operacion;
    std::string operacion= validador.validarEntradaOperacion();
    
       

    OperacionPolaca::operacionPolacaPostfija(operacion);
    OperacionPolaca::operacionPolacaPrefija(operacion);

}