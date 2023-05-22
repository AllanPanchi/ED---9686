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

Memoria Dinamica: Operaciones con matrices
*/

#include <iostream>
#include "Matriz.h"
#include "Operaciones.h"
int ingresar(char *);
int ingresar(char *msj){
	int dim;
	printf("\n%s\n",msj);
	scanf("%d",&dim);
	return dim;
}
void iniciar(int);
void iniciar(int  dim){
	int pot;
	int **mR=nullptr;
	int **m1=nullptr;
	int **m2=nullptr;
	Matriz matriz1(m1, dim);
	Operaciones operaciones1(matriz1);
	operaciones1.segmentar();
	operaciones1.encerar();
	operaciones1.imprimir();
	/*
	m1=operaciones.generar();
	m2=operaciones.generar();
	operaciones.imprimir(m1);
	operaciones.imprimir(m2);*/
}
int main(int argc, char** argv) {
	int dim;
	dim=ingresar("Ingrese la dimension de la matriz");
	iniciar(dim);
	
	return 0;
}