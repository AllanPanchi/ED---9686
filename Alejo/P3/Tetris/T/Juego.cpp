#include "Juego.h"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <fstream>

void Juego::ocultarCursor() {
	//Ocular el cursor de la consola
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false; // Oculta el cursor
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

Juego::Juego() {
	ocultarCursor();
	this->filas = 20 + 2;
    this->columnas = 10 + 2;
	this->tetris = Tetris(filas, columnas);;
}

std::string Juego::ingresarPalabra(){
    std::string palabra;
    std::cout << "Ingrese una palabra: ";
    std::cin >> palabra;
    return palabra;
}

void guardarPalabrasEnArchivo(const std::string& p1, const std::string& p2, const std::string& p3, const std::string& p4) {
    std::ofstream archivo("palabras.txt");
    if (archivo.is_open()) {
        archivo << p1 << std::endl;
        archivo << p2 << std::endl;
        archivo << p3 << std::endl;
        archivo << p4 << std::endl;
        archivo.close();
        std::cout << "Palabras guardadas en el archivo." << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo para guardar las palabras." << std::endl;
    }
}

std::vector<std::string> obtenerPalabrasDelArchivo() {
    std::ifstream archivo("palabras.txt");
    std::vector<std::string> palabras;
    std::string palabra;
    
    if (archivo.is_open()) {
        while (archivo >> palabra) {
            palabras.push_back(palabra);
        }
        archivo.close();
        
        if (!palabras.empty()) {
            return palabras;
        }
    } else {
        std::cerr << "No se pudo abrir el archivo de palabras." << std::endl;
    }
    
    return palabras;
}

void Juego::ejecutar() {
	srand(time(NULL));
	int intervaloActualizacion = 500; // 500 milisegundos
    bool gameOver = false;
    
    std::vector<std::string> palabra = obtenerPalabrasDelArchivo();
    
    auto tiempoUltimaActualizacion = std::chrono::high_resolution_clock::now();
	
    while (true)
    {
        int index = rand() % palabra.size();
        int posicionAleatoria = rand() % (columnas - palabra[index].length() - 1) + 1;
        int i = 1;
        bool hayColision = false;
        while (!hayColision)
        {
            auto tiempoActual = std::chrono::high_resolution_clock::now();
            auto duracionDesdeUltimaActualizacion = std::chrono::duration_cast<std::chrono::milliseconds>(tiempoActual - tiempoUltimaActualizacion).count();

            if (duracionDesdeUltimaActualizacion >= intervaloActualizacion)
            {
                tetris.borrarPalabra(i - 1, posicionAleatoria, palabra[index]);
                if (tetris.hayEspacioVacio(i, posicionAleatoria, palabra[index].length(), gameOver))
                {
                    tetris.colocarPalabra(i, posicionAleatoria, palabra[index]);
                }
                else
                {                	
                    tetris.colocarPalabra(i, posicionAleatoria, palabra[index]);
                    tetris.coincidenPalabras(i, posicionAleatoria, palabra[index]);
                    hayColision = true;
                }
                tetris.imprimirTablero();

                tiempoUltimaActualizacion = std::chrono::high_resolution_clock::now();
                i++;
            }

            if (_kbhit() && !hayColision)
            {                          // Verifica si una tecla ha sido presionada
                char tecla = _getch(); // Captura la tecla sin esperar a Enter
                if (tecla == 27)
                { // Si la tecla es Esc, sale del bucle
                    gameOver = false;
                    break;
                }
                else if (tecla == 75)
                { // Tecla de flecha izquierda (código ASCII 75)
                    if (tetris.hayEspacioHorizontal(i - 1, posicionAleatoria, palabra[index].length(), false))
                    {
                        tetris.borrarPalabra(i - 1, posicionAleatoria, palabra[index]);
                        posicionAleatoria--;
                        tetris.colocarPalabra(i - 1, posicionAleatoria, palabra[index]);
                    }
                }
                else if (tecla == 77)
                { // Tecla de flecha derecha (código ASCII 77)
                    if (tetris.hayEspacioHorizontal(i - 1, posicionAleatoria, palabra[index].length(), true))
                    { // Verificar si no está en el borde derecho
                        tetris.borrarPalabra(i - 1, posicionAleatoria, palabra[index]);
                        posicionAleatoria++;
                        tetris.colocarPalabra(i - 1, posicionAleatoria, palabra[index]);
                    }
                }
                else if (tecla == 80)
                { // Tecla de flecha abajo (código ASCII 80)
                    tetris.borrarPalabra(i - 1, posicionAleatoria, palabra[index]);
                    if (tetris.hayEspacioVacio(i, posicionAleatoria, palabra[index].length(), gameOver))
                    {
                        tetris.colocarPalabra(i, posicionAleatoria, palabra[index]);
                    }
                    else
                    {
                        tetris.colocarPalabra(i, posicionAleatoria, palabra[index]);
                        tetris.coincidenPalabras(i, posicionAleatoria, palabra[index]);
                        hayColision = true;
                    }
                    tetris.imprimirTablero();
                    tiempoUltimaActualizacion = std::chrono::high_resolution_clock::now();
                    i++;
                }

                tetris.imprimirTablero();
            }
        }

        if (gameOver)
        {
            tetris.imprimirTablero();
            std::cout << "El juego ha terminado" << std::endl;
            break;
        }
    }
    system("pause");
}