#pragma once
#include <iostream>
#include "Producto.h"
#include "Nodo.cpp"

class ListaProducto{
    private:
        Nodo *primero;
        Nodo *actual;
    public:

    Nodo* getPrimero();

    Nodo* getActual();

    void setPrimero(Nodo *primero);

    void setActual(Nodo *actual);

    int size();

    bool listaVacia();

    ListaProducto();
    
    void insertar(Producto producto);

    // Eliminar un producto de la lista
    void eliminar(int codigo);

    // Buscar un producto en la lista por medio del atrubuto codigo que es int y retornarlo
    Nodo* buscar(int codigo);

    // Mostrar todos los productos de la lista
    void mostrar();

    int contarRegistrosEnAnio(int anio);
};