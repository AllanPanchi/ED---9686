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

#if !defined(__Fraccion_IOperaciones_h)
#define __Fraccion_IOperaciones_h

#include "Fraccion.h"

class IOperaciones
{
public:
   virtual float operacion1(Fraccion fraccion1, Fraccion fraccion2)=0;
   virtual Fraccion operacion2(Fraccion fraccion1, Fraccion fraccion2)=0;
   virtual Fraccion operacion3(float flotante1, float flotante2)=0;
   virtual float operacion4(float flotante1, float flotante2)=0;

protected:
private:

};

#endif