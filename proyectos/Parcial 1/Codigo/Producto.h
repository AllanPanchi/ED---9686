#pragma once
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
        void setCodigo(int codigo);
        int getCodigo();

        void setNombre(std::string nombre);
        std::string getNombre();

        void setPrecio(float precio);
        float getPrecio();

        void setFechaElaboracion(FechaConcreta fechaElaboracion);
        FechaConcreta getFechaElaboracion();

        void setFechaCaducidad(FechaConcreta fechaCaducidad);
        FechaConcreta getFechaCaducidad();

        void toString();
};
