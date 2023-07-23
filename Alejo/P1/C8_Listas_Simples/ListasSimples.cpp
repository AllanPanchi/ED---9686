/*************************
 * UFA-ESPE
 * ALUMNOS:  Leonardo Obando, William Leon
 * FECHA CREACION: Miercoles, 21 de noviembre de 2022
 * FECHA MODIFICACION: Miercoles, 23 de noviembre de 2022
 * Enunciado del problema: Crear los m�todos Insertar, Buscar
 y Eliminar elementos de una lista Simple, Doble y Circular
 * Nivel: TERCERO     NRC: 7999
 *************************/
#include "ListasSimples.h"

using namespace std;

inline ListaSimples::ListaSimples() {
    cabeza = NULL;
}

inline void ListaSimples::setCebeza(Nodo* _cabeza) {
    cabeza = _cabeza;
}

inline Nodo* ListaSimples::getCabeza() {
    return cabeza;
}

inline void ListaSimples::Insertar(int _dato) {
    Nodo* nuevo = new Nodo(_dato);
    if (cabeza == NULL) {
        cabeza = nuevo;
    }
    else {
        Nodo* aux = cabeza;
        while (aux->getSiguiente() != NULL) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
}

void ListaSimples::recorrer(Nodo* tmp) {
    if(!tmp) {
        std::cout << "NULL" << std::endl;
    }
    else {
        cout << tmp->getDato() << " -> ";
        recorrer(tmp->getSiguiente());
    }
}

inline void ListaSimples::Buscar(int _dato) {
    Nodo* aux = this->cabeza;
    while (aux) {
        if (aux->getDato() == _dato) {
            cout << "El dato " << _dato << " si se encuentra en la lista" << endl;
            return;
        }
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
}

inline void ListaSimples::Eliminar(int _dato) {
    Nodo* aux = cabeza;
    Nodo* anterior = NULL;
    while (aux != NULL) {
        if (aux->getDato() == _dato) {
            if (anterior == NULL) {
                cabeza = aux->getSiguiente();
            }
            else {
                anterior->setSiguiente(aux->getSiguiente());
            }
            delete aux;
            cout << "El dato " << _dato << " se ha eliminado de la lista" << endl;
            return;
        }
        anterior = aux;
        aux = aux->getSiguiente();
    }
    cout << "El dato " << _dato << " no se encuentra en la lista" << endl;
}

inline void ListaSimples::Mostrar() {
    Nodo* aux = cabeza;
    while (aux != NULL) {
        cout << aux->getDato() << " -> ";
        aux = aux->getSiguiente();
    }
    cout << "NULL" << endl;
}
