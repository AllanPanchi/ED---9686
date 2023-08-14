#include "Nodo.h"

    template <typename T>
    Nodo<T>::Nodo() {
        valor = T();
        siguiente = nullptr;
    }

    template <typename T>
    Nodo<T>::Nodo(T _valor, Nodo* _siguiente) {
        valor = _valor;
        siguiente = _siguiente;
    }

    //Destructor
    template <typename T>
    Nodo<T>::~Nodo() {
        delete siguiente;
    }

    //Metodos Get - Set
    template <typename T>
    T Nodo<T>::getValor() const{
        return valor;
    }

    template <typename T>
    void Nodo<T>::setValor(T _valor) {
        valor = _valor;
    }

    template <typename T>
    Nodo<T>* Nodo<T>::getSiguiente() const{
        return siguiente;
    }

    template <typename T>
    void Nodo<T>::setSiguiente(Nodo* _siguiente) {
        siguiente = _siguiente;
    }
