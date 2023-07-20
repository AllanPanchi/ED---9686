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


#include "Persona.h"

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getCedula()
// Purpose:    Implementation of Persona::getCedula()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Persona::getCedula(void)
{
   return cedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setCedula(std::string newCedula)
// Purpose:    Implementation of Persona::setCedula()
// Parameters:
// - newCedula
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setCedula(std::string newCedula)
{
   cedula = newCedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getNombre()
// Purpose:    Implementation of Persona::getNombre()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Persona::getNombre(void)
{
   return nombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setNombre(std::string newNombre)
// Purpose:    Implementation of Persona::setNombre()
// Parameters:
// - newNombre
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setNombre(std::string newNombre)
{
   nombre = newNombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getApellido()
// Purpose:    Implementation of Persona::getApellido()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Persona::getApellido(void)
{
   return apellido;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setApellido(std::string newApellido)
// Purpose:    Implementation of Persona::setApellido()
// Parameters:
// - newApellido
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setApellido(std::string newApellido)
{
   apellido = newApellido;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::Persona()
// Purpose:    Implementation of Persona::Persona()
// Return:     
////////////////////////////////////////////////////////////////////////

Fecha Persona::getFechaNacimiento(void)
{
   return fechaNacimiento;
}

////////////////////////////////////////////////////////////////////////

void Persona::setFechaNacimiento(Fecha newFechaNacimiento)
{
   fechaNacimiento = newFechaNacimiento;
}

Persona::Persona(std::string cedula, std::string nombre, std::string apellido, Fecha fechaNacimiento)
{
   this->cedula = cedula;
   this->nombre = nombre;
   this->apellido = apellido;
   this->fechaNacimiento = fechaNacimiento;
}

Persona::Persona()
{
   this->cedula = "";
   this->nombre = "";
   this->apellido = "";
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::~Persona()
// Purpose:    Implementation of Persona::~Persona()
// Return:     
////////////////////////////////////////////////////////////////////////

Persona::~Persona()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::toString()
// Purpose:    Implementation of Persona::toString()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::toString(void)
{
   std::cout << "Cedula: " << cedula << std::endl;
   std::cout << "Nombre: " << nombre << std::endl;
   std::cout << "Apellido: " << apellido << std::endl;
   std::cout << "Fecha de nacimiento: " << fechaNacimiento.getDia() 
                  << "/" << fechaNacimiento.getMes() 
                  << "/" << fechaNacimiento.getAnio() 
                  << std::endl;
}
