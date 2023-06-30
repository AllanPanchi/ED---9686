#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void ordenarNumerosAleatorios() {
    // Inicializar la semilla del generador de números aleatorios
    srand(time(0));

    const int cantidadNumeros = 20;
    int numeros[cantidadNumeros];

    // Generar 20 números aleatorios
    std::cout << "20 números aleatorios:" << std::endl;
    for (int i = 0; i < cantidadNumeros; ++i) {
        numeros[i] = rand() % 100;
        std::cout << numeros[i] << " ";
    }
    // std::cout << std::endl;

    // Ordenar los números
    std::sort(numeros, numeros + cantidadNumeros);

    // Mostrar los números ordenados
    std::cout << "Números ordenados:" << std::endl;
    for (int i = 0; i < cantidadNumeros; ++i) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    ordenarNumerosAleatorios();

    return 0;
}

