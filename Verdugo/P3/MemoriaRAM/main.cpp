#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <fstream> 
#include "ListaCircularDoble.cpp"
#include "NodoDoble.cpp"
#include "Menu.h"

#define DIV 1024

void recuperarMemoria();
void guardarEnArchivo(const std::string& filename, const std::string& content);  // Declaración de la función

int main(int argc, char** argv[]) {
    std::string opcion;

    do {
        opcion = Menu::correrMenu();

        system("cls");

        if (opcion == "Recuperar datos de la memoria RAM y guardar en archivo .txt") {
            recuperarMemoria();
        }

        if (opcion == "Salir del Programa") {

        }
        system("PAUSE");
    } while (opcion != "Salir del Programa");

    return 0;
}

void recuperarMemoria() {
    MEMORYSTATUSEX statex;

    statex.dwLength = sizeof(statex);

    GlobalMemoryStatusEx(&statex);

    std::string content = "Hay un " + std::to_string(statex.dwMemoryLoad) + " por ciento de memoria en uso.\n" +
                      "Hay " + std::to_string(statex.ullTotalPhys / DIV) + " Kbytes totales de memoria física.\n" +
                      "Hay " + std::to_string(statex.ullAvailPhys / DIV) + " Kbytes libres de memoria física.\n" +
                      "Hay " + std::to_string(statex.ullTotalPageFile / DIV) + " Kbytes totales de archivo de paginación.\n" +
                      "Hay " + std::to_string(statex.ullAvailPageFile / DIV) + " Kbytes libres de archivo de paginación.\n" +
                      "Hay " + std::to_string(statex.ullTotalVirtual / DIV) + " Kbytes totales de memoria virtual.\n" +
                      "Hay " + std::to_string(statex.ullAvailVirtual / DIV) + " Kbytes libres de memoria virtual.\n" +
                      "Hay " + std::to_string(statex.ullAvailExtendedVirtual / DIV) + " Kbytes libres de memoria extendida.\n";

    guardarEnArchivo("info_memoria.txt", content);  // Llamada a la función para guardar en archivo
}

void guardarEnArchivo(const std::string& filename, const std::string& content) {
    std::ofstream outputFile(filename);  // Abre el archivo para escritura

    if (outputFile.is_open()) {
        outputFile << content;  // Escribe el contenido en el archivo
        outputFile.close();     // Cierra el archivo
        std::cout << "Información guardada en " << filename << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
    }
}
