
#include "ControladorMenu.h"
#include <iostream>
#include <ctime>    // Para la semilla aleatoria
int main() {

	srand(time(NULL)); // Inicializar la semilla con el tiempo actual
	ControladorMenu ctrlMenu;
	ctrlMenu.correrMenu();
	
    system ("pause");
	return 0;




}