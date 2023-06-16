#pragma once
#include "Nodo.h"
#include <iostream>

using namespace std;

class Lista {
private:
    Nodo* primero;
    Nodo* actual;
    bool listaVacia() {
        return (this->primero == NULL);
    }

public:
    Lista() {
        this->primero = NULL;
        this->actual = NULL;
    }

void insertar(int val) {
        Nodo* nuevo = new Nodo(val);
        if (listaVacia()) {
            this->primero = nuevo;
        }
        else {
            this->actual->siguiente = nuevo;
        }
        this->actual = nuevo;
    }

    void intercambiarNodos() {
        Nodo* tmp = this->primero;
        while (tmp != NULL && tmp->siguiente != NULL) {
            int temp = tmp->valor;
            tmp->valor = tmp->siguiente->valor;
            tmp->siguiente->valor = temp;
            tmp = tmp->siguiente->siguiente;
        }
    }

    void mostrarLista() {
        Nodo* tmp = this->primero;
        while (tmp) {
            cout << tmp->valor << "-->";
            tmp = tmp->siguiente;
        }
        cout << "NULL" << endl;
    }
};
