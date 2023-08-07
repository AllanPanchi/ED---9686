/***********************************************************************
 * Module:  Reina.h
 * Author:  Jeimy
 * Modified: viernes, 27 de enero de 2023 8:58:41
 * Purpose: Declaration of the class Reina
 ***********************************************************************/

/**
 * @file Alfil.h
 * @author Marley Morales y Camilo Orrico
 * @brief 
 * @version 0.1
 * @date 2023-01-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#define __tablero_Reina_h
#include <fstream>

using namespace std;
class Alfil
{
public:
   /**
    * @brief Obterner el objecto Validar
    * 
    * @return true 
    * @return false 
    */
   bool** getValidar(void);
   /**
    * @brief Insertar el objecto Validar
    * 
    * @param newValidar 
    */
   void setValidar(bool **newValidar);
   /**
    * @brief Obterner el objecto Tablero 
    * 
    * @return char** 
    */
   char** getTablero(void);
   /**
    * @brief Insertar el objecto Tablero
    * 
    * @param newTablero 
    */
   void setTablero(char **newTablero);
   /**
    * @brief Obterner el objecto Archivo 
    * 
    * @return fstream 
    */
   fstream getArchivo(void);
   /**
    * @brief Insertar el objecto Archivo
    * 
    * @param newArchivo 
    */
   void setArchivo(fstream newArchivo);
   /**
    * @brief Obterner el objecto Contador 
    * 
    * @return int 
    */
   int getContador(void);
   /**
    * @brief Insertar el objecto Contador
    * 
    * @param newContador 
    */
   void setContador(int newContador);
   /**
    * @brief Obterner el objecto n
    * 
    * @return int 
    */
   int getN(void);
   /**
    * @brief Insertar el objecto n
    * 
    * @param newN 
    */
   void setN(int newN);
   /**
    * @brief Constructor
    * 
    * @param n1 
    */
   Alfil(int n1);
   /**
    * @brief Destructor
    * 
    */
   ~Alfil();
   /**
    * @brief Funcion encerar
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
     * @brief Funcion solucion alfiles
     * 
     */
    void solucionReinas(void);

public:

   bool **validar;
   char **tablero;
   int contador;
   int n;
    	fstream archivo;


};
