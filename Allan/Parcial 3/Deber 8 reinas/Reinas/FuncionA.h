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
#include <vector>
#include <string>

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
	 * @brief Funcion dibujar tablero 2
	 * 
	 */
	void cuadrado2(int dimension);
	
	
	/**
	 * @brief Funcion crear tablero
	 * 
	 * @param dimension 
	 * @return vector<vector<char>> 
	 */
	std::vector<std::vector<char>> createChessboard(int dimension);

	/**
	 * @brief Funcion guardar tablero
	 * 
	 * @param chessboard 
	 */
	void saveChessboardToFile(const std::vector<std::vector<char>>& chessboard, const std::string& filename);

	/**
	 * @brief Funcion leer tablero
	 * 
	 * @param filename 
	 * @return vector<vector<char>> 
	 */
	std::vector<std::vector<char>> readChessboardFromFile(const std::string& filename);

	/**
	 * @brief Funcion imprimir tablero
	 * 
	 * @param chessboard 
	 * @param dimension 
	 */
	void printChessboardToFile(const std::vector<std::vector<char>>& chessboard, int dimension);


	/**
	 * @brief Funcion imprimir tablero
	 * 
	 * @param filename 
	 */
	void printChessboardFromTxtFile(const std::string& filename);

	void changeTextColor(int color);

	

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