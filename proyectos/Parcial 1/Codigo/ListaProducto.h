/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Allan Panchi
                Alex Trejo 
                Sebastian Verdugo
Fecha de inicio: 02/05/2023
Fecha de modificación: 08/06/2023

Proyecto sobre registros utlizando listas doblemente enlazadas
*/
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

    ListaProducto buscarPorAnioElaboracion(int anioElaboracion);

    void actualizar(Nodo *actual);

    // Mostrar todos los productos de la lista
    void mostrar();

    void sobreescribirArchivo(const std::string& nombreArchivo, ListaProducto& lista);

    void cargarDatosDesdeArchivo(const std::string& nombreArchivo, ListaProducto& lista);

    void vaciarLista();
};