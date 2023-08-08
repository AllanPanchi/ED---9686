/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Nombre:    Juan Pablo Pinza

Fecha de inicio: 02/08/2023 - 11:37
Fecha de modificación: 04/08/2023 - 03:37

Deber Parte 2: Reina en posición aleatoria del tablero de ajedrez
*/
#include "GenerarTablero.h"
#include <fstream>
#include <graphics.h>
#include <fstream>
#include <cstdlib> // Para la función rand()
#include <ctime>   // Para la función time()
#include <limits>//Para validar con el buffer y eliminar memoria del teclado


//0 Negro, 1 Blanco

int movimientosReina(int fila, int col, int n);

void GenerarTablero::generarTxtTableroNxN() {

	std::cout<<"Ingrese la dimension del tablero de ajedrez: (Min 2, Max 8): ";
	int dim,cuadros;
	std::cin>>dim;

	// Validación del valor de dim
	while (std::cin.fail() || dim < 2 || dim > 8) {
		std::cin.clear(); // Limpia el error de la mmeoria del teclado
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada incorrecta
		std::cout << "\nValor ingresado no valido!!. Vuelva a ingresar un valor entre 2 y 8: ";
		std::cin >> dim;
	}

	cuadros = dim*dim;

	std::ofstream archivo("tablero.txt");

	if(archivo.is_open()) {
		//para poder guardar en el archivo usamos archivo<<
		for(int i = 1; i<=cuadros; i++) {
			//Para Tablas impares
			if(dim%2!=0) {
				if(i%2==0) {
					std::cout<<"1";
					archivo<<"1";
				} else if(i%2!=0) {
					std::cout<<"0";
					archivo<<"0";
				}
				//PARA LOS SALTOS DE LÍNEA:
				if(i%dim==0) {
					std::cout<<"\n";
					archivo<<"\n";
				}
			}
		}
		//Para tablas pares
		//Ejm: 4 filas, debería ser el máximo del valor de fila 4,
		//Cuando sea 0 va a empezar con negro, si cambia a 1 va a empezar con blanco
		if(dim%2==0) {

			bool validador = false;
			for(int i = 0; i<=dim-1; i++) {
				if(validador == false) {
					for(int j = 0 ; j <=dim-1; j++) {
						if(j%2==0) {
							std::cout<<"0";
							archivo<<"0";
						} else if(j%2!=0) {
							std::cout<<"1";
							archivo<<"1";
						}
						validador = true;
					}
				} else if(validador == true) {
					for(int j = 0 ; j <=dim-1; j++) {
						if(j%2==0) {
							std::cout<<"1";
							archivo<<"1";
						} else if(j%2!=0) {
							std::cout<<"0";
							archivo<<"0";
						}
						validador = false;
					}
				}
				std::cout<<"\n";
				archivo<<"\n";
			}
		}
		std::cout<<"\nEl archivo fue escrito con exito"<<std::endl;
	} else {
		std::cout << "No se pudo abrir el archivo." << std::endl;
	}
}


//FUNCIONES ADICIONALES PARA GRAFICAR:

// Función para cargar el tablero desde el archivo
void GenerarTablero::cargarTablero(std::string nombreArchivo, int**& tablero, int& n) {
	std::ifstream archivo(nombreArchivo);

	if (archivo.is_open()) {
		std::string linea;
		n = 0;
		while (std::getline(archivo, linea)) {
			n++;
		}

		archivo.clear();
		archivo.seekg(0, std::ios::beg);

		tablero = new int* [n];
		for (int i = 0; i < n; i++) {
			tablero[i] = new int[n];
			std::getline(archivo, linea);
			for (int j = 0; j < n; j++) {
				tablero[i][j] = linea[j] - '0';
			}
		}

		archivo.close();
	} else {
		std::cout << "No se pudo abrir el archivo." << std::endl;
	}
}

//FUNCIÓN MODIFICADA PARA PODER PONER LA IMAGEN DE LA REINA
void GenerarTablero::dibujarTablero(int** tablero, int n) {
	const int margen = 20;
	int ventanaSize = std::min(n * 100 + 2 * margen, 800);

	initwindow(ventanaSize, ventanaSize);

	int ladoCasilla = (ventanaSize - 2 * margen) / n;

	//Generamos coordenadas aleatorias en base a la dimensión total
	srand(static_cast<unsigned int>(time(nullptr)));
	int filaAleatoria = rand() % n;
	int columnaAleatoria = rand() % n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = margen + j * ladoCasilla;
			int y = margen + i * ladoCasilla;

			/*if (tablero[i][j] == 0) { // 0 representa el color negro
				setfillstyle(SOLID_FILL, BLACK);
			} else { // 1 representa el color blanco
				setfillstyle(SOLID_FILL, WHITE);
			}*/
			int color = (i + j) % 2;

        	setfillstyle(SOLID_FILL, color == 0 ? BLACK : WHITE);
            bar(x, y, x + ladoCasilla, y + ladoCasilla);

			//bar(x, y, x + ladoCasilla, y + ladoCasilla);
		}
	}
	//Para poner la imagen en formato .jpg en alguna de las casillas aleatorias
	readimagefile("reina.jpg", margen + columnaAleatoria * ladoCasilla, margen + filaAleatoria * ladoCasilla,
	              margen + (columnaAleatoria + 1) * ladoCasilla, margen + (filaAleatoria + 1) * ladoCasilla);

	//llamado a función de la prueba
	int numMovimientos = movimientosReina(filaAleatoria, columnaAleatoria, n);
	std::cout<<"***APARTADO DE LA PRUEBA***"<<std::endl;
	std::cout << "La reina puede hacer " << numMovimientos << " movimientos" << std::endl;
	outtextxy(0, 20 + 20, "Tablero con Reina Aleatoria");

	getch();
	closegraph();
}


//FUNCIÓN DE LA PRUEBA

int movimientosReina(int fila, int col, int n) {
	int movimientos = 0;
	if (fila > 0) movimientos++; // arriba
	if (fila < n - 1) movimientos++; // abajo
	if (col > 0) movimientos++; // izquierda
	if (col < n - 1) movimientos++; // derecha
	if (fila > 0 && col > 0) movimientos++; // diagonal superior izquierda
	if (fila > 0 && col < n - 1) movimientos++; // diagonal superior derecha
	if (fila < n - 1 && col > 0) movimientos++; // diagonal inferior izquierda
	if (fila < n - 1 && col < n - 1) movimientos++; // diagonal inferior derecha
	return movimientos;
}



// Función para liberar la memoria utilizada por el tablero
void GenerarTablero::liberarTablero(int** tablero, int n) {
	for (int i = 0; i < n; i++) {
		delete[] tablero[i];
	}
	delete[] tablero;
}
