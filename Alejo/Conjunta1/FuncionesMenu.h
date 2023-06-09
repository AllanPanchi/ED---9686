#pragma once
#include <string>
#include <iostream>
#include "ValDatos.h"
#include "Producto.h"

class FuncionesMenu
{
    public:

        static Producto insertarProducto()
        {
            Producto producto;
            std::string nombre;
            int fecha = 1000;
            float precio = 0.0;
            producto.setCodigo(ValidarDatos::generarCodigo());
            std::cout << "Ingrese el nombre del producto: ";
            nombre = ValidarDatos::validarNombre(nombre);            
            producto.setNombre(nombre);
            std::cout << "Ingrese el precio del producto: ";
            precio = ValidarDatos::validarFloat();
            precio = ValidarDatos::validarPrecio(precio);
            producto.setPrecio(precio);
            std::cout << "Ingrese el anio de elaboracion del producto: ";
            fecha = ValidarDatos::validarFecha(fecha);
            producto.setAnioElaboracion(fecha);
            std::cout << "Ingrese el anio de vencimiento del producto : ";
            fecha = ValidarDatos::validarFecha(fecha);
            producto.setAnioCaducidad(fecha);

            return producto;
        }

};