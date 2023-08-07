#include "ValDatos.h"
#include "Archivos.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int opcion = 0;
    Maquina maquina;
    Archivos manejoA;
    ValidarDatos valDatos;
    vector<Producto> productos;
    string nombreProducto;
    string archivo = "Productos.txt";
    float precioProducto;
    int cantidadProducto;
    bool encontrado = false;



    productos.push_back(Producto(0.05, "Chicles", 30));
    productos.push_back(Producto(0.5, "Papas", 30));
    productos.push_back(Producto(0.3, "Aguas", 30));
    productos.push_back(Producto(0.5, "Mani", 30));
    productos.push_back(Producto(1.00, "Sandwich", 30));

    manejoA.escribirArchivoProducto(archivo, productos);    
    do{
        cout << "Ingrese el numero de la opcion que desea realizar: " << endl;
        cout << "1. Comprar" << endl;
        cout << "2. Salir" << endl;
        opcion = valDatos.validarEnteroMenu();

        switch(opcion){
            case 1:
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
                    canjearProducto(productos, nombreProducto, precioProducto, cantidadProducto, maquina);
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