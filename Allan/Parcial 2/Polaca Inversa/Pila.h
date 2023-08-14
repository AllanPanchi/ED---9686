#pragma once
#include "Nodo.cpp"

using namespace std;

template <typename T>

class Pila {
private:
	Nodo<T>* primero;
	Nodo<T>* actual;
	int ingresos;

public:

	Pila();

	bool PilaVacia();
	
	Nodo<T>* getPrimero();
	
	void setPrimero(Nodo<T>* _primero);
	
	Nodo<T>* getActual();
	
	void setActual(Nodo<T>* _actual);
	
	int getIngresos();
	
	void setIngresos(int _ingresos);
	
	void Push(T valor);
	
	void Pop();
	
	void mostrarPila();
	
	void mostrarNotacion();

	void mostrarIngreso();
	
		//Constructor
	// Pila() {
	// 	primero = nullptr;
	// 	actual = nullptr;
	// 	ingresos = 0;
	// }

	//Pila Vacia
	// bool PilaVacia() {
	// 	return (primero == nullptr && ingresos == 0);
	// }

	//Metodos Get - Set
	// Nodo<T>* getPrimero() {
	// 	return primero;
	// }

	// void setPrimero(Nodo<T>* _primero) {
	// 	primero = _primero;
	// }

	// Nodo<T>* getActual() {
	// 	return actual;
	// }

	// void setActual(Nodo<T>* _actual) {
	// 	actual = _actual;
	// }

	// int getIngresos() {
	// 	return ingresos;
	// }

	// void setIngresos(int _ingresos) {
	// 	ingresos = _ingresos;
	// }

	//Ingresar datos a Pila
	// void Push(T valor) {
	// 	Nodo<T>* nuevo = new Nodo<T>(valor);

	// 	if (PilaVacia()) {
	// 		actual = nuevo;
	// 	}
	// 	else {
	// 		nuevo->setSiguiente(primero);
	// 	}
	// 	primero = nuevo;
	// }

	// Eliminar datos a Pila
	// void Pop() {
	// 	if (!PilaVacia()) {
	// 		Nodo<T>* temp;
	// 		temp = primero;
	// 		primero = primero->getSiguiente();
	// 		free(temp);
	// 	}
	// }

	// Mostrar datos a Pila
	// void mostrarPila() {
	// 	Nodo<T>* tmp = primero;
	// 	while (tmp) {
	// 		cout << tmp->getValor() << "-->";
	// 		tmp = tmp->getSiguiente();
	// 	}
	// 	cout << "NULL\n";
	// }

	// //Mostrar expresion algebraica
	// void mostrarNotacion(){
	// 	Nodo<T>* tmp = primero;
	// 	while (tmp) {
	// 		cout << tmp->getValor() << " ";
	// 		tmp = tmp->getSiguiente();

	// 	}
	// 	cout << endl;
	// }


	// //Mostrar expresion algebraica invertida
	// void mostrarIngreso(){
	// 	Pila<T> copia;
	// 	Nodo<T>* tmp = primero;

	// 	while (tmp) {
	// 		copia.Push(tmp->getValor());
	// 		tmp = tmp->getSiguiente();
	// 	}
	// 	tmp = copia.getPrimero();
	// 	while (tmp) {
	// 		cout << tmp->getValor() << " ";
	// 		tmp = tmp->getSiguiente();
	// 	}
	// 	cout << endl;
	// }

};

