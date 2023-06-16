/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
          Allan Panchi
          Sebastian Verdugo
          Alejandro Andrade
Fecha de inicio: 20/05/2023
Fecha de modificación: 21/05/2023

Recursividad: Operaciones con matrices
*/
#include <iostream>
#include "Operaciones.h"

void Operaciones::sumarMatriz(int** mat1, int** mat2, int** matR, int f, int c) {
    if ((f >= 0) && (c >= 0)) {
	    *(*(matR + f) + c) = *(*(mat1 + f) + c) + *(*(mat2 + f) + c);
    	sumarMatriz(mat1, mat2, matR, f-1, c);
	    sumarMatriz(mat1, mat2, matR, f, c-1);
    }
}

void Operaciones::multiplicacionDeMatrices(int** mat1, int** mat2, int** matR, int f, int c) {
    if ((f >= 0) && (c >= 0)) {
        for (int i = 0; i < 3; i++) {
            *(*(matR + f) + c) += *(*(mat1 + f) + i) * *(*(mat2 + i) + c);
        }
        multiplicacionDeMatrices(mat1, mat2, matR, f-1, c);
        multiplicacionDeMatrices(mat1, mat2, matR, f, c-1);
    }
}