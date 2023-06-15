#include "ValDatos.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>


int ValidarDatos::validarEntero() {		
	char *entrada = new char[30];
	char tecla;
	int i = 0;
	
	while (true) {
		tecla = getch(); 
		
		if (tecla == '\r') { 
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { 
			i--;						
			std::cout << "\b \b"; 
			entrada[i] = 0; 
		} else if (isdigit(tecla) && i<12) {
			  entrada[i++] = tecla;
			  std::cout << tecla; 
		}
	}

	return atoi(entrada); 
}


float ValidarDatos::validarFloat() {
	char *entrada = new char[30];
	char tecla;
	int i = 0;
	bool punto = false;
	int signoMenosPos = -1;
	while(true){
		tecla = getch();
		
		if (tecla == '\r') { 
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { 		
			i--;						
			std::cout << "\b \b";
			if (entrada[i] == '.') { 
				punto = false;
			}
			if (i == signoMenosPos) { 
				signoMenosPos = -1;
			}
			entrada[i] = 0; 
		} else if (isdigit(tecla) && i < 15) {
			  entrada[i++] = tecla;
			  std::cout << tecla;
		} else if (tecla == '.' && !punto) {
			  entrada[i++] = tecla;
			  punto = true;
			  std::cout << tecla;
		} else if (tecla == '-' && i == 0) {
			  entrada[i++] = tecla;
			  signoMenosPos = i - 1;
			  std::cout << tecla;
		}
	}

	return atof(entrada);
  
}