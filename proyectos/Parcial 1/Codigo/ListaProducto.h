#include <iostream>
#include "Producto.h"
#include "Fecha.cpp"
#include "IProducto.h"
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

    // actualizar el atributo nombre que es de tipo string de un producto de la lista en el que se busca por codigo
    void actualizarNombre(int codigo, std::string nombre);

    // actualizar el atributo precio que es de tipo double de un producto de la lista en el que se busca por codigo
    void actualizarPrecio(int codigo, float precio);

    // actualizar el atributo fechaElaboracion que es de tipo Fecha de un producto de la lista en el que se busca por codigo
    void actualizarFechaElaboracion(int codigo, FechaConcreta fechaElaboracion);

    // actualizar el atributo fechaCaducidad que es de tipo Fecha de un producto de la lista en el que se busca por codigo
    void actualizarFechaCaducidad(int codigo, FechaConcreta fechaCaducidad);

};