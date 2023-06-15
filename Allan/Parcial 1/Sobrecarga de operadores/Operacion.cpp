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

#include "Operacion.h"

Operacion::Operacion(){}

Operacion::Operacion(float Num1, float Num2){
   this->num1 = Num1;
   this->num2 = Num2;
}

Operacion::~Operacion(){}

float Operacion::getNum1(void)
{
   return num1;
}

void Operacion::setNum1(float newNum1)
{
   num1 = newNum1;
}

float Operacion::getNum2(void)
{
   return num2;
}

void Operacion::setNum2(float newNum2)
{
   num2 = newNum2;
}

float Operacion::operator +(const Operacion& operacion) const
{
   return (num1 + operacion.num2, num2 + operacion.num1);
}

std::ostream& operator <<(std::ostream& imprimir, const Operacion& operacion)
{
   imprimir << "Es un objeto tipo Operacion que contiene dos numeros" << std::endl;
   imprimir << "Numero 1 = " << operacion.num1;
   imprimir << "\nNumero 2 = " << operacion.num2;
   return imprimir;

}

float Operacion::operator -(const Operacion& operacion) const
{
   return (num1 - num2, operacion.num1 - operacion.num2);
}

Operacion Operacion::operator &&(const Operacion& op) const
{
   Operacion res(num1 > op.num1 && num2 < op.num2, num1 < num2 && op.num1 > op.num2);
   return res;
}

Operacion Operacion::operator ||(const Operacion& op) const
{
    Operacion res(num1 > op.num1 || num2 < op.num2, num1 < num2 || op.num1 > op.num2);
    return res;
}

