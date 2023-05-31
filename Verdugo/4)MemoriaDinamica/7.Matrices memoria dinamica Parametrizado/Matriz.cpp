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
Matriz::Matriz(){
}
Matriz::Matriz(int **matriz, int dim ){
	this->matriz=matriz;
	this->dim=dim;
}
int Matriz::getDim(){
	return dim;
}
void Matriz::setDim(int dim){
	this->dim=dim;
}
int** Matriz::getMatriz(){
	return matriz;
}
void Matriz::setMatriz(int **matriz1){
	this-> matriz=matriz;
}


