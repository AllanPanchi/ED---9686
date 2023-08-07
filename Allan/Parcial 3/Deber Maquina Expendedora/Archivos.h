#include <iostream>
#include <vector>
#include "Maquina.cpp"
#include <fstream>

class Archivos
{
public:
    Archivos();
    ~Archivos();
    void escribirArchivoProducto(const std::string, const std::vector<Producto>& productos);
    void leerArchivo(std::string);
    void sobreescribirArchivo(std::string, std::string);
};