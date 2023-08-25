#include <Windows.h>
#include <DbgHelp.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <TlHelp32.h>



void volcadoDeMemoria(){
    HANDLE hFile = CreateFile("memory_dump.dmp", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hFile != INVALID_HANDLE_VALUE) {
        // Generar un volcado de memoria
        if (MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, MiniDumpWithFullMemory, NULL, NULL, NULL)) {
            printf("Volcado de memoria generado correctamente.\n");
        } else {
            printf("Error al generar el volcado de memoria.\n");
        }

        CloseHandle(hFile); // Cerrar el archivo después de escribir
    } else {
        printf("No se pudo crear el archivo de volcado de memoria.\n");
    }
}

void convertir(){

    std::string dumpFileName = "memory_dump.dmp";
    const std::streamsize chunkSize = 1024;

    std::ifstream dumpFile(dumpFileName, std::ios::binary);

    if (!dumpFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo de volcado de memoria." << std::endl;
        
    }

    std::vector<char> chunk(chunkSize);
     ////

    
    std::ofstream outputFile("readable_dump.txt");

    while (dumpFile.read(chunk.data(), chunkSize)) {
        for (char byte : chunk) {
            // Convertir el byte en su representación ASCII
            if (byte >= 32 && byte <= 126) {  // Caracteres legibles
                outputFile << byte;
            } else {
                outputFile << '.';  // Caracteres no legibles se representan como un punto
            }
        }
        outputFile << std::endl;
    }

    dumpFile.close();
    outputFile.close();

    std::cout << "Procesamiento de fragmentos y escritura en readable_dump.txt completado." << std::endl;

    std::string readableFileName = "readable_dump.txt";

    std::ifstream readableFile(readableFileName);

    if (!readableFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo legible." << std::endl;
       
    }

    /*std::string line;
    while (std::getline(readableFile, line)) {
        std::cout << line << std::endl;
    }*/

    readableFile.close();
}

void generarArchivoLimpio(){

    std::string readableFileName = "readable_dump.txt";
    std::string cleanFileName = "clean_dump.txt";

    std::ifstream readableFile(readableFileName);

    if (!readableFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo legible." << std::endl;
        
    }

    std::ofstream cleanFile(cleanFileName);

    if (!cleanFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo limpio para escribir." << std::endl;
        
    }

    std::string line;
    while (std::getline(readableFile, line)) {
        std::string filteredLine;

        for (char c : line) {
            if (c != '.') {
                filteredLine += c;
            }
        }

        cleanFile << filteredLine << std::endl;
    }

    readableFile.close();
    cleanFile.close();

    std::cout << "Procesamiento completado. El contenido limpio se guardo en " << cleanFileName << std::endl;
}

int main (){
            
    volcadoDeMemoria();
    convertir();
    generarArchivoLimpio();
                
    system("subl memory_dump.dmp");
    system("pause");
    system("readable_dump.txt");
    system("pause");
    system("clean_dump.txt");
    system("pause");

    return 0;

}