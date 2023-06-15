/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Nombre: Alejandro Andrade
Fecha de inicio: 22/05/2023
Fecha de modificación: 22/05/2023

Prueba 1, Cifrado con Recursividad
*/

#include "Operaciones.h"

int sumarDigitos(int numero) {
    if (numero < 10) {
        return numero;
    } else {
        return sumarDigitos(numero / 10 + numero % 10);
    }
}

int cifrarMatriz(int** matriz, int f, int c, int cifrado, int dim) {
    int dimension = (dim-1);
    if (f == dimension && c == dimension) {
        cifrado += *(*(matriz + f) + c);
        return sumarDigitos(cifrado);
    }

    cifrado += *(*(matriz + f) + c);
    
    if (c == dimension) {
        return cifrarMatriz(matriz, f + 1, 0, cifrado, dim);
    }
    
    return cifrarMatriz(matriz, f, c + 1, cifrado, dim);
}

