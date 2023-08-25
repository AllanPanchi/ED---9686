#ifndef SINGLETON_H
#define SINGLETON_H

#include "ListaSimple.cpp"
#include "Pieza.h"
class Singleton {

public:
    static Singleton* getInstance();

    ListaSimple<Pieza>& getPiezas();
private:
    static Singleton* instance;
    ListaSimple<Pieza> piezas;
    Singleton();
};

#endif