/***********************************************************************
 * Module:  Fraccion.h
 * Author:  Alex_22
 * Modified: mi�rcoles, 10 de mayo de 2023 2:10:30
 * Purpose: Declaration of the class Fraccion
 ***********************************************************************/

#if !defined(__FRACCION_Fraccion_h)
#define __FRACCION_Fraccion_h
#include <iostream>


class Fraccion
{
public:
   void setNumerador(float newNumerador);
   float getDenominador(void);
   float getNumerador(void);
   void setDenominador(float newDenominador);
   Fraccion(float num, float den);
   ~Fraccion();
   Fraccion proceso(Fraccion obj1, Fraccion obj2);
   Fraccion();
   void toString(void);
   float validarDenominador(float denominador);
   float validarNumeroIngresado(float numeroIngresado);
   bool validarNumero(std::string numero);

protected:
private:
   float numerador;
   float denominador;


};

#endif