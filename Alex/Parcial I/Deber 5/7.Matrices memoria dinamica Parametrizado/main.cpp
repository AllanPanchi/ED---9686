/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
			 Allan Panchi
			 Sebastian Verdugo
			 Alejandro Andrade
Fecha de inicio: 19/05/2023
Fecha de modificación: 22/05/2023

Memoria Dinamica en una matriz, uso de punteros y templates  
*/



#include <iostream>
#include "Matriz.h"
#include "Operaciones.h"

int ingresar(const char* msj);
void iniciar(int);


int ingresar(const char* msj){
	int dim;
	printf("\n%s\n",msj);
	scanf("%d",&dim);
	return dim;
}



template<typename T>
void iniciar(int  dim){
	/*int pot;
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

	Matriz<T> matriz1(nullptr, dim);
	Operaciones<T> operaciones1(matriz1);
	operaciones1.segmentar();
	operaciones1.encerar();
	operaciones1.imprimir();
}

int main(int argc, char** argv) {
	int dim;
	dim=ingresar("Ingrese la dimension de la matriz");
	iniciar<int>(dim);
	
	return 0;
}