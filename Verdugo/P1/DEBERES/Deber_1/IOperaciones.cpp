/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
          Allan Panchi
          Sebastian Verdugo
          Alejandro Andrade
Fecha de inicio: 04/05/2023
Fecha de modificación: 11/05/2023

Imprementar la interface en una clase y llamar a esta clase en el main 
*/

#include <iostream>
#include "IOperaciones.h"

class Operaciones : public IOperaciones
{
public:
   
   float validarDenominador(float den)
   {
      if(den == 0)
      {
         std::cout << "El denominador no puede ser 0, se reemplazara con 1 -> ";
         den = 1;
      }
      return den;
   }

   void operacion(float flotante, Fraccion fraccion) override
   {
      flotante = flotante + fraccion.getNumerador();
   }

   float operacion(Fraccion fraccion1, Fraccion fraccion2) override
   {
      return fraccion1.getNumerador()*fraccion2.getNumerador();
   }

   Fraccion operacion(float flotante1, float flotante2) override
   {
      Fraccion fraccion(flotante1 * flotante2, flotante1 - flotante2);
      fraccion.setDenominador(validarDenominador(fraccion.getDenominador()));
      return fraccion;
   }

};