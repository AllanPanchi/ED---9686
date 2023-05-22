#include "Operaciones.h"


void Operaciones::cifrarMatriz(int** mat1, int** mat2, int** matR, int f, int c) {
    if ((f >= 0) && (c >= 0)) {
	    *(*(matR + f) + c) = *(*(mat1 + f) + c) + *(*(mat2 + f) + c);
    	cifrarMatriz(mat1, mat2, matR, f-1, c);
	    cifrarMatriz(mat1, mat2, matR, f, c-1);
    }
}
void Operaciones::multiplicacionDeMatrices(int** mat1, int** mat2, int** matR, int f, int c) {
    if ((f >= 0) && (c >= 0)) {
        *(*(matR + f) + c) = *(*(mat1 + f) + c) * *(*(mat2 + c) + f);
        multiplicacionDeMatrices(mat1, mat2, matR, f-1, c);
        multiplicacionDeMatrices(mat1, mat2, matR, f, c-1);
    }
}
