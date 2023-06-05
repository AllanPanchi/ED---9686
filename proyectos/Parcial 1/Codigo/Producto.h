#pragma once
#include <iostream>
#include <string>
#include "Fecha.h"

template <typename T>
class Producto: public IProducto<T> {
    private:
        T codigo;
        std::string nombre;
        float precio;
        
        Fecha fechaElaboracion;
        Fecha fechaCaducidad;
    

    public:
        void setCodigo(T codigo) override;
        T getCodigo()const override;

        void setNombre(const std::string& nombre) override;
        std::string getNombre()const override;

        void setPrecio(float precio)override;
        float getPrecio()const override;

         void setFechaElaboracion(const Fecha& fechaElaboracion);
        Fecha getFechaElaboracion() const;

        void setFechaCaducidad(const Fecha& fechaCaducidad);
        Fecha getFechaCaducidad() const;

        /*Fecha getfechaElaboracion();
        Fecha getfechaCaducidad();

        Fecha setfechaElaboracion(float fechaElaboracion);
        Fecha getfechaElaboracion();*/



        





};

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
void Producto<T>::setFechaElaboracion(const Fecha& fechaElaboracion) {
    this->fechaElaboracion = fechaElaboracion;
}

template<typename T>
Fecha Producto<T>::getFechaElaboracion() const {
    return fechaElaboracion;
}

template<typename T>
void Producto<T>::setFechaCaducidad(const Fecha& fechaCaducidad) {
    this->fechaCaducidad = fechaCaducidad;
}

template<typename T>
Fecha Producto<T>::getFechaCaducidad() const {
    return fechaCaducidad;
}