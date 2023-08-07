/**
 * @file FuncionA.h
 * @author Marley Morales y Camilo Orrico 
 * @brief 
 * @version 0.1
 * @date 2023-01-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "Alfil.cpp"
#include "Tablero.h"
using namespace std;
class FuncionA:public Tablero{
	
	public:
	fstream archivo;
	Alfil *alfil;
	/**
	 * @brief Constructor
	 * 
	 * @param alf 
	 */
	FuncionA(Alfil *alf){
		cout<<"Constructor"<<endl;
		this->alfil=alf;
		this->encerarTablero();
		this->crearArchivo();
	}
	/**
	 * @brief Funcion encerar
	 * 
	 */
	void encerarTablero(void);
	/**
	 * @brief Funcion crear el archivo
	 * 
	 */
   	void crearArchivo(void);
	/**
	 * @brief Funcion bloquear posiciones
	 * 
	 * @param x 
	 * @param y 
	 */
   	void bloquear(int x, int y);
	/**
	 * @brief Funcion mostrar
	 * 
	 */
   	void mostrar(void);
	/**
	 * @brief Funcion quitar el relleno
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
	 * @brief Funcion solucion de los alfiles
	 * 
	 */
    void solucionReinas(void);
	/**
	 * @brief Funcion bloquear alfiles
	 * 
	 */
	void bloquearAlfiles(int, int);
	/**
	 * @brief Funcion solucion alfil A
	 * 
	 * @param i 
	 * @param j 
	 */
	void solucionAlfilA(int i, int j);
	/**
	 * @brief Funcion Solucion Alfiles
	 * 
	 */
	void solucionAlfiles(int, int, int);
	/**
	 * @brief Funcion dibujar tablero
	 * 
	 */
	void cuadrado();
	/**
	 * @brief Funcion mostrar alfil
	 * 
	 */
	void mostrarAlfil(void);
	/**
	 * @brief Funcion circulo
	 * 
	 * @param fila 
	 * @param columna 
	 */
	void circulo(int fila, int columna);
};