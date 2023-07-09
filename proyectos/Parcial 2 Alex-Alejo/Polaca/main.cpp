
#include <iostream>
#include "OperacionPolaca.cpp"

int main()
{
    std::string operacion;

    std::cout << "Ingrese la operacion infija: " << std::endl;
    std::cin >> operacion;
    OperacionPolaca::operacionPolacaPostfija(operacion);
    OperacionPolaca::operacionPolacaPrefija(operacion);

}