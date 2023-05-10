/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
          Allan Panchi
          Sebastian Verdugo
          Alejandro Andrade
Fecha de inicio: 04/05/2023
Fecha de modificación: 09/05/2023

Realizar 4 operaciones en una interface que incluyan datos abstractos 
*/
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

   float operacion1(Fraccion fraccion1, Fraccion fraccion2) override
   {
      return fraccion1.getNumerador()*fraccion2.getNumerador();
   }

   Fraccion operacion2(Fraccion fraccion1, Fraccion fraccion2) override
   {
      Fraccion fraccion(fraccion1.getNumerador(), fraccion2.getDenominador());
      return fraccion;
   }

   Fraccion operacion3(float flotante1, float flotante2) override
   {
      Fraccion fraccion(flotante1 * flotante2, flotante1 - flotante2);
      fraccion.setDenominador(validarDenominador(fraccion.getDenominador()));
      return fraccion;
   }

   float operacion4(float flotante1, float flotante2) override
   {
      return flotante1 * flotante2;
   }

};
