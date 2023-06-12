#include "Pila.h"
#include "Validacion.h"
#include <iostream>
#include <stack>

// Programa que suma los numeros que se ingresen haciendo un push y al final se hace un pop 
// para mostrar los numeros que se ingresaron en la pila haciendo una comparacion con la clase stack
// propia del c++ solo como comprobacion de una correcta implementacion, tambien usa lamndas

int main() {
	
	int dato = 0;
	int suma = 0;
	bool continuar = true;	

	// usando clase Pila
	Pila<int>* pila = new Pila<int>();
	
	while (continuar)
	{		
		std::cout << "\n Ingrese un numero: ";
		dato = Validacion::ingresar_DatosEnteros();
		pila->push(dato);
		auto sumaLambda = [&suma](int dato) {suma += dato; };
		sumaLambda(dato);
		std::cout << "\n La suma es: " << suma << std::endl;
		if (continuar) {
			std::cout << "\nDesea continuar? (1)Si (0)No: ";
			continuar = Validacion::ingresar_DatosEnteros();			
		}
	}
	
	std::cout << "\nLa Pila ingresada usando una Clase Pila Generda por Nosotros: " << std::endl;
	
	auto mostrarPila = [](Pila<int>* pila) {
		while (!pila->isEmpty()) {
			std::cout << "\t---" << std::endl;
			std::cout << "\t|" << pila->pop() << "|" << std::endl;
		}
	};

	std::cout << "\nLa cantidad de elementos de la pila es: " << pila->size() << std::endl;
	mostrarPila(pila);


	system("pause");
	
	return 0;
}