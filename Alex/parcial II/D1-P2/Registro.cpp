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

#include "Registro.h"
#include "Persona.h"

////////////////////////////////////////////////////////////////////////
// Name:       Registro::getPersona()
// Purpose:    Implementation of Registro::getPersona()
// Return:     Persona
////////////////////////////////////////////////////////////////////////

Persona Registro::getPersona(void)
{
   return persona;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::setPersona(Persona newPersona)
// Purpose:    Implementation of Registro::setPersona()
// Parameters:
// - newPersona
// Return:     void
////////////////////////////////////////////////////////////////////////

void Registro::setPersona(Persona newPersona)
{
   persona = newPersona;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::getEntrada()
// Purpose:    Implementation of Registro::getEntrada()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Registro::getEntrada(void)
{
   return entrada;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::setEntrada(std::string newEntrada)
// Purpose:    Implementation of Registro::setEntrada()
// Parameters:
// - newEntrada
// Return:     void
////////////////////////////////////////////////////////////////////////

void Registro::setEntrada(std::string newEntrada)
{
   entrada = newEntrada;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::getSalida()
// Purpose:    Implementation of Registro::getSalida()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Registro::getSalida(void)
{
   return salida;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::setSalida(std::string newSalida)
// Purpose:    Implementation of Registro::setSalida()
// Parameters:
// - newSalida
// Return:     void
////////////////////////////////////////////////////////////////////////

void Registro::setSalida(std::string newSalida)
{
   salida = newSalida;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::Registro()
// Purpose:    Implementation of Registro::Registro()
// Return:     
////////////////////////////////////////////////////////////////////////

Registro::Registro()
{
  


}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::~Registro()
// Purpose:    Implementation of Registro::~Registro()
// Return:     
////////////////////////////////////////////////////////////////////////

Registro::~Registro()
{
   // TODO : implement
}