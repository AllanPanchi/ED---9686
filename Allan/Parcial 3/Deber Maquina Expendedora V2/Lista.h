#include "Nodo.cpp"
#include <iostream>

template <typename T>
class Lista{
    private:
        Nodo<T> *primero;
        Nodo<T> *actual;
    public:

    Nodo<T>* getPrimero();

    Nodo<T>* getActual();

    void setPrimero(Nodo<T> *primero);

    void setActual(Nodo<T> *actual);

    int size();

    bool listaVacia();

    Lista();
    
    void insertar(T dato);

    // Eliminar un registro de la lista
    void eliminar(std::string cedula);

    Nodo<T>* buscar(std::string cedula);

    // Mostrar todos los registros de la lista
    void mostrar();

    void vaciarLista();

    void bucketSortCedula();

};