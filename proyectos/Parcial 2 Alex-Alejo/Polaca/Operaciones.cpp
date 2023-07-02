#pragma once
#include <iostream>
#include "Operaciones.h"

//exponente
    operaciones::operaciones(){
        this->base = base;
        this->exponente = exponente;
        this->radicando= radicando;
        this->indice= indice;
    
    }


    void operaciones::setBase(double base){
        this->base = base;

    }


    double operaciones::getBase(){
        return base;

    }   


    void operaciones::setExponente(int exponente){
        this->exponente = exponente;

    }


    double operaciones::getExponente(){
        return exponente;

    }

    double operaciones::calcularExponente(double base, int exponente){

        double resultado = 1.0;
        bool negativo = false;

        if (exponente < 0) {
            exponente = -exponente;
            negativo = true;
        }

        for (int i = 0; i < exponente; ++i) {
            resultado *= base;
        }

        if (negativo) {
            resultado = 1.0 / resultado;
        }

        return resultado;

    }

//fin exponente

//raiz 
    void operaciones::setRadicando(double radicando){
        this->radicando = radicando;

    }


    double operaciones::getRadicando(){
        return radicando;

    }   


    void operaciones::setIndice(int indice){
        this->indice = indice;

    }


    double operaciones::getIndice(){
        return indice;

    }



    //Retorna el valor absoluto para double
    double fabs(double numero) {
        return (numero < 0) ? -numero : numero;
    }


    double operaciones::calcularRaiz(double radicando, int indice){

        double precision = 0.0001;
        if (radicando < 0 && indice % 2 == 0) {
                throw std::invalid_argument("No se puede calcular la raíz par de un número negativo");
            }
            if (radicando < 0 && indice % 2 != 0) {
                radicando = -radicando;
            }
            
            double aproximacion = radicando / 2;
            
            while (true) {
                double potencia = 1.0;
                for (int i = 0; i < indice; i++) {
                    potencia *= aproximacion;
                }
                
                double diferencia = aproximacion - (potencia - radicando) / (indice * potencia / aproximacion);
                
                if (fabs(diferencia) < precision) {
                    break;
                }
                
                aproximacion -= diferencia;
            }
            
            return aproximacion;

    }

//Fin raiz

//Seno
    double operaciones::calcularSeno(double x) {
        double precision = 0.0001;
        double resultado = x;
        double termino = x;
        int signo = -1;
        int n = 3;
        
        while (fabs(termino) >= precision) {
            termino = power(x, n) / factorial(n);
            resultado += signo * termino;
            signo *= -1;
            n += 2;
        }
        
        return resultado;
    }

    double operaciones::factorial(int n) {
        if (n <= 1) {
            return 1;
        }
        double fact = 1;
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }

    double operaciones::power(double base, int exponent) {
        double result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        return result;
    }

    double operaciones::fabs(double numero) {
        return (numero < 0) ? -numero : numero;
    }
 //fin seno

//coseno
    double operaciones::calcularCoseno(double x) {
        double precision=0.0001;
        double resultado = 1.0;
        double termino = 1.0;
        int signo = -1;
        int n = 2;
        
        while (fabs(termino) >= precision) {
            termino = power(x, n) / factorial(n);
            resultado += signo * termino;
            signo *= -1;
            n += 2;
        }
        
        return resultado;
    }
//fin coseno

//tangente
    double operaciones::calcularTangente(double x){
        double precision= 0.0001;
        double seno= calcularSeno(x);
        double coseno= calcularCoseno(x);

        if(coseno == 0){
            throw std::invalid_argument("No se puede calcular la tangente cuando el coseno es cero");

        } 

        return seno / coseno;

    }



