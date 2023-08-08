/***********************************************************************
 * Module:  Tablero.h
 * Author:  Jeimy
 * Modified: viernes, 27 de enero de 2023 9:03:04
 * Purpose: Declaration of the class Tablero
 ***********************************************************************/

/**
 * @file Tablero.h
 * @author Marley Morales y Camilo Orrico
 * @brief 
 * @version 0.1
 * @date 2023-01-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#if !defined(__tablero_Tablero_h)
#define __tablero_Tablero_h

class Tablero
{
public:
   /**
    * @brief Funcion encerar
    * 
    */
   virtual void encerarTablero(void)=0;
   /**
    * @brief Funcion crear archivo
    * 
    */
   virtual void crearArchivo(void)=0;
   /**
    * @brief Funcion bloquear
    * 
    * @param x 
    * @param y 
    */
   virtual void bloquear(int x, int y)=0;
   /**
    * @brief Funcion mostrar
    * 
    */
   virtual void mostrar(void)=0;
   /**
    * @brief Funcion quitar relleno
    * 
    * @param x 
    * @param y 
    */
   virtual void quitarRelleno(int x, int y)=0;
   /**
    * @brief Funcion solucion
    * 
    * @param x 
    * @param y 
    * @param n1 
    */
   virtual void solucion(int x, int y, int n1)=0;
   /**
    * @brief Funcion solucion piezas
    * 
    */
   virtual void solucionReinas(void)=0;

protected:
private:

};

#endif

