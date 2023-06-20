/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Allan Panchi
                Alex Trejo 
                Sebastian Verdugo
Fecha de inicio: 15/06/2023
Fecha de modificación: 15/06/2023

Ordenamiento de lista circular doblemente enlazadas
*/

#include "Lista.cpp"
#include <iostream>

int main(int argc, char **argv) {

    Persona persona;
    Registro registro;
    Lista<Registro> lista;

    persona.setCedula("123");
    persona.setNombre("A");
    persona.setApellido("T");

    registro.setPersona(persona);
    registro.setEntrada("12:00");
    registro.setSalida("17:00");

    std::cout << "Lista de registros" << std::endl;
    std::cout << "------------------" << std::endl;

    return 0;

}