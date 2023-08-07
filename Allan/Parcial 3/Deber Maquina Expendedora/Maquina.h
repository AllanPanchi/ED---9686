#include "Producto.cpp"
#include "Moneda.cpp"
#include <iostream>
#include <vector>

class Maquina{
    private:
        std::vector<Producto> producto;
        Moneda monedas;
    public:
        Maquina();
        ~Maquina();
        bool canjearProducto(Producto& producto, const std::string& nombreProducto, float monto, int cantidadProducto, Maquina& maquina);
};
