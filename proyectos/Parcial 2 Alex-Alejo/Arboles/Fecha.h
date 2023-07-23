#pragma once
#include <iostream>
#include <string>
#include "ValDatos.h"

class Fecha
{
private:
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
    int segundo;
public:
    Fecha();
    ~Fecha();
    Fecha(int dia, int mes, int anio, int hora, int minuto, int segundo);
    int getDia();
    void setDia(int dia);
    int getMes();
    void setMes(int mes);
    int getAnio();
    void setAnio(int anio);
    int getHora();
    void setHora(int hora);
    int getMinuto();
    void setMinuto(int minuto);
    int getSegundo();
    void setSegundo(int segundo);
    bool esAnioBisiesto(int anio);
    Fecha validarFecha(Fecha &fecha);
    Fecha validarFechaNacimiento(Fecha &fecha);

    static Fecha getFechaActual(Fecha fecha);

    bool operator<(Fecha fecha);
    bool operator>(Fecha fecha);
    bool operator==(Fecha fecha);
    bool operator!=(Fecha fecha);
    bool operator<=(Fecha fecha);
    bool operator>=(Fecha fecha);
    friend std::ostream& operator<<(std::ostream& os, const Fecha& fecha);
    friend std::istream& operator>>(std::istream& is, Fecha& fecha);

};