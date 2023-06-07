#pragma once
#include <string>
#include <iostream>
#include "ValDatos.h"
#include "Producto.h"

class FuncionesMenu
{
    public:
        // static Producto insertarProducto(ListaProducto lista);
        

        static Producto insertarProducto()
        {
            Producto producto;
            producto.setCodigo(ValidarDatos::generarCodigo());
            std::cout << "Ingrese el nombre del producto: ";
            producto.setNombre(ValidarDatos::validarString());
            std::cout << "Ingrese el precio del producto: ";
            producto.setPrecio(ValidarDatos::validarFloat());
            std::cout << "Ingrese el a\xf1o de elaboracion del producto" << std::endl;
            producto.setAnioElaboracion(ValidarDatos::validarEntero());
            std::cout << "Ingrese el a\xf1o de vencimiento del producto: " << std::endl;
            producto.setAnioCaducidad(ValidarDatos::validarEntero());

            return producto;
        }
        

};