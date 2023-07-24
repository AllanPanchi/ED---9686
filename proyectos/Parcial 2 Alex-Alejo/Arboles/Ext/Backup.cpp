#include "Backup.h"

//Copiar un archivo
/**
 * @brief Copia un archivo de origen a un archivo de destino
 * 
 * @param origen 
 * @param destino 
 * @return true 
 * @return false 
 */
bool Backup::copiarArchivo(const std::string& origen,const std::string& destino)
{
    std::ifstream archivoEntrada(origen.c_str(),std::ios::binary);
    std::ofstream archivoSalida(destino.c_str(),std::ios::binary);
    if (!archivoEntrada) {
        std::cerr << "Error abriendo el archivo de origen: " << origen << std::endl;
        return false;
    }

    if (!archivoSalida) {
        std::cerr << "Error abriendo el archivo de destino: " << destino << std::endl;
        return false;
    }

    // Copiar el contenido del archivo de origen al archivo de destino
    archivoSalida << archivoEntrada.rdbuf();

    if (archivoEntrada.fail() || archivoSalida.fail()) {
        std::cerr << "Error al copiar el contenido del archivo." << std::endl;
        return false;
    }

    std::cout << "Archivo copiado exitosamente de " << origen << " a " << destino << std::endl;
    return true;
}