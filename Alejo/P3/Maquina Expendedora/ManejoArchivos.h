#include <iostream>
#include "Lista.cpp"
#include "Maquina.cpp"

class ManejoArchivos
{
public:

    static void guardarProductos(const std::string& nombreArchivo, Lista<Producto>& lista);

    static void cargarProductos(const std::string& nombreArchivo, Lista<Producto>& lista);

    static void guardarMaquina(const std::string& nombreArchivo, Maquina& maquina);

    static void cargarMaquina(const std::string& nombreArchivo, Maquina& maquina);

};