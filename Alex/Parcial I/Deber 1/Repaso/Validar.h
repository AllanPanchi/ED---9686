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
#ifndef Validar_H
#define Validar_H


#include <string>

      

class Validar{

    public:

        /*Validar();
        ~Validar();
        std::string ValidarNombre(std::string nombre);
       
        int ValidarEdad(int edad);*/


        Validar();
        ~Validar();
		std::string pedirNombre();
		int pedirEntero();
		int pedirEdad(int, int);


    private:
       

};

#endif