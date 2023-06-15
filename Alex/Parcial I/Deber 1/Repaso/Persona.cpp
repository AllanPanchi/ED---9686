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

      

        Persona::Persona(std::string& nombre, std::string& apellido, int edad)
    : nombre(nombre), apellido(apellido), edad(edad) {
}

       Persona::~Persona(){

       } 

        void Persona::setNombre(std::string nuevoNombre) { 

            this->nombre = nuevoNombre;
        }
        
        void Persona::setApellido(std::string nuevoApellido) {
            this->apellido = nuevoApellido;
        }
        
        void Persona::setEdad(int nuevoEdad) {
            this->edad = nuevoEdad;
        }
        
        std::string Persona::getNombre() {
            return this->nombre;
        }
        
        std::string Persona::getApellido() {
            return this->apellido;
        }
        
        int Persona::getEdad() {
            return this->edad;
        }

        std::string Persona::toString(){
            return this->nombre + " " + this->apellido + " " + std::to_string(this->edad);
        }

       