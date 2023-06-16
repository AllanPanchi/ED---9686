#include "Operacion.h"

Operacion::Operacion(){};
Operacion::~Operacion(){};

Operacion::Operacion(const float i , const float j) : a(i), b(j){};

void Operacion::setA(float newA)
{
     a = newA;
}
void Operacion::setB(float newB)
{
     b = newB;
}
float Operacion::getA()
{
    return a;
}
float Operacion::getB()
{
    return b;
}

float Calculo::operator +(const Operacion& op) const
{
    Operacion resul(a + op.a, b + op.b);
    return (resul.a + resul.b);
}
