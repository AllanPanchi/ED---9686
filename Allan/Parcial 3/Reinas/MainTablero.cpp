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
	
	do{
		obj->presentacio();
		system("color 0F");
		system("cls");
		cout << "-----------------------MENU-----------------------" << endl
             << endl; 
        cout << "\t[1]  Reinas " << endl;
        cout << "\t[2]  Prueba " << endl;
        cout << "\t[3]  Reina" << endl;
        cout << "\t[4]  Caballo" << endl;
        cout << "\t[5]  Tablero nxn" << endl;
        cout << "\t[0]  Salir " << endl;
        cin>>opcion;
		cout<<"\n";
		fila=0;
		columna=0;
		cleardevice();
		obj1->cuadrado();
		obj->ejes();
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
				do{
					fila = rand() % 8 + 1;
        			columna = rand() % 8 + 1;
        		}while(fila>columna);
	        	if (fila<=columna){
					alfil = new Alfil(1);
	        		obj1= new FuncionA(alfil);
					obj1->solucionAlfilA(fila-1,columna-1);
					cout<<"[ "<<fila<<" ; "<<columna<<" ]"<<endl;
				}else{
					cout<<"Valor no permitido"<<endl;
					cout<<"La fila debe ser mayor a la columna"<<endl;
				}
				
				system("PAUSE");
				cleardevice();
				break;
			case 3:
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
				
			case 4:
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
				
			case 5:
			   	int dimension;
			    //string nombreArchivo;
			    cout << "Ingrese la dimension del tablero: " << endl;
			    cin >> dimension;
				if(dimension == 1){
					cout << "los movimientos son 0" << endl;
					system("Pause");
				}else{
			    	char** tablero;
				//nombreArchivo = "tablero.txt";
			    	tablero = crearTablero(dimension);
			    	llenarTablero(tablero, dimension);
			    //guardarEnArchivo(tablero, dimension, nombreArchivo);
			    	mostrarTablero(tablero, dimension);
			    	liberarTablero(tablero, dimension);
				}
				break;
				
			case 0:
				system("cls");
            	cout << "Gracias por utilizar este programa." << endl;
            	system("PAUSE");
            	exit(0);
				break;
		}
	}while (opcion!=1|| opcion!=2||opcion !=3 ||opcion !=4 ||opcion !=5 || opcion!=0);
	return 0;
}
