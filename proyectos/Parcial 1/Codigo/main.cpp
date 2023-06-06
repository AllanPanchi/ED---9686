#include "ListaProducto.cpp"
#include <iostream>
#include <chrono>
#include <thread>

int main(int argc, char const *argv[]){

    ListaProducto lista;

    Producto producto1;
    Producto producto2;
    Producto producto3;

    producto1.setCodigo(1);
    producto1.setNombre("Producto 1");
    producto1.setPrecio(10.0);
    producto1.setFechaElaboracion(FechaConcreta(1, 1, 2021));
    producto1.setFechaCaducidad(FechaConcreta(1, 1, 2022));

    producto2.setCodigo(2);
    producto2.setNombre("Producto 2");
    producto2.setPrecio(20.0);
    producto2.setFechaElaboracion(FechaConcreta(2, 1, 2021));
    producto2.setFechaCaducidad(FechaConcreta(2, 1, 2022));

    producto3.setCodigo(3);
    producto3.setNombre("Producto 3");
    producto3.setPrecio(30.0);
    producto3.setFechaElaboracion(FechaConcreta(3, 1, 2021));
    producto3.setFechaCaducidad(FechaConcreta(3, 1, 2022));

    lista.insertar(producto1);
    lista.insertar(producto2);
    lista.insertar(producto3);

    lista.mostrar();

    std::this_thread::sleep_for(std::chrono::seconds(3));
    system("cls");

    lista.eliminar(1);

    lista.mostrar();

    std::this_thread::sleep_for(std::chrono::seconds(3));
    system("cls");

    Nodo *nodo = lista.buscar(3);
    nodo->getProducto().toString();

    std::this_thread::sleep_for(std::chrono::seconds(3));
    system("cls");

    return 0;
}