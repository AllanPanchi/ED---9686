#pragma once
#include "iostream"

template <typename T>

class Nodo {

private:
    T valor;
    Nodo* siguiente;

public:

    Nodo();

    Nodo(T _valor, Nodo* _siguiente = nullptr);

    ~Nodo();

    T getValor() const;

    void setValor(T _valor);

    Nodo<T>* getSiguiente() const;

    void setSiguiente(Nodo* _siguiente);
};
