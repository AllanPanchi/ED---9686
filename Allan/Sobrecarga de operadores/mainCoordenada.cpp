/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
			 Allan Panchi
			 Sebastian Verdugo
			 Alejandro Andrade
Fecha de inicio: 10/05/2023
Fecha de modificación: 21/05/2023

Realizar una sobrecarga de 4 operadores y uno extra para poder pracitcar
*/

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include "Operacion.cpp"
using namespace std;


int main(int arch, char** argv)
{
    Operacion op1;
    Operacion op2;
    Operacion op3;
    Operacion op4;
    op1.setNum1(3.5F);
    op1.setNum2(3.7F);
    op2.setNum1(5.6F);
    op2.setNum2(5.4F);
    op3 = op1 && op2;
    op4 = op1 || op2;

    std::cout << "Operador sobrecargado +" << std::endl;
    std::cout << op1.getNum1() << " , " << op1.getNum2() << " , " << op2.getNum1() << " , " << op2.getNum2() << " = " << op1 + op2 << std::endl;

    std::cout << "Operador sobrecargado <<" << std::endl;
    std::cout <<  op1 << std::endl;
    std::cout <<  op2 << std::endl;

    std::cout << "Operador sobrecargado -" << std::endl;
    std::cout << op1.getNum1() << " , " << op1.getNum2() << " , " << op2.getNum1() << " , " << op2.getNum2() << " = " << op1 - op2 << std::endl;

    std::cout <<"Operador sobrecargado &&" << std::endl;
    std::cout << op3.getNum1() << "," << op3.getNum2() << std::endl;

    std::cout <<"Operador sobrecargado ||" << std::endl;
    std::cout << op4.getNum1() << "," << op4.getNum2() << std::endl;
    return 0;

}
