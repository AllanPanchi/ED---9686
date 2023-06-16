#include <iostream>
#include "Lista.h"
int main(int argc, char** argv) {
	Lista lst;
	int numNodos;
	std::cout << "Ingrese el número de nodos: ";
    std::cin >> numNodos;
    
    for (int i = 0; i < numNodos; i++) {
        int val;
		std::cout << "Ingrese el valor para el nodo " << i + 1 << ": ";
        std::cin >> val;
        lst.insertar(val);
    }

	cout << "Lista original: ";
    lst.mostrarLista();

    lst.intercambiarNodos();

    cout << "Lista con nodos intercambiados: ";
    lst.mostrarLista();

    return 0;
}