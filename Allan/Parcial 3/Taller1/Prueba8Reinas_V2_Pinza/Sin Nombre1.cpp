#include <iostream>
#include <cstdlib>
#include <ctime>

const int n = 8;  // Tamaño del tablero
const int numPeones = 4; // Número de peones a colocar

struct Peon {
    int fila;
    int columna;
};

bool seAmenazan(const Peon& peon1, const Peon& peon2) {
    return (peon1.fila == peon2.fila) || (peon1.columna == peon2.columna);
}

int main() {
    srand(time(0));

    Peon peones[numPeones];

    // Generar posiciones aleatorias para los peones
    for (int i = 0; i < numPeones; i++) {
        peones[i].fila = rand() % n;
        peones[i].columna = rand() % n;
    }

    // Imprimir las posiciones de los peones
    std::cout << "Posiciones de los peones:" << std::endl;
    for (int i = 0; i < numPeones; i++) {
        std::cout << "Peon " << i + 1 << ": Fila " << peones[i].fila << ", Columna " << peones[i].columna << std::endl;
    }

    // Verificar si los peones se amenazan mutuamente
    bool amenaza = false;
    for (int i = 0; i < numPeones; i++) {
        for (int j = i + 1; j < numPeones; j++) {
            if (seAmenazan(peones[i], peones[j])) {
                std::cout << "Peon " << i + 1 << " y Peon " << j + 1 << " se amenazan mutuamente." << std::endl;
                amenaza = true;
            }
        }
    }

    if (!amenaza) {
        std::cout << "Los peones no se amenazan mutuamente." << std::endl;
    }

    return 0;
}

