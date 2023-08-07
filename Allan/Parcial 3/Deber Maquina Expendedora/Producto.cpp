#include "Producto.h"
using namespace std;

Producto::Producto()
{
    precio = 0;
    nombre = "";
    cantidad = 0;
}

Producto::Producto(float precio, string nombre, int cantidad) : precio(precio), nombre(nombre), cantidad(cantidad) {}

Producto::~Producto()
{
}

float Producto::getPrecio() const
{
    return precio;
}

string Producto::getNombre() const
{
    return nombre;
}

int Producto::getCantidad() const
{
    return cantidad;
}

void Producto::setPrecio(float precio)
{
    this->precio = precio;
}

void Producto::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Producto::setCantidad(int cantidad)
{
    this->cantidad = cantidad;
}

