#include "FuncionesInterfaz.cpp"
#include "FuncionA.cpp"
#include "validar.h"
#include <conio.h>
#include <string.h>
#include <graphics.h>
#include <math.h>
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

	str_cpy(datoEntero,ingresarDatosEnteros("\nIngrese la fila: "));
	fila = funcion_atoi(datoEntero,strlen(datoEntero));
	str_cpy(datoEntero,ingresarDatosEnteros("\nIngrese la columna  "));
	columna= funcion_atoi(datoEntero,strlen(datoEntero));
	rei = new Reina(1);
	obj= new FuncionesInterfaz(rei);
	obj->caballoP(fila-1,columna-1);

				
	system("PAUSE");
	cleardevice();
	return 0;
}
