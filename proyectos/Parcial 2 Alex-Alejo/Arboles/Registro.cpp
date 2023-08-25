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
/**
 * @brief Get the Persona object
 * 
 * @return Persona 
 */
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
/**
 * @brief Set the Persona object
 * 
 * @param newPersona 
 */
void Registro::setCedula(std::string newCedula)
{
   cedula = newCedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::getEstado()
// Purpose:    Implementation of Registro::getEstado()
// Return:     std::string
////////////////////////////////////////////////////////////////////////
/**
 * @brief Get the Estado object
 * 
 * @return std::string 
 */
std::string Registro::getEstado(void)
{
   return estado;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::setEstado(std::string newEstado)
// Purpose:    Implementation of Registro::setEstado()
// Parameters:
// - newEstado
// Return:     void
////////////////////////////////////////////////////////////////////////
/**
 * @brief Set the Estado object
 * 
 * @param newEstado 
 */
void Registro::setEstado(std::string newEstado)
{
   estado = newEstado;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::getEntrada()
// Purpose:    Implementation of Registro::getEntrada()
// Return:     std::string
////////////////////////////////////////////////////////////////////////
/**
 * @brief Get the Entrada object
 * 
 * @return std::string 
 */
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
/**
 * @brief Set the Entrada object
 * 
 * @param newEntrada 
 */
void Registro::setEntrada(Fecha newEntrada)
{
   entrada = newEntrada;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::getSalida()
// Purpose:    Implementation of Registro::getSalida()
// Return:     std::string
////////////////////////////////////////////////////////////////////////
/**
 * @brief Get the Salida object
 * 
 * @return std::string 
 */
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
/**
 * @brief Set the Salida object
 * 
 * @param newSalida 
 */
void Registro::setSalida(Fecha newSalida)
{
   salida = newSalida;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::toString()
// Purpose:    Implementation of Registro::toString()
// Return:     void
////////////////////////////////////////////////////////////////////////
/**
 * @brief 
 * 
 */

void Registro::toString(void)
{
   std::cout << "-------------------------------------------- " << std::endl;
   std::cout << "Cedula: " << cedula << std::endl;
   std::cout << "Hora de entrada: " << entrada.getHora() 
                                 << ":" << entrada.getMinuto()
             << " \nDia/Mes/A\xA4o: " 
                                 << entrada.getDia()
                                 << "/" << entrada.getMes()
                                 << "/" << entrada.getAnio() << std::endl;
   if(estado == "Entrada"){
      std::cout << "No se ha registrado la salida" << std::endl;
   } else {
      std::cout << "Hora de salida: " << salida.getHora()
                                    << ":" << salida.getMinuto()
               << " \nDia/Mes/A\xA4o: " 
                                    << salida.getDia()
                                    << "/" << salida.getMes()
                                    << "/" << salida.getAnio() << std::endl;
   } 
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::Registro()
// Purpose:    Implementation of Registro::Registro()
// Return:     
////////////////////////////////////////////////////////////////////////
/**
 * @brief Construct a new Registro:: Registro object
 * 
 * @param cedula 
 * @param entrada 
 * @param salida 
 * @param estado 
 */
Registro::Registro(std::string cedula, Fecha entrada, Fecha salida, std::string estado)
{
   this->cedula = cedula;
   this->entrada = entrada;
   this->salida = salida;
   this->estado = estado;
}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::Registro()
// Purpose:    Implementation of Registro::Registro()
// Return:
////////////////////////////////////////////////////////////////////////
/**
 * @brief Construct a new Registro:: Registro object
 * 
 */
Registro::Registro()
{
  


}

////////////////////////////////////////////////////////////////////////
// Name:       Registro::~Registro()
// Purpose:    Implementation of Registro::~Registro()
// Return:     
////////////////////////////////////////////////////////////////////////
/**
 * @brief Destroy the Registro:: Registro object
 * 
 */   
Registro::~Registro()
{
   // TODO : implement
}