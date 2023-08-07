#include "ValDatos.h"
#include "Maquina.cpp"
#include "Archivos.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int opcion = 0;
    Maquina maquina;
    ValidarDatos valDatos;
    vector<Producto> productos;
    string nombreProducto;
    float precioProducto;
    int cantidadProducto;
    bool encontrado = false;

    maquina.setSaldo(200.00);
    productos.push_back(Producto(0.05, "Chicles", 30));
    productos.push_back(Producto(0.5, "Papas", 30));
    productos.push_back(Producto(0.3, "Aguas", 30));
    productos.push_back(Producto(0.5, "Mani", 30));
    productos.push_back(Producto(1.00, "Sandwich", 30));
    
    do{
        cout << "Ingrese el numero de la opcion que desea realizar: " << endl;
        cout << "1. Comprar" << endl;
        cout << "2. Salir" << endl;
        opcion = valDatos.validarEnteroMenu();

        switch(opcion){
            case 1:
                cout << "saldo de la maquina disponible: " << maquina.getSaldo() << endl;
                for (const auto& producto : productos) {
                    cout << producto.getNombre() << " - Precio $" << producto.getPrecio() << " - Cantidad: " << producto.getCantidad() << endl;
                    
                }
                cout << "\nIngrese el nombre del producto que desea canjear: ";
                nombreProducto = valDatos.validarString();
                cout << "Ingrese su saldo: $";
                precioProducto = valDatos.validarFloat();
                cout << "Ingrese cuantas unidades quiere llevar: ";
                cantidadProducto = valDatos.validarEntero();
                for(auto& producto : productos){
                    canjearProducto(productos, nombreProducto, precioProducto, cantidadProducto, maquina.getSaldo(), maquina);
                    encontrado = true;
                    break;   
                }

            break;

            case 2:
                cout << "Gracias por su compra" << endl;

            break;

            default:
                cout << "Opcion no valida" << endl;

            break;
        }

    }while(opcion != 2);

    return 0;
}