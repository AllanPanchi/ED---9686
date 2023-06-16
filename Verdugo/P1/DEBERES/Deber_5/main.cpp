#include <iostream>
#include "ValDatos.cpp"
#include "Lista.h"

int main() {
    
    Lista lst;

    lst.insertarPorCabeza(1);
    lst.insertarPorCabeza(2);
    lst.insertarPorCabeza(3);
    lst.insertarPorCabeza(4);

    lst.mostrarLista();

    Nodo *nodo = lst.buscar(3);
    if (nodo != NULL) {
        cout << "Nodo encontrado: " << nodo->getValor() << endl;
    } else {
        cout << "Nodo no encontrado" << endl;
    }

    lst.eliminar(3);

    const auto sumarElementos = [](int acum, Nodo *nodo, const auto& val) -> int{
        if (nodo == NULL)
        {
            return acum;
        }else{
            acum += nodo->getValor();
            return val(acum, nodo->getSiguiente(), val);
        }
        
    };

    std::cout << "Suma de elementos: " << sumarElementos(0, lst.getPrimero(), sumarElementos) << std::endl;
    
    lst.mostrarLista();
    

    return 0;
}