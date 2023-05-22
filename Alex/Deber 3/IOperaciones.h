/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
			 Allan Panchi
			 Sebastian Verdugo
			 Alejandro Andrade
Fecha de inicio: 12/05/2023
Fecha de modificación: 22/05/2023

Templates implementados en C++
*/

#ifndef __Fraccion_IOperaciones_h
#define __Fraccion_IOperaciones_h

#include "Fraccion.h"

template <typename T>
class IOperaciones
{
public:
   IOperaciones(T obj1, T obj2);
   T operacion();

protected:
private:
   T objeto1;
   T objeto2;

};

#endif