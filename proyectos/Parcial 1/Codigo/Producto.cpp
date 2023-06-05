#pragma once
#include <iostream>
#include "Producto.h"
#include "Fecha.h"


template<typename T>
void Producto<T>::setCodigo(T codigo) {
    this->codigo = codigo;
}

template<typename T>
T Producto<T>::getCodigo() const {
    return codigo;
}

template<typename T>
void Producto<T>::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

template<typename T>
std::string Producto<T>::getNombre() const {
    return nombre;
}

template<typename T>
void Producto<T>::setPrecio(float precio) {
    this->precio = precio;
}

template<typename T>
float Producto<T>::getPrecio() const {
    return precio;
}

template<typename T>
Fecha Producto<T>::getfechaElaboracion() {
    return fechaElaboracion;
}

template<typename T>
Fecha Producto<T>::getfechaCaducidad() {
    return fechaCaducidad;
}

template<typename T>
void Producto<T>::setfechaElaboracion(const Fecha& fechaElaboracion) {
    this->fechaElaboracion = fechaElaboracion;
}

template<typename T>
void Producto<T>::setfechaCaducidad(const Fecha& fechaCaducidad) {
    this->fechaCaducidad = fechaCaducidad;
}