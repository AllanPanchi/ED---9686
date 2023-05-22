#include "Operaciones.h"

int sumarDigitos(int numero) {
    if (numero < 10) {
        return numero;
    } else {
        return sumarDigitos(numero / 10 + numero % 10);
    }
}

int sumarMatrizRecursivamente(int** punteroMatriz, int fila, int columna, int sumaParcial) {
    if (fila == 3 && columna == 3) {
        sumaParcial += *(*(punteroMatriz + fila) + columna);
        return sumarDigitos(sumaParcial);
    }

    sumaParcial += *(*(punteroMatriz + fila) + columna);
    
    if (columna == 3) {
        return sumarMatrizRecursivamente(punteroMatriz, fila + 1, 0, sumaParcial);
    }
    
    return sumarMatrizRecursivamente(punteroMatriz, fila, columna + 1, sumaParcial);
}

