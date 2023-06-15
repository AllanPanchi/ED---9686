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
#ifndef PERSONA_H
#define PERSONA_H

#include <string>



class Persona{

    private:

    std::string nombre;
    std::string apellido;
    int edad;   


    
    public:
        Persona();
        Persona(std::string&, std::string&, int);
        

        void setNombre(std::string);
        void setApellido(std::string);
        void setEdad(int);

        ~Persona();

        std::string getNombre();
        std::string getApellido();
        int getEdad();
        std::string toString();
        



};


#endif 
