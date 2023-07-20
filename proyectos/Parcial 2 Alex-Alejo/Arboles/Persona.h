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

#include <iostream>
#include "Fecha.cpp"

class Persona
{
public:
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   std::string getApellido(void);
   void setApellido(std::string newApellido);
   Fecha getFechaNacimiento(void);
   void setFechaNacimiento(Fecha newFechaNacimiento);

   void toString(void);
   Persona();
   Persona(std::string cedula, std::string nombre, std::string apellido, Fecha fechaNacimiento);
   ~Persona();

protected:
private:
   std::string cedula;
   std::string nombre;
   std::string apellido;
   Fecha fechaNacimiento;

};

