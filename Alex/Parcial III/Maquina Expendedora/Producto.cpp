/***********************************************************************
 * Module:  Producto.cpp
 * Author:  02ale
 * Modified: domingo, 6 de agosto de 2023 13:44:58
 * Purpose: Implementation of the class Producto
 ***********************************************************************/

#include "Producto.h"

////////////////////////////////////////////////////////////////////////
// Name:       Producto::Producto()
// Purpose:    Implementation of Producto::Producto()
// Return:     
////////////////////////////////////////////////////////////////////////

Producto::Producto(std::string newNombre, float newPrecio, int newStock)
{
   this->nombre = newNombre;
   this->precio = newPrecio;
   this->stock = newStock;
}

////////////////////////////////////////////////////////////////////////
// Name:       Producto::Producto()
// Purpose:    Implementation of Producto::Producto()
// Return:     
////////////////////////////////////////////////////////////////////////

Producto::Producto()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Producto::~Producto()
// Purpose:    Implementation of Producto::~Producto()
// Return:     
////////////////////////////////////////////////////////////////////////

Producto::~Producto()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Producto::getNombre()
// Purpose:    Implementation of Producto::getNombre()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Producto::getNombre(void)
{
   return nombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Producto::setNombre(std::string newNombre)
// Purpose:    Implementation of Producto::setNombre()
// Parameters:
// - newNombre
// Return:     void
////////////////////////////////////////////////////////////////////////

void Producto::setNombre(std::string newNombre)
{
   nombre = newNombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Producto::getPrecio()
// Purpose:    Implementation of Producto::getPrecio()
// Return:     float
////////////////////////////////////////////////////////////////////////

float Producto::getPrecio(void)
{
   return precio;
}

////////////////////////////////////////////////////////////////////////
// Name:       Producto::setPrecio(float newPrecio)
// Purpose:    Implementation of Producto::setPrecio()
// Parameters:
// - newPrecio
// Return:     void
////////////////////////////////////////////////////////////////////////

void Producto::setPrecio(float newPrecio)
{
   precio = newPrecio;
}

////////////////////////////////////////////////////////////////////////
// Name:       Producto::getStock()
// Purpose:    Implementation of Producto::getStock()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Producto::getStock(void)
{
   return stock;
}

////////////////////////////////////////////////////////////////////////
// Name:       Producto::setStock(int newStock)
// Purpose:    Implementation of Producto::setStock()
// Parameters:
// - newStock
// Return:     void
////////////////////////////////////////////////////////////////////////

void Producto::setStock(int newStock)
{
   stock = newStock;
}

////////////////////////////////////////////////////////////////////////
// Name:       Producto::toString()
// Purpose:    Implementation of Producto::toString()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Producto::toString(void)
{
   std::cout << this->getNombre() << " " << this->getPrecio() << " " << this->getStock() << std::endl;
}