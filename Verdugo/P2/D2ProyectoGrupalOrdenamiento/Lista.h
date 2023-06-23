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

#include "Nodo.cpp"
#include <vector>

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
    
    void insertar(T registro);

    // Eliminar un registro de la lista
    void eliminar(std::string cedula);

    Nodo<T>* buscar(std::string cedula);

    // Buscar el ultimo Nodo por su cedula
    Nodo<T>* buscarUltimo(std::string cedula);

    // Actualizar un registro de la lista
    void actualizarEstado(Nodo<T> *actual, T dato);

    // Mostrar todos los registros de la lista
    void mostrar();

    void sobreescribirArchivo(const std::string& nombreArchivo, Lista& lista);

    void cargarDatosDesdeArchivo(const std::string& nombreArchivo, Lista& lista);

    void vaciarLista();

    void bucketSortCedula();
};