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