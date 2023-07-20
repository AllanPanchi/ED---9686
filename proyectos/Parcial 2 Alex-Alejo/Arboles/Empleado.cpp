#include "Empleado.h"

Empleado::Empleado(std::string cedula, std::string nombre, std::string apellido, Fecha fechaNacimiento, float sueldo) : Persona(cedula, nombre, apellido, fechaNacimiento)
{
    this->sueldo = sueldo;
}

Empleado::Empleado()
{
    this->sueldo = 0;
}

Empleado::~Empleado()
{
}

float Empleado::getSueldo(){
    return this->sueldo;
}

void Empleado::setSueldo(float sueldo){
    this->sueldo = sueldo;
}

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