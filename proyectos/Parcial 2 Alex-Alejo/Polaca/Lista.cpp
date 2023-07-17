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
#include "Lista.h"

/// @brief Guarda el primer nodo de la lista
/// @tparam T 
/// @param primero Nodo<T>* primero
template <typename T>
void Lista<T>::setPrimero(Nodo<T>* primero)
{
    this->primero = primero;
}

/// @brief Guarda el ultimo nodo de la lista
/// @tparam T 
/// @param ultimo 
template <typename T>
void Lista<T>::setUltimo(Nodo<T>* ultimo)
{
    this->ultimo = ultimo;
}

/// @brief Retorna el primer nodo de la lista
/// @return Nodo<T>*
template <typename T>
Nodo<T>* Lista<T>::getPrimero()
{
    return this->primero;
}

/// @brief Retorna el ultimo nodo de la lista
/// @return Nodo<T>*
template <typename T>
Nodo<T>* Lista<T>::getUltimo()
{
    return this->ultimo;
}

/// @brief Retorna el tamaño de la lista
/// @return int
template <typename T>
int Lista<T>::size()
{
    int contador = 0;
    Nodo<T>* aux = this->primero;
    while (aux != nullptr)
    {
        contador++;
        aux = aux->getSiguiente();
    }
    return contador;
}

/// @brief Inserta un nodo al final de la lista
/// @tparam T
/// @param dato
template <typename T>
void Lista<T>::insertar(T dato)
{
    Nodo<T>* nuevo = new Nodo<T>(dato);
    if (this->primero == nullptr)
    {
        this->primero = nuevo;
        this->ultimo = nuevo;
    }
    else
    {
        this->ultimo->setSiguiente(nuevo);
        this->ultimo = nuevo;
    }
}

/// @brief Elimina el nodo que contiene el dato
/// @tparam T
/// @param dato
template <typename T>
void Lista<T>::eliminar(T dato)
{
    Nodo<T>* aux = this->primero;
    Nodo<T>* anterior = nullptr;
    while (aux != nullptr)
    {
        if (aux->getDato() == dato)
        {
            if (aux == this->primero)
            {
                this->primero = this->primero->getSiguiente();
                delete aux;
                return;
            }
            else if (aux == this->ultimo)
            {
                this->ultimo = anterior;
                this->ultimo->setSiguiente(nullptr);
                delete aux;
                return;
            }
            else
            {
                anterior->setSiguiente(aux->getSiguiente());
                delete aux;
                return;
            }
        }
        anterior = aux;
        aux = aux->getSiguiente();
    }
}

/// @brief Retorna el nodo que contiene el dato
/// @tparam T
/// @param dato
/// @return Nodo<T>*
template <typename T>
Nodo<T>* Lista<T>::buscar(T dato)
{
    Nodo<T>* aux = this->primero;
    while (aux != nullptr)
    {
        if (aux->getDato() == dato)
        {
            return aux;
        }
        aux = aux->getSiguiente();
    }
    return nullptr;
}

/// @brief Retorna true si la lista esta vacia
/// @return bool
template <typename T>
bool Lista<T>::estaVacia()
{
    if(this->primero == nullptr)
    {
        return true;
    }
    return false;
}

/// @brief Si el dato esta en la lista, retorna true
/// @tparam T
/// @param dato
/// @return bool
template <typename T>
bool Lista<T>::buscarDatos(T dato)
{
    // Si el dato esta en la lista, retorna true
    Nodo<T>* aux = this->primero;
    while (aux != nullptr)
    {
        if (aux->getDato() == dato)
        {
            return true;
        }
        aux = aux->getSiguiente();
    }    
    return false;
}

/// @brief Imprime los datos de la lista
template <typename T>
void Lista<T>::imprimir()
{
    Nodo<T>* aux = this->primero;
    while (aux != nullptr)
    {
        std::cout << aux->getDato() << std::endl;
        aux = aux->getSiguiente();
    }
}