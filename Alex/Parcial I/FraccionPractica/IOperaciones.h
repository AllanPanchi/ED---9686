/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: 
        Alex Trejo
        Allan Panchi
        Sebastian Verdugo
        Alejandro Andrade
Fecha de inicio: 04/05/2023
Fecha de modificación: 09/05/2023

Realizar 4 operaciones en una interface que incluyan datos abstractos 
*/


/***********************************************************************
 * Module:  IOperaciones.h
 * Author:  Alex_22
 * Modified: mi�rcoles, 10 de mayo de 2023 1:17:41
 * Purpose: Declaration of the class IOperaciones
 ***********************************************************************/

#if !defined(__FRACCION_IOperaciones_h)
#define __FRACCION_IOperaciones_h

#include "Fraccion.h"

class IOperaciones
{
public:
   virtual float operacion1(Fraccion fraccion1, Fraccion fraccion2)=0;
   virtual Fraccion operacion2(Fraccion fraccion1, Fraccion fraccion2)=0;
   virtual Fraccion operacion3(float dato1, float dato2)=0;
   virtual float operacion4(float dato1, float dato2)=0;

protected:
private:

};

#endif