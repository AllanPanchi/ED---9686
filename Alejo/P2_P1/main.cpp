#include <iostream>
#include "ValDatos.cpp"
#include "Lista.h"

int main() {
    
    Lista lst;

    lst.insertarPorCabeza(1);
    
    
    lst.mostrarLista();

    lst.alterarValores();

    lst.mostrarLista();
    

    return 0;
}