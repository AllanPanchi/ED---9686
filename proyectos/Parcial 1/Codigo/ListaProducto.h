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

    void actualizar(Nodo *actual);
    

    // Mostrar todos los productos de la lista
    void mostrar();

    // void cargarDatosEnArchivo(const std::string& nombreArchivo, ListaProducto& lista);

    // void guardarDatosEnArchivo(const std::string& nombreArchivo, const ListaProducto& lista);

    void sobreescribirArchivo(const std::string& nombreArchivo);

    void cargarDatosDesdeArchivo(const std::string& nombreArchivo);

};