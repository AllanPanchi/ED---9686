#include "ValidacionDatos.h"
#include <cstdlib>
#include <conio.h>
#include <regex>

class Validacion : public ValidacionDatos
{
public:

    std::string validarEntradaOperacion() override
    {
       // std::regex patron("^([0-9]+( [\\+\\-\\*/] [0-9]+)*)$");
        //std::string entrada;
        //std::cout << "Ingrese la expresion matematica en notacion infija separada por espacios: ";
        //std::getline(std::cin, entrada);
/*
        while (!std::regex_match(entrada, patron))
        {
            std::cout << "La expresion no es valida. Ingrese nuevamente: ";
            std::getline(std::cin, entrada);
        }

        return entrada;
    }*/

    
        std::regex patron("^(\\s*(\\d+\\.?\\d*|((sen|cos|tan) \\(\\s*(\\d+\\.?\\d*)\\s*\\))))(\\s*[+\\-/]\\s(\\d+\\.?\\d*|((sen|cos|tan) \\(\\s*(\\d+\\.?\\d*)\\s*\\))))*$");

        //std::regex patron("^(\\s*((\\d+\\.?\\d*)|(sen|cos|tan)\\s*\\(\\s*(\\d+\\.?\\d*)\\s*\\)|\\())(\\s*[+\\-/]\\s((\\d+\\.?\\d*)|(sen|cos|tan)\\s*\\(\\s*(\\d+\\.?\\d*)\\s*\\)))*$");

        
        std::string entrada;
        std::cout << "Ingrese la expresion matematica en notacion infija separada por espacios: ";
        std::getline(std::cin, entrada);

        while (!std::regex_match(entrada, patron))
        {
            std::cout << "La expresion no es valida. Ingrese nuevamente: ";
            std::getline(std::cin, entrada);
        }

       return entrada;

    }

};