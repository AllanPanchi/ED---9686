/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Allan Panchi
                Alex Trejo 
                Sebastian Verdugo
Fecha de inicio: 15/06/2023
Fecha de modificación: 15/06/2023

Ordenamiento de lista circular doblemente enlazadas
*/

#include <iostream>
#include "Nodo.cpp"

class Lista{
    private:
        Nodo<Registro> *primero;
        Nodo<Registro> *actual;
    public:

    Nodo<Registro>* getPrimero();

    Nodo<Registro>* getActual();

    void setPrimero(Nodo<Registro> *primero);

    void setActual(Nodo<Registro> *actual);

    int size();

    bool listaVacia();

    Lista();
    
    void insertar(Registro registro);

    // Eliminar un registro de la lista
    void eliminar(std::string cedula);

    // Buscar un registro en la lista por medio del atrubuto codigo que es int y retornarlo
    Nodo<Registro>* buscar(std::string cedula);

    //void actualizar(Nodo<Registro> *actual);

    // Mostrar todos los registros de la lista
    void mostrar();

    void sobreescribirArchivo(const std::string& nombreArchivo, Lista& lista);

    void cargarDatosDesdeArchivo(const std::string& nombreArchivo, Lista& lista);

    void vaciarLista();
};