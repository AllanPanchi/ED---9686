#include "Lista.h"

template <typename T>
void Lista<T>::setPrimero(Nodo<T>* primero)
{
    this->primero = primero;
}

template <typename T>
void Lista<T>::setUltimo(Nodo<T>* ultimo)
{
    this->ultimo = ultimo;
}

template <typename T>
Nodo<T>* Lista<T>::getPrimero()
{
    return this->primero;
}

template <typename T>
Nodo<T>* Lista<T>::getUltimo()
{
    return this->ultimo;
}

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

template <typename T>
bool Lista<T>::estaVacia()
{
    if(this->primero == nullptr)
    {
        return true;
    }
    return false;
}
