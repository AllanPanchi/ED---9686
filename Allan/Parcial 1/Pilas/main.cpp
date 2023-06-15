/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Allan Panchi
                Alex Trejo 
                Sebastian Verdugo
Fecha de inicio: 09/05/2023
Fecha de modificación: 09/06/2023

Proyecto sobre registros utlizando listas doblemente enlazadas
*/

#include "Pila.h"
#include "Validacion.h"
#include <iostream>
#include <stack>

using namespace std;

int main() {
	
	int dato = 0;
	int suma = 0;
	bool continuar = true;	

	// usando clase Pila
	Pila* pila = new Pila();
	// usando stack
	stack<int> pila2;
	
	while (continuar)
	{		
		cout << "\n Ingrese un numero: ";
		dato = Validacion::ingresar_DatosEnteros();
		pila->push(dato);
		pila2.push(dato);
		auto sumaLambda = [&suma](int dato) {suma += dato; };
		sumaLambda(dato);
		cout << "\n La suma es: " << suma << endl;
		if (continuar) {
			cout << "\nDesea continuar? (1)Si (0)No: ";
			continuar = Validacion::ingresar_DatosEnteros();			
		}
	}
	
	cout << "\nLa Pila ingresada usando una Clase Pila Generda por Nosotros: " << endl;
	
	auto mostrarPila = [](Pila* pila) {
		while (!pila->isEmpty()) {
			cout << "\t---" << endl;
			cout << "\t|" << pila->pop() << "|" << endl;
		}
	};
	mostrarPila(pila);

	cout << "\nLa Pila ingresada usando stack propia de C++: " << endl;
	auto mostrarPilaStack = [](stack<int> pila) {
		while (!pila.empty()) {
			cout << "\t---" << endl;
			cout << "\t|" << pila.top() << "|" << endl;
			pila.pop();
		}
	};
	
	mostrarPilaStack(pila2);

	
	return 0;
}