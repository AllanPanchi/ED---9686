#pragma once
#include "Nodo.cpp"

class Arbol
{
private:
    Nodo *arbol = NULL;
    void imprimirNivelActual(Nodo *, int); //Metodo para que funcione el recorrido por nivel
public:
    void setArbol(Nodo *);
    Nodo *getArbol();
    Nodo *crearNodo(int);
    void insertarNodo(Nodo *&, int);
    void mostrar(Nodo *, int);
    void buscar(Nodo *, int);
    void buscarporNivel(Nodo *, int);
    void preOrden(Nodo *);
    void inOrden(Nodo *);
    void recorridoNivel(Nodo *);
    void postOrden(Nodo *);
    int peso(Nodo *);
    int altura(Nodo *);
    bool simetria(Nodo *, Nodo *);
    bool simetrias(Nodo *);
    void calcularPrimos(Nodo* arbol);
    void sumarporNivel(Nodo *);
    void sumarDatosDecadaNivel(Nodo* arbol,int nivel);
    Nodo *eliminarNodo(Nodo *, int);
};
