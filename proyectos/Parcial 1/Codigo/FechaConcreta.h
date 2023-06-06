#ifndef FECHACONCRETA_H
#define FECHACONCRETA_H

#include <iostream>

class FechaConcreta {
    private:
        int dia;
        int mes;
        int anio;

    public:
        // FechaConcreta();
    
        // FechaConcreta(int dia, int mes, int anio);

        // int getDia();

        // int getMes();

        // int getAnio();

        // void setDia(int dia);

        // void setMes(int mes);

        // void setAnio(int anio);

        // void print();

    FechaConcreta() : dia(0), mes(0), anio(0){}
    
    FechaConcreta(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}

    int getDia(){
        return dia;
    }

    int getMes(){
        return mes;
    }

    int getAnio(){
        return anio;
    }

    void setDia(int dia){
        this->dia = dia;
    }

    void setMes(int mes){
        this->mes = mes;
    }

    void setAnio(int anio){
        this->anio = anio;
    }

    void print(){
        std::cout << dia << "/" << mes << "/" << anio << std::endl;
    }
};

#endif  // FECHACONCRETA_H
