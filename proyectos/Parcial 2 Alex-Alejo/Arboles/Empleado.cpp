#include "Empleado.h"

/**
 * @brief Construct a new Empleado:: Empleado object
 * 
 * @param cedula 
 * @param nombre 
 * @param apellido 
 * @param fechaNacimiento 
 * @param sueldo 
 * @return Empleado
 */
Empleado::Empleado(std::string cedula, std::string nombre, std::string apellido, Fecha fechaNacimiento, float sueldo) : Persona(cedula, nombre, apellido, fechaNacimiento)
{
    this->sueldo = sueldo;
}


/**
 * @brief Construct a new Empleado:: Empleado object
 * 
 */
Empleado::Empleado()
{
    this->sueldo = 0;
}

/**
 * @brief Destroy the Empleado:: Empleado object
 * 
 */
Empleado::~Empleado()
{
}

/**
 * @brief Get the Sueldo object
 * 
 * @return float 
 */
float Empleado::getSueldo(){
    return this->sueldo;
}

/**
 * @brief Set the Sueldo object
 * 
 * @param sueldo 
 */
void Empleado::setSueldo(float sueldo){
    this->sueldo = sueldo;
}

/**
 * @brief Muestra los datos del empleado
 * 
 */
void Empleado::toString(){
    std::cout << "Cedula: " << this->getCedula() << std::endl;
    std::cout << "Nombre: " << this->getNombre() << std::endl;
    std::cout << "Apellido: " << this->getApellido() << std::endl;
    std::cout << "Fecha de nacimiento: " << this->getFechaNacimiento().getDia() 
                  << "/" << this->getFechaNacimiento().getMes() 
                  << "/" << this->getFechaNacimiento().getAnio()
                  << std::endl;
    std::cout << "Sueldo: " << this->sueldo << std::endl;
}