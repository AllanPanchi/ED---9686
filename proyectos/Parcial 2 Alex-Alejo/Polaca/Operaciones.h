/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Alex Trejo 
                
Fecha de inicio: 30/06/2023
Fecha de modificación: 16/07/2023

Proyecto sobre Calculadora polaca infija, posfija y prefija
*/
#pragma once

class Operaciones{

    private:
        const double PI = 3.141592653589793238463;
        const double EPSILON = 1e-10;
    
    public:
        
        int redondear(double numero);
        bool isNaN(double valor);
        double abs(double valor);
        double normalizaRadian(double radian);
        double seno(double operando);
        double coseno(double operando);
        double tangente(double operando);
        double log(double operando);
        double potencia(double base, double exponente);
        double getPI();
        double getEPSILON();    
        Operaciones();
        ~Operaciones();

};