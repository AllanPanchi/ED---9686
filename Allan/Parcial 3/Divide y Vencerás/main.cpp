

#include "Matriz.h"
#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

int main(){
	
	Matriz T;
	int **matriz;
	string **matriz2;
    initwindow(900,900);
    int x =65;
    int y=65;
    int opc, tamanio;
    char *c="a";
    
    do{
    	system("CLS");
    	cout<<"Encriptar matriz"<<endl;
    	cout<<"1. generar matriz con numeros primos"<<endl;
    	cout<<"2. encriptar matriz"<<endl;
    	cout<<"3. desencriptar matriz"<<endl;
    	cout<<"4. salir"<<endl;
    	cout<<"Seleccion: ";
    	opc = T.ingresarEnteros();
    	switch(opc){
    		case 1:
    			system("CLS");
    			tamanio = T.pedirDimension();
				T.setDimension(tamanio);
				matriz = T.crearMatriz();
				matriz2 = T.crearMatriz2();
				T.llenar_tablero(matriz);
				T.imprimir_tablero(matriz);
				T.guardarTablero(matriz,matriz2);
				T.graficarTableroAjedrez();
				T.graficarNumeros(matriz,x,y);
    			system("PAUSE");
    			break;
    		case 2:
    			system("CLS");
    			T.encriptarMatriz(matriz2, *c);
				T.imprimir_tablero2(matriz2);
				T.graficarTableroAjedrez();
				T.graficarNumerosString(matriz2,x,y);
    			system("PAUSE");
    			break;
    		case 3:
    			system("CLS");
    			T.desencriptarMatriz(matriz2, *c);
				T.imprimir_tablero2(matriz2);
				T.graficarTableroAjedrez();
				T.graficarNumeros(matriz,x,y);
		    	system("PAUSE");
    			break;
    		case 4:
    			exit(0);
    			break;
		}	
	}while(opc>0 || opc<5);
	
	system("PAUSE");
    closegraph();
    return 0;
}