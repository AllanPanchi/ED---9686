/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
			 Allan Panchi
			 Sebastian Verdugo
			 Alejandro Andrade
Fecha de inicio: 12/05/2023
Fecha de modificación: 22/05/2023

Templates implementados en C++
*/

#include "template.h"

// Definición
template <typename T>
Calculadora<T>::Calculadora(T n1, T n2) : num1(n1), num2(n2) {};

template <typename T>
void Calculadora<T>::operaciones() {
    std::cout << "Numeros: " << num1 << " y " << num2 << std::endl;
    std::cout << num1 << " + " << num2 << " = " << suma() << std::endl;
    std::cout << num1 << " - " << num2 << " = " << resta() << std::endl;
    std::cout << num1 << " * " << num2 << " = " << producto() << std::endl;
    std::cout << num1 << " / " << num2 << " = " << division() << std::endl;
}

template <typename T>
T Calculadora<T>::suma() { return num1 + num2; }

template <typename T>
T Calculadora<T>::resta() { return num1 - num2; }

template <typename T>
T Calculadora<T>::producto() { return num1 * num2; }

template <typename T>
T Calculadora<T>::division() { return num1 / num2; }
