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