/**
 * @file FuncionesInterfaz.h
 * @author Marley Morales y Camilo Orrico
 * @brief 
 * @version 0.1
 * @date 2023-01-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Tablero.h"
#include <iostream>
#include <fstream>
#include "Reina.cpp"
#define DIMENSION 8
using namespace std;
class FuncionesInterfaz:public Tablero{
	
	public:
	fstream archivo;
	Reina *reina;
	/**
	 * @brief Constructor
	 * 
	 * @param rei 
	 */
	FuncionesInterfaz(Reina *rei){
		this->reina=rei;
		this->encerarTablero();
		this->crearArchivo();
	}
	/**
	 * @brief  Funcion encerar
	 * 
	 */
	void encerarTablero(void);
	/**
	 * @brief Funcion crear archivo
	 * 
	 */
   	void crearArchivo(void);
	/**
	 * @brief Funcion bloquear
	 * 
	 * @param x 
	 * @param y 
	 */
   	void bloquear(int x, int y);
   	void bloquearR(int x, int y);
	/**
	 * @brief Funcion mostrar
	 * 
	 */
   	void mostrar(void);
	/**
	 * @brief Funcion quitar relleno
	 * 
	 * @param x 
	 * @param y 
	 */
   	void quitarRelleno(int x, int y);
	/**
	 * @brief Funcion solucion
	 * 
	 * @param x 
	 * @param y 
	 * @param n1 
	 */
    void solucion(int x, int y, int n1);
	/**
	 * @brief Funcion solucion reinas
	 * 
	 */
    void solucionReinas(void);
	void dibujoReina(int fila, int columna);
	void dibujoPeonB(int fila, int columna,int dimension);
	void dibujoPeonN(int fila, int columna,int dimension);
	void dibujoReinaB(int fila, int columna,int dimension);
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
	
};