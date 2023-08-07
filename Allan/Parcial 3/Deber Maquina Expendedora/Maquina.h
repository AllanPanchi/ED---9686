#include "Producto.cpp"
#include <iostream>
#include <vector>

class Maquina{
    private:
        std::vector<Producto> producto;
        float saldo;
    public:
        Maquina();
        ~Maquina();
        float getSaldo() const;
        void setSaldo(float);
        bool canjearProducto(Producto& producto, const std::string& nombreProducto, float monto, int cantidadProducto, float saldo, Maquina& maquina);
};
