#ifndef JUEGO_H
#define JUEGO_H

#include "TetrisGame.h"

class Juego
{
	public:
		Juego();
		void ejecutar();
		
	private:
		TetrisGame tetris;
		int filas;
		int columnas;
		void ocultarCursor();
		void pantallaInicio();
		
};

#endif