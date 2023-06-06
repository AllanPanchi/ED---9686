#pragma once
#include <iostream>
#include "Producto.h"
#include "Fecha.h"

void Producto::setCodigo(int codigo) {
    this->codigo = codigo;
}

int Producto::getCodigo() {
    return codigo;
}

void Producto::setNombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Producto::getNombre() {
    return nombre;
}

void Producto::setPrecio(float precio) {
    this->precio = precio;
}

float Producto::getPrecio() {
    return precio;
}

FechaConcreta Producto::getFechaElaboracion() {
    return this->fechaElaboracion;
}

FechaConcreta Producto::getFechaCaducidad() {
    return this->fechaCaducidad;
}

void Producto::setFechaElaboracion(FechaConcreta fechaElaboracion) {
    this->fechaElaboracion = fechaElaboracion;
}

void Producto::setFechaCaducidad(FechaConcreta fechaCaducidad) {
    this->fechaCaducidad = fechaCaducidad;
}

void Producto::toString() {
    std::cout << "Codigo: " << this->codigo << std::endl;
    std::cout << "Nombre: " << this->nombre << std::endl;
    std::cout << "Precio: " << this->precio << std::endl;
    std::cout << "Fecha de elaboracion: "; this->fechaElaboracion.print();
    std::cout << "Fecha de caducidad: "; this->fechaCaducidad.print();
}