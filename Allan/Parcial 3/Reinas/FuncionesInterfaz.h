#include "Tablero.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Reina.cpp"
#define DIMENSION 8
using namespace std;
class FuncionesInterfaz:public Tablero{
	
	public:
	fstream archivo;
	Reina *reina;
	FuncionesInterfaz(Reina *rei){
		this->reina=rei;
		this->encerarTablero();
		this->crearArchivo();
	}
	void encerarTablero(void);
   	void crearArchivo(void);
   	void bloquear(int x, int y);
   	void bloquearR(int x, int y);
   	void mostrar(void);
   	void quitarRelleno(int x, int y);
    void solucion(int x, int y, int n1);
    void solucionReinas(void);
	void dibujoReina(int fila, int columna);
	void reinaB(int fila, int columna);
	void solucionRB(int x, int y, int n1);
	void solucionReinasB(int i, int j);
	void mostrarReina();
	void caballo(int fila, int columna);
	void caballoS(int x ,int y, int n1);
	void mostrarCaballo();
	void BolquearCaballo(int x, int y);
	void dibujocaballo(int fila, int columna);
	void ejes();
	void LineaRoja();
	void LineaA();
	void graficarBigTiempoLineal();
	void graficarBigHoraSuperLineal();
	void dibujarBigOExponecialCeleste();
	void dibujarBigOExponecialAzul();
	void dibujarBigOExponecialNaranja();
	void presentacio();
	void caballoP(int fila, int columna);
	void solucionCP(int f, int c, int con);
	char** crearTablero(int dimension);
	void liberarTablero(char** tablero, int dimension);
	int mostrarMovimientos(char** tablero, int dimension, int filas, int columnas);
	void llenarTablero(char** tablero, int dimension);
	bool estaEnBorde(int fila, int columna, int dimension);
	bool estaEnEsquina(int fila, int columna, int dimension);
	void mostrarTablero(char** tablero, int dimension);
	void guardarEnArchivo(char** tablero, int dimension, const string& nombreArchivo);
		
};
