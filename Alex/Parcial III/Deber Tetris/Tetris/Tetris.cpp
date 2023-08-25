#include "Tetris.h"
void Tetris::limpiar()
{
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Tetris::Tetris() {
	filas = 0;
    columnas = 0;
}

Tetris::Tetris(int numRows, int numCols) : filas(numRows), columnas(numCols) {	
    puntaje = 0;
    tablero = std::vector<std::vector<char>>(numRows, std::vector<char>(numCols, ' '));
    
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            if (i == 0 || i == filas - 1 || j == 0 || j == columnas - 1) {
                tablero[i][j] = '|';
            } else {
                tablero[i][j] = ' ';
            }
        }
    }
}

bool Tetris::hayEspacioVacio(int fila, int columna, int longitud, bool &gameOver)
{
    for (int j = columna; j < columna + longitud; ++j)
    {
        if (tablero[fila + 1][j] != ' ')
        {
            if (tablero[fila + 1][j] == '-')
            {                // Para los bordes
                return false; // Es la ultima fila
            }
            else
            {
                if (fila == 1)
                {
                    gameOver = true; // Si está en el tope superior y ya no puede avanzar
                }
                return false; // Hay una palabra en esta posición
            }
        }
    }
    return true; // No hay palabras en la siguiente posicion
}

void Tetris::coincidenPalabras(int fila, int columna, std::string palabra) {
	bool coincide = true;
	
	for (int j = columna; j < columna + palabra.length(); ++j)
    {
        if (tablero[fila][j] != tablero[fila + 1][j])
        {
            coincide = false;
            break;
        }
    }
    
    if (coincide) {
    	borrarPalabra(fila, columna, palabra);
    	borrarPalabra(fila + 1, columna, palabra);
	}
    
}

bool Tetris::hayEspacioHorizontal(int fila, int columna, int longitud, bool derecha) {
	
	if (derecha) {
		if(tablero[fila][columna + longitud] == ' ') {
			return true;
		}	
	} else {
		if(tablero[fila][columna - 1] == ' ' ) {
			return true;
		}
	}

    return false; // hay palabras en la siguiente posicion
}

void Tetris::colocarPalabra(int fila, int columna, std::string palabra)
{
    for (int j = columna; j < columna + palabra.length(); ++j)
    {
        tablero[fila][j] = palabra[j - columna];
    }
}

void Tetris::borrarPalabra(int fila, int columna, std::string palabra)
{
    for (int j = columna; j < columna + palabra.length(); ++j)
    {
        tablero[fila][j] = (fila == 0) ? '-' : ' '; // Reemplazar por arrobas en la primera fila
    }
}

void Tetris::imprimirTablero()
{
	limpiar();
    for (int i = 0; i < filas; ++i)
    {
        for (int j = 0; j < columnas; ++j)
        {
            std::cout << tablero[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}