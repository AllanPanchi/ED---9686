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

#if !defined(__Fraccion_IOperaciones_h)
#define __Fraccion_IOperaciones_h

#include "Fraccion.h"

class IOperaciones
{
public:
   virtual void operacion(float flotante, Fraccion fraccion)=0;
   virtual float operacion(Fraccion fraccion1, Fraccion fraccion2)=0;
   virtual Fraccion operacion(float flotante1, float flotante2)=0;

protected:
private:

};

#endif