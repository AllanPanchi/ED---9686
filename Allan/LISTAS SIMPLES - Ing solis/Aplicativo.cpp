#include <iostream>
#include "Lista.h"
int main(int argc, char** argv) {
	Lista lst;
	lst.insertar(8);
	lst.insertar(10);
	lst.insertar(7);
	lst.insertar(9);
	std::cout << "lista sin cambiar" << std::endl;
	lst.mostrarLista();
	lst.cambiarValoresLista();
	std::cout << "lista cambiada" << std::endl;
	lst.mostrarLista();
	return 0;
}
