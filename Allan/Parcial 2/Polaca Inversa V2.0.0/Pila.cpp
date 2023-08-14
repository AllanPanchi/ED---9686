#include "Pila.h"

template <typename T>
	Pila<T>::Pila() {
		primero = nullptr;
		actual = nullptr;
		ingresos = 0;
	}

template <typename T>
    bool Pila<T>::PilaVacia() {
        return (primero == nullptr && ingresos == 0);
    }

template <typename T>
    Nodo<T>* Pila<T>::getPrimero() {
        return primero;
    }

template <typename T>
    void Pila<T>::setPrimero(Nodo<T>* _primero) {
        primero = _primero;
    }

template <typename T>
    Nodo<T>* Pila<T>::getActual() {
        return actual;
    }

template <typename T>
    void Pila<T>::setActual(Nodo<T>* _actual) {
        actual = _actual;
    }

template <typename T>
    int Pila<T>::getIngresos() {
        return ingresos;
    }  

template <typename T>
    void Pila<T>::setIngresos(int _ingresos) {
        ingresos = _ingresos;
    }

template <typename T>
    void Pila<T>::Push(T valor) {
		Nodo<T>* nuevo = new Nodo<T>(valor);

		if (PilaVacia()) {
			actual = nuevo;
		}
		else {
			nuevo->setSiguiente(primero);
		}
		primero = nuevo;
    }

template <typename T>
    void Pila<T>::Pop() {
		if (!PilaVacia()) {
			Nodo<T>* temp;
			temp = primero;
			primero = primero->getSiguiente();
			free(temp);
		}
	}

template <typename T>
    void Pila<T>::mostrarPila() {
		Nodo<T>* tmp = primero;
		while (tmp) {
			std::cout << tmp->getValor() << "-->";
			tmp = tmp->getSiguiente();
		}
		std::cout << "NULL\n";
	}

template <typename T>
	void Pila<T>::mostrarNotacion(){
		Nodo<T>* tmp = primero;
		while (tmp) {
			std::cout << tmp->getValor() << " ";
			tmp = tmp->getSiguiente();
		}
		std::cout << std::endl;
	}

template <typename T>
	void Pila<T>::mostrarIngreso(){
		Pila<T> copia;
		Nodo<T>* tmp = primero;

		while (tmp) {
			copia.Push(tmp->getValor());
			tmp = tmp->getSiguiente();
		}
		tmp = copia.getPrimero();
		while (tmp) {
			std::cout << tmp->getValor() << " ";
			tmp = tmp->getSiguiente();
		}
		std::cout << std::endl;

	}