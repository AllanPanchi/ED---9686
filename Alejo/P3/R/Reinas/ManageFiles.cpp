#include "ManageFiles.h"
#include <fstream>

void ManageFiles::WriteFile(const std::string& nombreArchivo, std::string cadena) {
    std::ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        archivo.write(cadena.c_str(), cadena.size());
        archivo.close();
        std::cout << "Archivo sobrescrito exitosamente." << std::endl;
    } else {
        std::cout << "No se pudo abrir el archivo para sobrescribir." << std::endl;
    }
        
}

std::string ManageFiles::ReadFile(std::string nombreArchivo) {
    std::ifstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        std::string cadena;
        std::string contenido;

        while (!archivo.eof()) {
            getline(archivo, cadena);
            contenido += cadena + "\n";
        }

        archivo.close();
        std::cout << "Archivo le\xA1"<<"do exitosamente." << std::endl;
        return contenido;
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }
    return "";
}