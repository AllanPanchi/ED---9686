#include "Pila.h"

template <typename T>
Pila<T>::Pila() : top(nullptr) {}

template <typename T>
Pila<T>::~Pila() {
    while (!estaVacio()) {
        pop();
    }
}

template <typename T>
bool Pila<T>::estaVacio() const {
    return (top == nullptr);
}

template <typename T>
void Pila<T>::push(const T& item) {
    Nodo<T>* nuevoNodo = new Nodo<T>(item);
    nuevoNodo->setSiguiente(top);
    top = nuevoNodo;
}

template <typename T>
T Pila<T>::pop() {
    if (estaVacio()) {
        throw "La Pila está vacia. No se puede hacer un pop a este elemento.";
    }

    Nodo<T>* temp = top;
    T dato = temp->getDato();
    top = top->getSiguiente();
    delete temp;

    return dato;
}

template <typename T>
T Pila<T>::peek() const {
    if (estaVacio()) {
        throw "La Pila está vacia. No se puede hacer peek.";
    }
    return top->getDato();
}

