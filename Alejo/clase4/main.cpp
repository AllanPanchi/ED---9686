#include "Operacion.h"
#include <iostream>

int main(int argc, char** argv)
{
    Operacion v1(2.2, 3.2);
    Operacion v2(4.2, 5.2);
    Operacion v3 = v1 + v2;
    
    //std::cout << "v1 = <" << v1.getA() << ',' << v1.getB() << ">\n";
    //std::cout << "v2 = <" << v2.getA() << ',' << v2.getB() << ">\n";
    //std::cout << "v3 = <" << v3.getA() << ',' << v3.getB() << ">\n";

    return 0;
}

/*
    Hacer 3 metodos en calculo y sobreescrbir el operador << para la impresion
*/
