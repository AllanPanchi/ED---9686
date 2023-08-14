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
    const std::streamsize chunkSize = 16384;

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


void abrirArchivoEnSublimeText(const char* fileName) {
    // Abrir el archivo en Sublime Text usando el comando "subl"
    char command[100];
    snprintf(command, sizeof(command), "subl %s", fileName);
    system(command);
}

int main (){

    int opcion;
    bool salir=false;
    char respuesta;
    
    do{
        system("cls");
       
        std::cout << "Menu" << std::endl;
        std::cout << "1. Volcado de memoria" << std::endl;
        std::cout << "2. Fragmentar" << std::endl;
        std::cout << "3. Convertir" << std::endl;
        std::cout << "4. Generar archivo limpio" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;

             
        

         switch (opcion) {
            case 1:
                
                volcadoDeMemoria();

                std::cout << "¿Desea abrir el archivo en Sublime Text? (S/N): ";
                std::cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    abrirArchivoEnSublimeText("memory_dump.dmp");
                }
                
                break;
            case 2:
                fragmentar();
                               
                break;
            case 3:
                convertir();
                std::cout << "¿Desea abrir el archivo en Sublime Text? (S/N): ";
                std::cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    abrirArchivoEnSublimeText("readable_dump.txt");
                }
                
                break;
            case 4:
                generarArchivoLimpio();
                std::cout << "¿Desea abrir el archivo en Sublime Text? (S/N): ";
                std::cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    abrirArchivoEnSublimeText("clean_dump.txt");
                }
                
                break;
            case 5:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida" << std::endl;
                break;
        }

        if (opcion != 5) {
            system("pause");
        }


    }while(opcion != 5);



    /*

    do{
        system("cls");
        while(opcion < 1 || opcion > 5){
        std::cout << "Menu" << std::endl;
        std::cout << "1. Volcado de memoria" << std::endl;
        std::cout << "2. Fragmentar" << std::endl;
        std::cout << "3. Convertir" << std::endl;
        std::cout << "4. Generar archivo limpio" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese una opcion: ";
        std::cin >> opcion;
        system("cls");
        }

       
        switch (opcion)
    {   
        case 1:
            volcadoDeMemoria();
            break;
        case 2:
            fragmentar();
            
            break;
        case 3:
            convertir();
            
            break;
        case 4:
            generarArchivoLimpio();
            
            break;
        case 5:
            salir=true;
            break;
        default:
            break;
    }

    }while ( !salir);*/
       
    


    system("pause");
    return 0;


}