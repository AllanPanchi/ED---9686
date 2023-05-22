/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
          Allan Panchi
          Sebastian Verdugo
          Alejandro Andrade
Fecha de inicio: 04/05/2023
Fecha de modificación: 22/05/2023

Imprementar la interface en una clase y llamar a esta clase en el main 
*/
#ifndef FRACCION_H
#define FRACCION_H

#include <iostream>
#include <string>

using namespace std;

class Fraccion{
    private:
        int numerador;
        int denominador;
        
    public:
        
        float getNumerador(void);
        float getDenominador(void);
        void setNumerador(float nuevoNumerador);
        void setDenominador(float nuevoDenominador);

        Fraccion();
        ~Fraccion();
        Fraccion(float, float);
        Fraccion proceso(Fraccion object1, Fraccion object2);
        void toString();
        float validarDenominador(float denominador);
    
};

#endif