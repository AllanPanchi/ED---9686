
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <cstring>
#include <string>
#include <graphics.h>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;
using std::string;

class Matriz
{

private:
	int dimension;

public:
	void setDimension(int newDimension){ dimension = newDimension;}
	int getDimension(){ return dimension;}


	//CREAR LA MATRIZ DE NUMEROS ENTEROS
	int **crearMatriz(){
		int **matriz;
		matriz = new int *[getDimension()];

		for (int i = 0; i < getDimension(); i++)
		{
			matriz[i] = new int[getDimension()];
		}
		return matriz;
	}
	
	
	//CREAR LA MATRIZ DE STRINGS
	string **crearMatriz2(){
		string **matriz;
		matriz = new string *[getDimension()];

		for (int i = 0; i < getDimension(); i++)
		{
			matriz[i] = new string[getDimension()];
		}
		return matriz;
	}


	//VERIFICA SI ES PRIMO
	bool es_primo(int num){
		if (num < 2)
		{
			return false;
		}
		for (int i = 2; i <= sqrt(num); i++)
		{
			if (num % i == 0)
			{
				return false;
			}
		}
		return true;
	}


	//RELLENA EL TABLERO CON NUMEROS ENTEROS
	void llenar_tablero(int **matriz){
		srand(time(NULL));
		for (int fila = 0; fila < getDimension(); fila++)
		{
			for (int columna = 0; columna < getDimension(); columna++)
			{
					int num_primo = rand() % 99 + 1;
					while (!es_primo(num_primo))
					{
						num_primo = rand() % 99 + 1;
					}
					*(*(matriz + fila) + columna) = num_primo;
			}
		}
	}


	//MUESTRA EL TABLERO DE NUMEROS ENTEROS
	void imprimir_tablero(int **matriz){
		for (int fila = 0; fila < getDimension(); fila++)
		{
			for (int columna = 0; columna < getDimension(); columna++)
			{
				cout << *(*(matriz + fila) + columna) << " ";
			}
			cout << endl;
		}
		
	}
	
	
	//MUESTRA LA TABLERO DE NUMEROS STRINGS
	void imprimir_tablero2(string **matriz){
		for (int fila = 0; fila < getDimension(); fila++)
		{
			for (int columna = 0; columna < getDimension(); columna++)
			{
				cout << *(*(matriz + fila) + columna) << " ";
			}
			cout << endl;
		}	
	}


	//GRAFICA RL TABLERO 
	void graficarTableroAjedrez(){

		int x = 50, y = 50;
		setfillstyle(SOLID_FILL, BLUE);
		bar(30, 30, 470, 470);

		for (int i = 0; i < getDimension(); i++)
		{
			for (int j = 0; j < getDimension(); j++)
			{
				if ((i + j) % 2 == 0)
				{
					setfillstyle(SOLID_FILL, WHITE);
					setbkcolor(WHITE);
					bar(x, y, x + 50, y + 50);
				}
				else
				{
					setfillstyle(SOLID_FILL, BLACK);
					setbkcolor(BLACK);
					bar(x, y, x + 50, y + 50);
				}
				x += 50;
			}
			y += 50;
			x = 50;
		}
	}

	
	//ENCRIPTA LA MATRIZ
	void encriptarMatriz(string **matriz, char c){

		cout<<"Encriptando..."<<endl;
		for (int i = 0; i < getDimension(); i++)
		{
			for (int j = 0; j < getDimension(); j++)
			{
				encriptar(*(*(matriz + i) + j), c);
			}
		}
	}
	
	
	void encriptar(string &cadena, char c){
		int i;
		for (i = 0; i < cadena.size(); i++)
		{
			cadena[i] = cadena[i] + c;
		}
	}


	//DESENCRIPTA LA MATRIZ
	void desencriptarMatriz(string **matriz, char c){
		cout<<"Desencriptando..."<<endl;
		for (int i = 0; i < getDimension(); i++)
		{
			for (int j = 0; j < getDimension(); j++)
			{
				desencriptar(*(*(matriz + i) + j), c);
			}
		}
	}

	void desencriptar(string &cadena, char c){
		int i;
		for (i = 0; i < cadena.size(); i++)
		{
			cadena[i] = cadena[i] - c;
		}
	}


	//GRAFICA NUMEROS DE MATRIZ ENTERA
	void graficarNumeros(int **matriz, int x, int y)
	{
		char num[8];
		int valor;
		for (int i = 0; i < getDimension(); i++)
		{
			for (int j = 0; j < getDimension(); j++)
			{
				valor = *(*(matriz + i) + j);
				sprintf(num, "%d", valor);
				setcolor(BLACK);
				outtextxy(x, y, num);
				x += 50;
			}
			y += 50;
			x = 65;
		}
	}
	
	
	//GRAFICA NUMEROS DE MATRIZ STRING
	void graficarNumerosString(string **matriz, int x, int y){
		char num[8];
		string valor;
		for (int i = 0; i < getDimension(); i++)
		{
			for (int j = 0; j < getDimension(); j++)
			{
				valor = *(*(matriz + i) + j);
				sprintf(num, "%s", valor);
				setcolor(BLACK);
				outtextxy(x, y, num);
				x += 50;
			}
			y += 50;
			x = 65;
		}
	}
	

	//VALIDA LA ENTRADA DE NUMEROS ENTEROS 
	int ingresarEnteros()
	{
		char *dato = new char[10];
		int i = 0;
		int numero;
		char c;
		while ((c = getch()) != 13)
		{

			if (c >= '0' && c <= '9')
			{

				dato[i++] = c;
				printf("%c", c);
				numero = atoi(dato);
			}
			else if (c == 8)
			{

				dato[i] = 0;
				i--;

				putchar(8);
				putchar(32);
				putchar(8);
			}
		}
		dato[i] = '\0';
		return numero;
	}
	
	
	void guardarTablero(int **matriz1, string **matriz2){
		char c[3]="";
		for (int fila = 0; fila < getDimension(); fila++)
		{
			for (int columna = 0; columna < getDimension(); columna++)
			{
				sprintf(c, "%d", *(*(matriz1 + fila) + columna));
				*(*(matriz2 + fila) + columna) = c;
				
			}
		}
	}
	
	int pedirDimension(){
		int tamanio;
		do{
	    	system("CLS");
	    	cout<<"ingrese la dimension del tablero: "<<endl;
			tamanio = ingresarEnteros();	
			cout<<endl;
		}while(tamanio<2 ||tamanio>8);
		return tamanio;
	}
};
