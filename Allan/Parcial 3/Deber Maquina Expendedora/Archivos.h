#include <iostream>
#include <fstream>

class Archivos
{
public:
    Archivos();
    ~Archivos();
    void escribirArchivo(std::string, std::string);
    void leerArchivo(std::string);
    void sobreescribirArchivo(std::string, std::string);
};