#pragma once
#include <iostream>
#include <string>


template <typename T>
class Fecha;

template <typename T>
class Producto{
    private:
        T codigo;
        std::string nombre;
        float precio;
        
        Fecha<T>* fechaElaboracion;
        Fecha<T>* fechaCaducidad;
    

    public:
        void setCodigo(T codigo);
        T getCodigo()const;

        void setNombre(const std::string& nombre);
        std::string getNombre()const;

        void setPrecio(float precio);
        float getPrecio()const;

         void setFechaElaboracion(Fecha<T>* fechaElaboracion);
      Fecha<T>* getFechaElaboracion() const;

        void setFechaCaducidad(Fecha<T>* fechaCaducidad);
    Fecha<T>* getFechaCaducidad() const;

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
void Producto<T>::setFechaElaboracion(Fecha<T>* fechaElaboracion) {
    this->fechaElaboracion = fechaElaboracion;
}

template<typename T>
Fecha<T>* Producto<T>::getFechaElaboracion() const {
    return fechaElaboracion;
}

template<typename T>
void Producto<T>::setFechaCaducidad(Fecha<T>* fechaCaducidad) {
    this->fechaCaducidad = fechaCaducidad;
}

template<typename T>
Fecha<T>* Producto<T>::getFechaCaducidad() const {
    return fechaCaducidad;
}