#include "ListaProducto.cpp"
#include "ValDatos.cpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>

int main(int argc, char const *argv[]){

    ValidarDatos validar;
    int opcion;
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
    do{
        std::cout << "Menu de opciones" << std::endl;
        std::cout << "1. Insertar Producto" << std::endl;
        std::cout << "2. Eliminar Producto" << std::endl;
        std::cout << "3. Buscar Producto" << std::endl;
        std::cout << "4. Mostrar Producto" << std::endl;
        std::cout << "5. Salir" << std::endl;
        std::cout << "Ingrese la opcion: " << std::endl;
        opcion = validar.validarEntero();

        switch(opcion)
        {
            case 1:
                lista.insertar(producto1);
                lista.insertar(producto2);
                lista.insertar(producto3);
                std::cout << "El producto ha sido añadido" << std::endl;
            break;

            case 2:
                lista.eliminar(3);
                lista.mostrar();
            break;

            case 3:
                Nodo *nodo = lista.buscar(3);
                nodo->getProducto().toString();
            break;
            case 4:
                lista.mostrar();
            break;
            case 5:
                exit(1);
            break;


        }

        }while(opcion != 5);

        /*lista.mostrar();

        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("cls");

        lista.mostrar();

        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("cls");

        std::this_thread::sleep_for(std::chrono::seconds(3));
        system("cls");*/

        return 0;
}