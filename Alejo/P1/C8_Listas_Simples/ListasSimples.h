/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#pragma once
#include "Nodo.cpp"

using namespace std;

class ListaSimples {

private:
    Nodo* cabeza;
public:
    void setCebeza(Nodo*);
    Nodo* getCabeza();
    ListaSimples();
    void recorrer(Nodo*);
    void Insertar(int);
    void Buscar(int);
    void Eliminar(int);
    void Mostrar();
};

