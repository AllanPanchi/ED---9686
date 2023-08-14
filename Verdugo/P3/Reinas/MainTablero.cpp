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

void imprimirDesplazamientos(int fila, int dimension) {
    /*if(dimension==1){
		cout<<"La reina puede hacer 0 desplazamientos."<<endl;
		return;
	}
	if(dimension==2){
		cout<<"La reina puede hacer 3 desplazamientos."<<endl;
		return;
	}*/
	int desplazamientos = 2 * (dimension - fila) + 1;
    cout << "La reina puede hacer " << desplazamientos << " desplazamientos." << endl;
}


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
		std::cout << "\t[6]  Crear Tablero" << endl;
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
				
				int dimension;
				cleardevice();
				
				
				do{
					std::cout<<"\n\t Reingrese:  ";
					cin>>dimension;
				}while(dimension<1 || dimension>8);
				
				//cin>>dimension;

				chessboard = obj1->createChessboard(dimension);
				//vector<vector<char>> chessboard = obj1->createChessboard(dimension);

				obj1->saveChessboardToFile(chessboard,"chessboard.txt");


				readChessboard = obj1->readChessboardFromFile("chessboard.txt");
				//vector<vector<char>> readChessboard = obj1->readChessboardFromFile("chessboard.txt");

				obj1->printChessboardToFile(chessboard, dimension);
				obj1->printChessboardFromTxtFile("chessboard_output.txt");


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

							do{
								fila = rand() % dimension + 1;
								cout<<"fila:"<<fila<<endl;
								columna = rand() % dimension + 1;
								cout<<"columna:"<<columna<<endl;
							}while(fila>columna);
	        				if (fila<=columna){
								obj1->cuadrado2(dimension);
								rei->setDimension(dimension);
								/*rei = new Reina(1);
								

	        					obj= new FuncionesInterfaz(rei);
								//obj->solucionReinasB(fila-1,columna-1);*/
								cout<<"dimension:"<<dimension<<endl;
								obj->dibujoReinaB(fila-1,columna-1, dimension);
								cout<<"[ "<<fila<<" ; "<<columna<<" ]"<<endl;
								 imprimirDesplazamientos(fila, dimension);

								if(fila==columna){
									std::cout<<"La reina generada esta en la diagonal principal" <<std::endl;
								}else{
									std::cout<<"La reina no esta en la diagonal principal"<<std::endl;
								}
									


							}else{
								cout<<"Valor no permitido"<<endl;
								cout<<"La fila debe ser mayor a la columna"<<endl;
							}
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
			case 7:

				break;
			case 0:
				system("cls");
            	cout << "Gracias por utilizar este programa." << endl;
            	system("PAUSE");
            	exit(0);
				break;
		}
	}while (opcion!=1|| opcion!=2||opcion !=3 ||opcion !=4 ||opcion !=5 || opcion !=6 ||opcion!=0);
	return 0;
}