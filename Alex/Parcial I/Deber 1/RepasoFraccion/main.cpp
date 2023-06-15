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

#include "Persona.h"
#include "Validar.h"



#include  <string>
#include  <iostream>
using namespace std;

int main() {

   string nombre, apellido;	
	int edad;
	Validar v ;

	
	cout << "Ingresa nombre: " << endl;
	nombre = v.pedirNombre();
	cout << "Ingresa apellido: " << endl;
	apellido = v.pedirNombre();
	edad = v.pedirEdad(0, 120);
	
    Persona persona(nombre, apellido, edad);
    
    cout << persona.toString() << endl;    
    
    return 0;

    
}



