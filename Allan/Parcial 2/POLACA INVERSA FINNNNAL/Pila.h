#ifndef PILA_H
#define PILA_H

#include "Nodo.h"

template <typename T>
class Pila {
private:
    Nodo<T>* top;

public:
    Pila();
    ~Pila();

    bool estaVacio() const;
    void push(const T& item);
    T pop();
    T peek() const;
};

#endif