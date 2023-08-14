/***********************************************************************
 * Module:  CuboMagico.cpp
 * Author:  Jeimy Morales y Orrico Camilo
 * Modified: miércoles, 1 de febrero de 2023 18:19:30
 * Purpose: Implementation of the class CuboMagico
 * TALLER
 ***********************************************************************/
#include "FuncionesInterfaz.cpp"
#include "FuncionA.cpp"
#include "validar.h"
#include <conio.h>
#include <string.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
int main(int argc, char** argv) {
	int gd = DETECT;
	int gm;
	//initgraph(&gd, &gm,"C:\TC\8GI");
	initwindow(1250,700); 
	
	int numero,nume;
	int opcion, n;
	char datoEntero[10];
	Reina *rei;
	FuncionesInterfaz *obj;
	Alfil *alfil;
	FuncionA *obj1;
	int fila, columna;
	fila=9;
	columna=9;
	obj1->cuadrado();
/*	do{
	fila = rand() % 8 + 1;
    columna = rand() % 8 + 1;
    }while(fila>columna);
	*/
	while(fila>8 && columna>8){
		str_cpy(datoEntero,ingresarDatosEnteros("\nIngrese la fila  "));
    	fila = funcion_atoi(datoEntero,strlen(datoEntero));
    	str_cpy(datoEntero,ingresarDatosEnteros("\nIngrese la columna  "));
    	columna= funcion_atoi(datoEntero,strlen(datoEntero));
	}
		rei = new Reina(1);
		obj= new FuncionesInterfaz(rei);
		obj->caballoP(fila-1,columna-1);

				
		system("PAUSE");
		cleardevice();
	return 0;
}