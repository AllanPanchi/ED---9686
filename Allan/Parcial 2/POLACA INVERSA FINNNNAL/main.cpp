#include <iostream>
#include "IngresoExpresiones.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	std::string expresion;
	IngresoExpresiones ingresaroperacion;

	std::cout<<"Ingrese la notacion infija: "<<std::endl;
	expresion = ingresaroperacion.ingresoExpresion();
	
	//2+2+sen(90)/10+(3+5)
	
	
	

	return 0;
}