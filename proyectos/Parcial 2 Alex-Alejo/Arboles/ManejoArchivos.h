/**
 * @file ManejoArchivos.h
 * @author Alejandro Andrade - Alex Trejo
 * @brief 
 * @version 1.0
 * @date 2023-07-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include "Lista.cpp"

class ManejoArchivos
{
public:

    static void guardarPersonas(const std::string& nombreArchivo, Lista<Empleado>& lista);

    static void cargarPersonas(const std::string& nombreArchivo, Lista<Empleado>& lista);

    static void guardarRegistros(const std::string& nombreArchivo, Lista<Registro>& lista);

    static void cargarRegistros(const std::string& nombreArchivo, Lista<Registro>& lista);

};