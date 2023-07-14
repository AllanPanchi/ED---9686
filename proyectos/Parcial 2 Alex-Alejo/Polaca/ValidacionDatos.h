
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