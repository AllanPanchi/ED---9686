#ifndef JUEGO_H
#define JUEGO_H

#include "Tetris.cpp"

class Juego
{
	public:
		Juego();
		void ejecutar();
		
	private:
		Tetris tetris;
		int filas;
		int columnas;
		void ocultarCursor();
        std::string ingresarPalabra();
		
};

#endif