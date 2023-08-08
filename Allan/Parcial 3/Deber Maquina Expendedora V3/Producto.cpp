#include "Producto.h"

Producto::Producto(std::string newNombre, float newPrecio, int newStock)
{
   this->nombre = newNombre;
   this->precio = newPrecio;
   this->stock = newStock;
}

Producto::Producto()
{
}

Producto::~Producto()
{
}

std::string Producto::getNombre(void)
{
   return nombre;
}

void Producto::setNombre(std::string newNombre)
{
   nombre = newNombre;
}

float Producto::getPrecio(void)
{
   return precio;
}

void Producto::setPrecio(float newPrecio)
{
   precio = newPrecio;
}

int Producto::getStock(void)
{
   return stock;
}

void Producto::setStock(int newStock)
{
   stock = newStock;
}

void Producto::toString(void)
{
   std::cout << this->getNombre() << " " << this->getPrecio() << " " << this->getStock() << std::endl;
}