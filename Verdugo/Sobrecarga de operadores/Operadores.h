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
#ifndef OPERADORES_H_INCLUDED
#define OPERADORES_H_INCLUDED

#include <iostream>

class Operacion;

class Operadores
{
    public:
        virtual float operator +(const Operacion&)const = 0;
        friend std::ostream& operator <<(std::ostream& imprimir, const Operacion& operacion);
        virtual float operator -(const Operacion&)const = 0;
        virtual Operacion operator ||(const Operacion&)const = 0;
        virtual Operacion operator &&(const Operacion&)const = 0;
};


#endif // OPERADORES_H_INCLUDED
