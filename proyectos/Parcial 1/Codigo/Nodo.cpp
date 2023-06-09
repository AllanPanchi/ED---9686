/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Allan Panchi
                Alex Trejo 
                Sebastian Verdugo
Fecha de inicio: 02/05/2023
Fecha de modificación: 08/06/2023

Proyecto sobre registros utlizando listas doblemente enlazadas
*/
#include "Nodo.h"

Nodo::Nodo(Producto product, Nodo *sig, Nodo *ant){
    this->producto = product;
    this->siguiente = sig;
    this->anterior = ant;
}

void Nodo::setProducto(Producto product){
	this->producto = product;
}

Producto Nodo::getProducto(){
	return this->producto;
}

void Nodo::setSiguiente(Nodo *sig){
	this->siguiente=sig;
}

Nodo* Nodo::getSiguiente(){
	return this->siguiente;
}

void Nodo::setAnterior(Nodo *ant){
    this->anterior=ant;
}

Nodo* Nodo::getAnterior(){
    return this->anterior;
}