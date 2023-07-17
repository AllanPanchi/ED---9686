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
template <typename T>
class Nodo
{
private:
    T dato;
    Nodo<T>* siguiente;
public:
    Nodo(T dato);
    Nodo(T dato, Nodo<T>* siguiente);
    T getDato();
    Nodo<T>* getSiguiente();
    void setDato(T dato);
    void setSiguiente(Nodo<T>* siguiente);
};