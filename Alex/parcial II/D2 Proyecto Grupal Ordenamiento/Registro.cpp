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

////////////////////////////////////////////////////////////////////////
// Name:       Registro::getPersona()
// Purpose:    Implementation of Registro::getPersona()
// Return:     Persona
////////////////////////////////////////////////////////////////////////

std::string Registro::getCedula(void)
{
   return cedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::setPersona(Persona newPersona)
// Purpose:    Implementation of Registro::setPersona()
// Parameters:
// - newPersona
// Return:     void
////////////////////////////////////////////////////////////////////////

void Registro::setCedula(std::string newCedula)
{
   cedula = newCedula;
}

std::string Registro::getEstado(void)
{
   return estado;
}

void Registro::setEstado(std::string newEstado)
{
   estado = newEstado;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::getEntrada()
// Purpose:    Implementation of Registro::getEntrada()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

Fecha Registro::getEntrada(void)
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

void Registro::setEntrada(Fecha newEntrada)
{
   entrada = newEntrada;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::getSalida()
// Purpose:    Implementation of Registro::getSalida()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

Fecha Registro::getSalida(void)
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

void Registro::setSalida(Fecha newSalida)
{
   salida = newSalida;
}

void Registro::toString(void)
{
   std::cout << "-------------------------------------------- " << std::endl;
   std::cout << "Cedula: " << cedula << std::endl;
   std::cout << "Hora de entrada: " << entrada.getHora() 
                                 << ":" << entrada.getMinuto()
             << " \nDia/Mes/Anio: " 
                                 << entrada.getDia()
                                 << "/" << entrada.getMes()
                                 << "/" << entrada.getAnio() << std::endl;
   std::cout << "Hora de salida: " << salida.getHora()
                                 << ":" << salida.getMinuto()
             << " \nDia/Mes/Anio: " 
                                 << salida.getDia()
                                 << "/" << salida.getMes()
                                 << "/" << salida.getAnio() << std::endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::Registro()
// Purpose:    Implementation of Registro::Registro()
// Return:     
////////////////////////////////////////////////////////////////////////

Registro::Registro(std::string cedula, Fecha entrada, Fecha salida, std::string estado)
{
   this->cedula = cedula;
   this->entrada = entrada;
   this->salida = salida;
   this->estado = estado;
}

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