#include <iostream>

class Producto
{
private:
    float precio;
    std::string nombre;
    int cantidad;
public:
    Producto();
    Producto(float, std::string, int);
    ~Producto();
    float getPrecio() const;
    std::string getNombre() const;
    int getCantidad() const;
    void setPrecio(float);
    void setNombre(std::string);
    void setCantidad(int);
};
