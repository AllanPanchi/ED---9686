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

#pragma once
#include <iostream>
#include <string>
<<<<<<< HEAD


=======
>>>>>>> 978ffe834b84b684e208ab6816907325e30ce63c
#include "Persona.h"

class Registro
{
public:
   Persona getPersona(void);
   void setPersona(Persona newPersona);
   std::string getEntrada(void);
   void setEntrada(std::string newEntrada);
   std::string getSalida(void);
   void setSalida(std::string newSalida);
   Registro();
   ~Registro();

protected:
private:
   Persona persona;
   std::string entrada;
   std::string salida;


};

