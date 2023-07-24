/**
 * @file Empleado.h
 * @author Alejandro Andrade - Alex Trejo
 * @brief 
 * @version 1.0
 * @date 2023-07-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <iostream>
#include "Persona.cpp"

class Empleado : public Persona
{
private:
    float sueldo;
public:
    Empleado(std::string cedula, std::string nombre, std::string apellido, Fecha fechaNacimiento, float sueldo);
    Empleado();
    ~Empleado();
    float getSueldo();
    void setSueldo(float sueldo);
    void toString();
};