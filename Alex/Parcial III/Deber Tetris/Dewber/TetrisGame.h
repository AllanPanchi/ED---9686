#ifndef TETRISGAME_H
#define TETRISGAME_H
#include "ListaSimple.h"
#include "Pieza.h"
#include <vector>
#include <string>
#include <iostream>
#include <Windows.h>
#include <string>

class TetrisGame
{
private:
    int filas;
    int columnas;
    int puntaje;
    Pieza pieza;
    std::vector<std::vector<char>> tablero;
    
public:
	TetrisGame();
	TetrisGame(int numRows, int numCols);
	int getPuntaje();
	Pieza& getPieza();
	void setPieza(Pieza);
	bool acabaDeRotar;
	void rotarPalabra(int fila, int columna);
	ListaSimple<std::string> getPiezas();
	bool hayEspacioVacio(int fila, int columna, bool &gameOver);
	bool hayEspacioHorizontal(int fila, int columna, bool derecha);
	void coincidenPalabras(int fila, int columna);
	void aumentarPuntaje(int aumento);
	void colocarPalabra(int fila, int columna);
	void verificarParaRecorrerTablero(int);
	void borrarPalabra(int fila, int columna);
	void imprimirTablero();
	void limpiar();
	void obtenerPiezas();
};

#endif