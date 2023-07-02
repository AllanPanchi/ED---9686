#pragma once

class operaciones{

    private:
        double base;
        int exponente;

        double radicando;
        int indice;

        //calculo de seno

        double factorial(int n);
        double power(double base, int exponent);
        double fabs(double numero);
    
    public:
        
        operaciones();
        
        //exponente
        void setBase(double base);
        double getBase();
        void setExponente(int exponente);
        double getExponente();
        double calcularExponente ( double base, int exponente); 

        //raiz cuadrada y cubica
        void setRadicando(double radicando);
        double getRadicando();
        void setIndice(int indice);
        double getIndice();

        double calcularRaiz (double radicando, int indice); 


        //calculo seno
        operaciones();
        double calcularSeno(double x);

        //calculo coseno

        double calcularCoseno(double x);

        //calculo tangente
        double calcularTangente(double x);



       


};