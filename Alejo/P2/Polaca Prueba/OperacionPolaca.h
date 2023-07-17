
#include <iostream>
#include "Lista.cpp"

class OperacionPolaca
{
public:

    static void funcion(const std::string& entrada);
    static void operacionPolacaPrefija(std::string operacion);
    static void operacionPolacaPostfija(std::string operacion);
};