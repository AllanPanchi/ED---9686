#ifndef PRODUCTO_H
#define PRODUCTO_H

#include "FechaConcreta.h"
#include <iostream>
#include <string>

class Producto {
    private:

        int codigo;
        std::string nombre;
        float precio;
        FechaConcreta fechaElaboracion;
        FechaConcreta fechaCaducidad;

    public:
        // Producto(int codigo, std::string nombre, float precio,const FechaConcreta& FechaElaboracion,const FechaConcreta& FechaCaducidad);
        // Producto();
        // ~Producto();

        // void setCodigo(int codigo);
        // int getCodigo();

        // void setNombre(std::string nombre);
        // std::string getNombre();

        // void setPrecio(float precio);
        // float getPrecio();

        // void setFechaElaboracion(const FechaConcreta&);
        // FechaConcreta getFechaElaboracion();

        // void setFechaCaducidad(const FechaConcreta&);
        // FechaConcreta getFechaCaducidad();

        // void toString();

        Producto() : codigo(0), nombre(""), precio(0.0) {}

        ~Producto() {}

        void setCodigo(int codigo) {
            this->codigo = codigo;
        }

        int getCodigo() {
            return codigo;
        }

        void setNombre(std::string nombre) {
            this->nombre = nombre;
        }

        std::string getNombre() {
            return nombre;
        }

        void setPrecio(float precio) {
            this->precio = precio;
        }

        float getPrecio() {
            return precio;
        }

        FechaConcreta getFechaElaboracion() {
            return this->fechaElaboracion;
        }

        FechaConcreta getFechaCaducidad() {
            return this->fechaCaducidad;
        }

        void setFechaElaboracion(const FechaConcreta& fechaElaboracion) {
            this->fechaElaboracion = fechaElaboracion;
        }

        void setFechaCaducidad(const FechaConcreta& fechaCaducidad) {
            this->fechaCaducidad = fechaCaducidad;
        }

        void toString() {
            std::cout << "Codigo: " << this->codigo << std::endl;
            std::cout << "Nombre: " << this->nombre << std::endl;
            std::cout << "Precio: " << this->precio << std::endl;
            std::cout << "Fecha de elaboracion: "; this->fechaElaboracion.print();
            std::cout << "Fecha de caducidad: "; this->fechaCaducidad.print();
        }
};

#endif  // PRODUCTO_H