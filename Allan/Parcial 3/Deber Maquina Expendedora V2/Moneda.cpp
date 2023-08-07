#include "Moneda.h"


Moneda::Moneda(int newValor, std::string newNombre)
{
   this->valor = newValor;
   this->nombre = newNombre;
}

Moneda::Moneda()
{
}

Moneda::~Moneda()
{
}

float Moneda::getValor(void)
{
   return valor;
}

void Moneda::setValor(int newValor)
{
   valor = newValor;
}

std::string Moneda::getNombre(void)
{
   return nombre;
}

void Moneda::setNombre(std::string newNombre)
{
   nombre = newNombre;
}

void Moneda::toString(void)
{
   std::cout << "Moneda: " << this->nombre << " Valor: " << this->valor << std::endl;
}
