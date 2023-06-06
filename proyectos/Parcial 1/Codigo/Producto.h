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
<<<<<<< HEAD
        float getPrecio()const;

<<<<<<< HEAD
        void setFechaElaboracion(const Fecha& fechaElaboracion);
        Fecha getFechaElaboracion() const;
=======
         void setFechaElaboracion(Fecha<T>* fechaElaboracion);
      Fecha<T>* getFechaElaboracion() const;
>>>>>>> 65089d56c9938e0541ec920da79b50f860c77b4a

        void setFechaCaducidad(Fecha<T>* fechaCaducidad);
    Fecha<T>* getFechaCaducidad() const;

        Fecha getfechaElaboracion();
        Fecha getfechaCaducidad();

        Fecha setfechaElaboracion(float fechaElaboracion);
        Fecha getfechaElaboracion();
=======
        float getPrecio();

        void setFechaElaboracion(FechaConcreta fechaElaboracion);
        FechaConcreta getFechaElaboracion();

        void setFechaCaducidad(FechaConcreta fechaCaducidad);
        FechaConcreta getFechaCaducidad();

        void toString();
>>>>>>> 4e0e3b027318c07b611a60f78a6140269f183889
};
