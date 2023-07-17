/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Alex Trejo 
                
Fecha de inicio: 30/06/2023
Fecha de modificación: 16/07/2023

Proyecto sobre Calculadora polaca infija, posfija y prefija
*/
#include "Nodo.cpp"

template <typename T>
class Lista
{
private:
    Nodo<T>* primero;
    Nodo<T>* ultimo;
public:
    void setPrimero(Nodo<T>* primero);
    void setUltimo(Nodo<T>* ultimo);
    Nodo<T>* getPrimero();
    Nodo<T>* getUltimo();
    int size();
    void insertar(T dato);
    void eliminar(T dato);
    Nodo<T>* buscar(T dato);
    bool buscarDatos(T dato);
    bool estaVacia();
    void imprimir();

};
