#ifndef TETRIS_H
#define TETRIS_H

#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>

class Tetris
{
private:
    int filas;
    int columnas;
    std::vector<std::vector<char>> tablero;

public:
	Tetris();
	Tetris(int numRows, int numCols);
	bool hayEspacioVacio(int fila, int columna, int longitud, bool &gameOver);
	bool hayEspacioHorizontal(int fila, int columna, int longitud, bool derecha);
	void coincidenPalabras(int fila, int columna, std::string palabra);
	void aumentarPuntaje(int aumento);
	void colocarPalabra(int fila, int columna, std::string palabra);
	void borrarPalabra(int fila, int columna, std::string palabra);
	void imprimirTablero();
	void limpiar();
};

#endif