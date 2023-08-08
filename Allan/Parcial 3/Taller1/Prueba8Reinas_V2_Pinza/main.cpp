/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Nombre:    Juan Pablo Pinza

Fecha de inicio: 02/08/2023 - 11:37
Fecha de modificación: 04/08/2023 - 03:37

Deber Parte 2: Reina en posición aleatoria del tablero de ajedrez
*/
#include <iostream>
#include "GenerarTablero.h"
#include <limits>//Para validar con el buffer y eliminar memoria del teclado
#include <ctime>



int main() {
	int opc;
	do {
		std::system("cls");
		std::cout<<"***** PROGRAMA DE TABLERO DE REINAS, PARTE 2 *****\n";
		std::cout<<"Seleccione una opcion:"<<std::endl;
		std::cout<<"1. Generar txt de Tablero"<<std::endl;
		std::cout<<"2. Generar Reina Aleatoria en Tablero"<<std::endl;
		std::cout<<"3. Salir"<<std::endl;
		std::cin>>opc;
		while (std::cin.fail() || opc < 1 || opc > 3) {
			std::cin.clear(); // Limpia el error de la mmeoria del teclado
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada incorrecta
			std::cout << "\nValor ingresado no valido!!. Vuelva a ingresar un valor entre 1 y 3: ";
			std::cin >> opc;
		}

		switch(opc) {
			case 1:
				GenerarTablero::generarTxtTableroNxN();
				break;
			case 3:
				std::cout<<"SALIENDO DEL PROGRAMA..."<<std::endl;
				exit(0);
				break;
			case 2:
				std::string nombreArchivo = "tablero.txt";
				int** tablero;
				int n;
				GenerarTablero::cargarTablero(nombreArchivo, tablero, n);
				GenerarTablero::dibujarTablero(tablero, n);
				GenerarTablero::liberarTablero(tablero, n);
				break;
		}
	} while(opc!=3);

	return 0;
}

