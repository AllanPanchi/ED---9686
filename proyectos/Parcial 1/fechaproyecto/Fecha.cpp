#include <iostream>
#include "Fecha.h"

class FechaConcreta : public Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    FechaConcreta(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}

    int getDia() const override {
        return dia;
    }

    int getMes() const override {
        return mes;
    }

    int getAnio() const override {
        return anio;
    }

    void setDia(int dia) override {
        this->dia = dia;
    }

    void setMes(int mes) override {
        this->mes = mes;
    }

    void setAnio(int anio) override {
        this->anio = anio;
    }

    void print() const override {
        std::cout << dia << "/" << mes << "/" << anio << std::endl;
    }
};
