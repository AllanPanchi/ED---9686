// #include <iostream>
// #include "Producto.h"

// Producto::Producto(int codigo, std::string nombre, float precio,const FechaConcreta& fechaElaboracion,const FechaConcreta& fechaCaducidad) {
//     this->codigo = codigo;
//     this->nombre = nombre;
//     this->precio = precio;
//     this->fechaElaboracion = fechaElaboracion;
//     this->fechaCaducidad = fechaCaducidad;
// }

// Producto::Producto() : codigo(0), nombre(""), precio(0.0) {}

// Producto::~Producto() {}

// void Producto::setCodigo(int codigo) {
//     this->codigo = codigo;
// }

// int Producto::getCodigo() {
//     return codigo;
// }

// void Producto::setNombre(std::string nombre) {
//     this->nombre = nombre;
// }

// std::string Producto::getNombre() {
//     return nombre;
// }

// void Producto::setPrecio(float precio) {
//     this->precio = precio;
// }

// float Producto::getPrecio() {
//     return precio;
// }

// FechaConcreta Producto::getFechaElaboracion() {
//     return this->fechaElaboracion;
// }

// FechaConcreta Producto::getFechaCaducidad() {
//     return this->fechaCaducidad;
// }

// void Producto::setFechaElaboracion(const FechaConcreta& fechaElaboracion) {
//     this->fechaElaboracion = fechaElaboracion;
// }

// void Producto::setFechaCaducidad(const FechaConcreta& fechaCaducidad) {
//     this->fechaCaducidad = fechaCaducidad;
// }

// void Producto::toString() {
//     std::cout << "Codigo: " << this->codigo << std::endl;
//     std::cout << "Nombre: " << this->nombre << std::endl;
//     std::cout << "Precio: " << this->precio << std::endl;
//     std::cout << "Fecha de elaboracion: "; this->fechaElaboracion.print();
//     std::cout << "Fecha de caducidad: "; this->fechaCaducidad.print();
// }