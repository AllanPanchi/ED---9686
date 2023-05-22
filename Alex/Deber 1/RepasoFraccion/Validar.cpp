/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
          Allan Panchi
          Sebastian Verdugo
          Alejandro Andrade
Fecha de inicio: 04/05/2023
Fecha de modificación: 22/05/2023


*/
#include "Validar.h"

#include <iostream>
#include <conio.h>
#include <cctype>
#include <string>

Validar::Validar() {

}

Validar::~Validar() {

}


std::string Validar::pedirNombre() {
	std::string nombre;
    char c;

    while ((c = getch()) != '\r') {
        if (c == 8 && !nombre.empty()) { 
            nombre.pop_back(); 
            std::cout << "\b \b"; 
        } else if (isalpha(c) || isspace(c)) { 
            nombre += c; 
            std::cout << c; 
        }
    }
    
    std::cout << std::endl;
		    
    return nombre;		    
}

int Validar::pedirEntero() {	
	int entero;
	std::string input;
    char c;
    bool signo_ingresado, enteroValido;
    
    do {    	
    	enteroValido = true;
    	while ((c = getch()) != '\r') {
	        if (c == 8 && !input.empty()) { 
	            input.pop_back(); 
	            if (input.empty() || input[0] != '-') { 
	                signo_ingresado = false; 
	            }
	            std::cout << "\b \b"; 
	        } else if (isdigit(c) || c == '-' && !signo_ingresado && input.empty()) { 
	            input += c; 
	            if (c == '-') { 
	                signo_ingresado = true; 
	            }
	            std::cout << c; 
	        }
	    }
	    std::cout << std::endl;
	    
	    try {
	    	entero = stoi(input);
		} catch (std::invalid_argument &e) {
			std::cout << "Numero no valido, intete de nuevo" << std::endl;
			enteroValido = false;
			signo_ingresado = false;
			if (!input.empty()) {
				input.pop_back();
			}
		}
	} while (!enteroValido);

    return entero;
}

bool validarEdad(int edad, int min, int max) {
	return edad >= min && edad <= max;
}

int Validar::pedirEdad(int min, int max) {
	int edad;
	std::cout << "Ingresa edad: " << std::endl;
	edad = pedirEntero();
	
	while (!validarEdad(edad, min, max)) {
        std::cout << "Edad invalida. Ingresa solo numeros entre "<< min << " y " << max << "." << std::endl;
        std::cout << "Ingresa edad: ";
        edad = pedirEntero();
    }
	
	return edad;
}


