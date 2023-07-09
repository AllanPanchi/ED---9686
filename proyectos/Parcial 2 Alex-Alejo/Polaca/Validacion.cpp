#include "ValidacionDatos.h"
#include <cstdlib>
#include <conio.h>
#include <regex>

class Validacion : public ValidacionDatos
{
public:

    std::string solicitarReingreso(){
        std::string entrada;
        std::cout << "Ingrese nuevamente la operación (infija): " << std::endl;
        std::cin >> entrada;
        return entrada;
    }

    bool validarOperacion(std::string operacion){
        std::regex patron("[0-9]+$");
        if(!isdigit(operacion[0])){
            return false;
        }
        if(!isdigit(operacion[operacion.length()-1])){
            return false;
        }
        return true;
    }

    std::string validarEntradaOperacion() override
    {
        std::regex patron("^[0-9+\\-*/]+$");
        std::string entrada;
        std::cout << "Ingrese la operación (infija): " << std::endl;
        std::cin >> entrada;

        while (!std::regex_match(entrada, patron))
        {
            entrada = solicitarReingreso();
        }

        while (validarOperacion(entrada))
        {
            entrada = solicitarReingreso();
        }
        
        return entrada;
    }
};