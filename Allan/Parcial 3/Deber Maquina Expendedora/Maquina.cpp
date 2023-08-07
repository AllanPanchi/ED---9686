#include "Maquina.h"

using namespace std;

Maquina::Maquina()
{
    saldo = 0;
}

Maquina::~Maquina()
{
}

float Maquina::getSaldo() const
{
    return saldo;
}

void Maquina::setSaldo(float saldo)
{
    this->saldo = saldo;
}

bool canjearProducto(vector<Producto>& productos, const string& nombreProducto, float monto, int cantidadProducto, float saldo, Maquina& maquina) {
    for(auto& producto : productos) { 
        if(producto.getNombre() == nombreProducto){
            if (monto >= producto.getPrecio() * cantidadProducto && producto.getCantidad() >= cantidadProducto) {
                cout << "Canje exitoso. Ha obtenido un " << producto.getNombre() << "." << endl;
                cout << "Cambio: $" << monto - (producto.getPrecio() * cantidadProducto) << endl;
                int nuevoSaldo = maquina.getSaldo() - (monto - (producto.getPrecio() * cantidadProducto));
                maquina.setSaldo(nuevoSaldo);
                if(producto.getCantidad() < cantidadProducto){
                    cout << "No hay suficientes unidad para satisfacer su demanda" << endl;
                }else{ 
                    int nuevaCantidad = producto.getCantidad() - cantidadProducto;
                    producto.setCantidad(nuevaCantidad);
                }
                return true;
            } else if (producto.getCantidad() < cantidadProducto){
                cout << "No hay suficientes productos de " << producto.getNombre() << endl;
            } else {
                cout << "El monto ingresado no es suficiente para canjear el producto." << endl;
            }
            return false;
        }
    }
    cout << "El producto no se ha encontrado en la maquina" << endl;

    return false;
}