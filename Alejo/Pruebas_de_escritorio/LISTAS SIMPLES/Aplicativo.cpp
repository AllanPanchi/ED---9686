#include <iostream>
#include "Lista.h"
#include <functional>

int main(int argc, char** argv) {
	Lista lst;
	lst.insertarPorCabeza(5);
	lst.insertarPorCabeza(15);
	lst.insertarPorCola(35);
	lst.insertarPorCola(45);
	lst.insertarPorCola(55);

	lst.mostrarLista();

	const auto sumarElementos = [](Lista lsta, int &suma, const auto& funcionRecursiva) -> void{
		if (lsta.listaVacia()){
			suma = 0;
		}
		
		if (lsta.getPrimero() != NULL) {
			suma += lsta.getPrimero()->getValor();
			lsta.setPrimero(lsta.getPrimero()->getSiguiente());
			funcionRecursiva(lsta, suma, funcionRecursiva);
		}
    };

	Lista aux = lst;
	int sumas = 0;
	sumarElementos(aux, sumas, sumarElementos);
    std::cout << sumas << std::endl;

	return 0;
}