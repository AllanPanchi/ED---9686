#include <iostream>
#include "Persona.h"

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