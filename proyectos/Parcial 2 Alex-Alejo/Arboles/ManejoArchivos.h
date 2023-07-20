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