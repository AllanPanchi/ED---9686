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
/**
 * @brief Get the Cedula object
 * 
 * @return std::string cedula 
 */
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

/**
 * @brief Set the Cedula object
 * 
 * @param newCedula
 * @return void 
 */
void Persona::setCedula(std::string newCedula)
{
   cedula = newCedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getNombre()
// Purpose:    Implementation of Persona::getNombre()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

/**
 * @brief Get the Nombre object
 * 
 * @return std::string 
 */
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
/**
 * @brief Set the Nombre object
 * 
 * @param newNombre 
 * @return void 
 */
void Persona::setNombre(std::string newNombre)
{
   nombre = newNombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getApellido()
// Purpose:    Implementation of Persona::getApellido()
// Return:     std::string
////////////////////////////////////////////////////////////////////////
/**
 * @brief Get the Apellido object
 * 
 * @return std::string 
 */
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
/**
 * @brief Set the Apellido object
 * 
 * @param newApellido 
 * @return void 
 */
void Persona::setApellido(std::string newApellido)
{
   apellido = newApellido;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::Persona()
// Purpose:    Implementation of Persona::Persona()
// Return:     
////////////////////////////////////////////////////////////////////////
/**
 * @brief Construct a new Persona:: Persona object
 * 
 * @param cedula 
 * @param nombre 
 * @param apellido 
 * @param fechaNacimiento 
 */
Fecha Persona::getFechaNacimiento(void)
{
   return fechaNacimiento;
}

////////////////////////////////////////////////////////////////////////
/**
 * @brief Set the Fecha Nacimiento object
 * 
 * @param newFechaNacimiento 
 * @return void
 */
void Persona::setFechaNacimiento(Fecha newFechaNacimiento)
{
   fechaNacimiento = newFechaNacimiento;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::Persona()
// Purpose:    Implementation of Persona::Persona()
// Return:
////////////////////////////////////////////////////////////////////////
/**
 * @brief Construct a new Persona:: Persona object
 * 
 * @param cedula 
 * @param nombre 
 * @param apellido 
 * @param fechaNacimiento 
 */
Persona::Persona(std::string cedula, std::string nombre, std::string apellido, Fecha fechaNacimiento)
{
   this->cedula = cedula;
   this->nombre = nombre;
   this->apellido = apellido;
   this->fechaNacimiento = fechaNacimiento;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::Persona()
// Purpose:    Implementation of Persona::Persona()
// Return:
////////////////////////////////////////////////////////////////////////
/**
 * @brief Construct a new Persona:: Persona object
 * 
 * @param cedula 
 * @param nombre 
 * @param apellido 
 * @return  
 */
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
/**
 * @brief Destroy the Persona:: Persona object
 * 
 */
Persona::~Persona()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::toString()
// Purpose:    Implementation of Persona::toString()
// Return:     void
////////////////////////////////////////////////////////////////////////
/**
 * @brief  Imprime los datos de la persona
 * 
 * @return void 
 * 
 */
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
