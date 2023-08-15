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

void fragmentar(){

    std::string dumpFileName = "memory_dump.dmp";
    std::string outputFolderPath = "fragments"; // Nombre de la carpeta donde se guardarán los fragmentos

    // Crear la carpeta de salida si no existe
    CreateDirectory(outputFolderPath.c_str(), NULL);

    // Tamaño de fragmento en bytes (ajústalo según tus necesidades)
    const std::streamsize chunkSize = 75000;

    std::ifstream dumpFile(dumpFileName, std::ios::binary);

    if (!dumpFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo de volcado de memoria." << std::endl;
        return;
    }

    std::vector<char> chunk(chunkSize);

    int fragmentCounter = 0;

    // Leer y procesar cada fragmento
    while (dumpFile.read(chunk.data(), chunkSize)) {
        // Generar un nombre único para cada archivo de fragmento
        std::string fragmentFileName = outputFolderPath + "/fragment_" + std::to_string(fragmentCounter) + ".txt";

        // Abrir un archivo de texto para escribir el fragmento
        std::ofstream fragmentFile(fragmentFileName);
        if (fragmentFile.is_open()) {
            // Escribir el contenido del fragmento en el archivo de texto
            for (char byte : chunk) {
                fragmentFile << byte;
            }
            fragmentFile.close();
            std::cout << "Fragmento " << fragmentCounter << " guardado en " << fragmentFileName << std::endl;
        } else {
            std::cerr << "No se pudo crear el archivo de fragmento." << std::endl;
        }

        fragmentCounter++;
    }

    dumpFile.close();

    std::cout << "Procesamiento de fragmentos completado." << std::endl;
}

void convertir(){

    std::string dumpFileName = "memory_dump.dmp";
    const std::streamsize chunkSize = 1024;

    std::ifstream dumpFile(dumpFileName, std::ios::binary);

    if (!dumpFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo de volcado de memoria." << std::endl;
        
    }

    std::vector<char> chunk(chunkSize);
    
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

void abrirArchivoEnSublimeText(const char* fileName) {
    // Abrir el archivo en Sublime Text usando el comando "subl"
    char command[100];
    snprintf(command, sizeof(command), "subl %s", fileName);
    system(command);
}

int main (){
    
    std::cout << "Volcado de memoria" << std::endl;
    volcadoDeMemoria();
    std::cout << "Abriendo archivo txt" << std::endl;
    abrirArchivoEnSublimeText("memory_dump.dmp");
    system("Pause");
    std::cout << "Fragmentar" << std::endl;
    fragmentar();
    std::cout << "Convertir" << std::endl;
    convertir();
    std::cout << "Abriendo archivo txt" << std::endl;
    abrirArchivoEnSublimeText("readable_dump.txt");
    system("Pause");
    std::cout << "Generar archivo limpio" << std::endl;
    generarArchivoLimpio();
    std::cout << "Abriendo archivo txt" << std::endl;
    abrirArchivoEnSublimeText("clean_dump.txt");
    std::cout << "Saliendo..." << std::endl;

    return 0;
}