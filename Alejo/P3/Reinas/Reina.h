/***********************************************************************
 * Module:  Reina.h
 * Author:  Jeimy
 * Modified: viernes, 27 de enero de 2023 8:58:41
 * Purpose: Declaration of the class Reina
 ***********************************************************************/

/**
 * @file Reina.h
 * @author Marley Morales y Camilo Orrico
 * @brief 
 * @version 0.1
 * @date 2023-01-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#if !defined(__tablero_Reina_h)
#define __tablero_Reina_h
#include <fstream>
using namespace std;
class Reina
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
   Reina(int n1);
   /**
    * @brief Destructor
    * 
    */
   ~Reina();

public:

   bool **validar;
   char **tablero;
   fstream archivo;
   int contador;
   int n;


};

#endif