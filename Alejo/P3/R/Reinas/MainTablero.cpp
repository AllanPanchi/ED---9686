/***********************************************************************
 * Module:  CuboMagico.cpp
 * Author:  Jeimy Morales y Orrico Camilo
 * Modified: miércoles, 1 de febrero de 2023 18:19:30
 * Purpose: Implementation of the class CuboMagico
 * TALLER
 ***********************************************************************/
#include "FuncionesInterfaz.cpp"
#include "FuncionA.cpp"
#include <conio.h>
#include <string.h>
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>
#include "ValidarDatos.h"
#include "ManageFiles.cpp"


int main(int argc, char** argv) {
	int gd = DETECT;
	int gm;
	//initgraph(&gd, &gm,"C:\TC\8GI");
	initwindow(1350,800); 
	ValidarDatos validar;
	int numero,nume;
	int opcion, n;
	int opcionReina;
	char datoEntero[10];
	Reina *rei;
	FuncionesInterfaz *obj;
	Alfil *alfil;
	FuncionA *obj1;
	int fila, columna;

	std::ofstream archivo("tablero.txt");
	std::string cadena;
	bool estado = true;
	bool salir = false;

	std::string cadenaAux = "";
	std::string cadenaDefinitiva = "";
	std::string linea = "";
	int zoom, tamano;
	
	do{
		obj->presentacio();
		system("color 0F");
		system("cls");
		std::cout << "-----------------------MENU-----------------------" << endl
             << endl; 
        std::cout << "\t[1]  Reinas " << endl;
        std::cout << "\t[2]  Alfiles " << endl;
        std::cout << "\t[3]  Prueba " << endl;
        std::cout << "\t[4]  Reina" << endl;
        std::cout << "\t[5]  Caballo" << endl;
		std::cout << "\t[6]  Imprimir tablero en consola" << endl;
		std::cout << "\t[7]  Crear Tablero con una Reina" << endl;
		std::cout << "\t[0]  Salir " << endl;
        //str_cpy(datoEntero,ingresarDatosEnteros("\nSelecciona: "));
        //opcion = funcion_atoi(datoEntero,strlen(datoEntero));
        //std::cout<<"\n\tIngrese una opcion: ";
		//opcion=ValidarDatos::validarEntero();
		cin>>opcion;


		
		cout<<"\n";
		fila=0;
		columna=0;
		cleardevice();
		obj1->cuadrado();
		obj->ejes();


		vector<vector<char>> chessboard;
		vector<vector<char>> readChessboard;

        switch(opcion){
        	case 1:
        		cout<<"\n\tIngrese el numero de Reinas "<<endl;
        		cin>>n;
        	/*	str_cpy(datoEntero,ingresarDatosEnteros("\n\tIngrese el numero de Reinas "));
        		n = funcion_atoi(datoEntero,strlen(datoEntero));*/
        		rei = new Reina(n);
        		obj= new FuncionesInterfaz(rei);
        		obj->solucionReinas();
        		cout<<"Se creo el archivo txt"<<endl;
        		system("PAUSE");
        		cleardevice();
        		break;
        	case 2:
        		
        		alfil = new Alfil(4);
        		obj1= new FuncionA(alfil);
				obj1->solucionReinas();
				cout<<"Se creo el archivo txt"<<endl;
				system("PAUSE");
				cleardevice();
				break;
			case 3:
				//cleardevice();
				srand(time(NULL));
				do{
					fila = rand() % 8 + 1;
        			columna = rand() % 8 + 1;
        		}while(fila>columna);
	        	if (fila<=columna){
					alfil = new Alfil(1);
	        		obj1= new FuncionA(alfil);
					//obj1->cuadrado2(6);
					obj1->solucionAlfilA(fila-1,columna-1);
					cout<<"[ "<<fila<<" ; "<<columna<<" ]"<<endl;
				}else{
					cout<<"Valor no permitido"<<endl;
					cout<<"La fila debe ser mayor a la columna"<<endl;
				}
				
				system("PAUSE");
				cleardevice();
				break;
			case 4:
				rei->setDimension(8);
				std::cout<<"dimension: "<<rei->getDimension()<<endl;
				do{
					fila = rand() % 8 + 1;
        			columna = rand() % 8 + 1;
        		}while(fila>columna);
	        	if (fila<=columna){
					rei = new Reina(1);
	        		obj= new FuncionesInterfaz(rei);
					obj->solucionReinasB(fila-1,columna-1);
					cout<<"[ "<<fila<<" ; "<<columna<<" ]"<<endl;
				}else{
					cout<<"Valor no permitido"<<endl;
					cout<<"La fila debe ser mayor a la columna"<<endl;
				}
				
				system("PAUSE");
				cleardevice();
				break;
			case 5:
				do{
					fila = rand() % 8 + 1;
        			columna = rand() % 8 + 1;
        		}while(fila>columna);
	        	if (fila<=columna){
					rei = new Reina(1);
	        		obj= new FuncionesInterfaz(rei);
					obj->caballo(fila-1,columna-1);
				//	obj->caballo(1,3);
					cout<<"[ "<<fila<<" ; "<<columna<<" ]"<<endl;
				}else{
					cout<<"Valor no permitido"<<endl;
					cout<<"La fila debe ser mayor a la columna"<<endl;
				}
				
				system("PAUSE");
				cleardevice();
				break;

			case 6:
				std::cout << "Ingrese el tama\xA4o del tablero: ";
				std::cin >> tamano;
				while(tamano < 2 || tamano > 8){
					std::cout << "!!! TAMA\xA5O INVALIDO !!!" << std::endl;
					std::cout << "Ingrese nuevamente el tama\xA4o del tablero: ";
					std::cin >> tamano;
				}

				cadena = "";
				cadenaDefinitiva = "";
				cadenaAux = "";
				linea = "";

				if((tamano % 2) == 0){
					
					for (int i = 0; i < tamano; i++) {
						for (int j = 0; j < tamano; j++) {
							
							if (estado == true){
								cadena += "* ";
								estado = false;
							} else {
								cadena += "0 ";
								estado = true;
							}

						}
						cadena += "\n";
						estado = !estado;
					}

				} else {

					for (int i = 0; i < tamano; i++) {
						for (int j = 0; j < tamano; j++) {
							
							if (estado == true){
								cadena += "* ";
								estado = false;
							} else {
								cadena += "0 ";
								estado = true;
							}
							if(j == tamano){
								if (estado == true){
									estado = false;
								} else {
									estado = true;
								}
							}
						}
						cadena += "\n";
					}
				}

				estado = true;

				ManageFiles::WriteFile("tablero.txt", cadena);
				cadena = ManageFiles::ReadFile("tablero.txt");

				std::cout << "Ingrese el zoom: ";
				std::cin >> zoom;

				cadena = cadena.substr(0, cadena.length()-1);

				for(int i = 0; i < cadena.length(); i++){
					linea += cadena[i];
					if (cadena[i] == '\n')
					{
						for(int j = 0; j < zoom; j++){
							cadenaAux += linea;
						}
						cadenaDefinitiva += cadenaAux;
						cadenaAux = "";
						linea = "";
					}
					
				}

				for(int i = 0; i < cadenaDefinitiva.length(); i++){
	
					if(cadenaDefinitiva[i] == '\n'){
						std::cout << cadenaDefinitiva[i];
					}
					if(cadenaDefinitiva[i] == '*'){
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 255 | 255 | 255 | BACKGROUND_INTENSITY);
						for(int j = 0; j < zoom; j++){
							std::cout << "  ";
						}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15| 0);
					} else if(cadenaDefinitiva[i] == '0'){
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0 | 0 | 0 | BACKGROUND_INTENSITY);
						for(int k = 0; k < zoom; k++){
							std::cout << "  ";
						}
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15| 0);
					}

				}

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15| 0);
				std::cout << "\b" << std::flush;
				system("PAUSE");
				cleardevice();
				break;

			case 7:
				int dimension;
				cleardevice();
				cout<<"\n\t Ingrese el tama\xA4o del tablero: ";
				cin>>dimension;
				while(dimension < 2 || dimension > 8){
					cout << "!!! TAMA\xA5O INVALIDO !!!" << endl;
					cout << "Ingrese nuevamente el tama\xA4o del tablero: ";
					cin >> dimension;
				}

				chessboard = obj1->createChessboard(dimension);
				//vector<vector<char>> chessboard = obj1->createChessboard(dimension);

				obj1->saveChessboardToFile(chessboard,"chessboard.txt");


				readChessboard = obj1->readChessboardFromFile("chessboard.txt");
				//vector<vector<char>> readChessboard = obj1->readChessboardFromFile("chessboard.txt");

				//obj1->printChessboardToFile(chessboard, dimension);
				//obj1->printChessboardFromTxtFile("chessboard_output.txt");


				obj1->cuadrado2(dimension);
				
				cout<<"-------------------------Sub-Menu-----------------"<<endl;
				cout << "\t[1]  Ubicar Reina " << endl;
        		cout << "\t[2]  Continuar " << endl;
				cin>>opcionReina;

				while (opcionReina!=1||opcionReina!=2){
					switch(opcionReina){
						case 1:
							cleardevice();
							srand(time(NULL));
							//Reina::setDimension(dimension);
								fila = rand() % dimension + 1;
								cout<<"fila:"<<fila<<endl;
								columna = rand() % dimension + 1;
								cout<<"columna:"<<columna<<endl;

								obj1->cuadrado2(dimension);
								//rei->setDimension(dimension);
								cout<<"dimension:"<<dimension<<endl;
								obj->dibujoReinaB(fila-1,columna-1, dimension);
								cout<<"[ "<<fila<<" ; "<<columna<<" ]"<<endl;

								// if(dimension == 1){
								// 	std::cout << "La reina no tiene movimientos posibles" << std::endl;
								// } else if((fila == 1 && columna == 1) || (fila == 1 && columna == 8) || (fila == 8 && columna == 1) || (fila == 8 && columna == 8)){
								// 	std::cout << "La reina tiene 3 movimientos posibles" << std::endl;
								// } else if((fila > 1 && fila < 8) && (columna > 1 && columna < 8)){
								// 	std::cout << "La reina tiene 8 movimientos posibles" << std::endl;
								// } else {
								// 	std::cout << "La reina tiene 5 movimientos posibles" << std::endl;
								// }
							
							//system("PAUSE");
							//cleardevice();
							break;
						case 2:
							break;
					}
					break;
				}


				system("PAUSE");
        		cleardevice();
				break;
			case 0:
				system("cls");
            	cout << "Gracias por utilizar este programa." << endl;
            	system("PAUSE");
            	exit(0);
				break;
		}
	}while (opcion >= 0 && opcion <= 7);
	return 0;
}