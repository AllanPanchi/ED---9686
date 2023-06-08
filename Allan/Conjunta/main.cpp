#include "ListaProducto.cpp"
#include "FuncionesMenu.h"
#include "ValDatos.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    
    bool continuar = true;
    int opcion;
    ListaProducto lista;
    Nodo *nodoTm = NULL;
    Producto producto1;
    int codigo;
    int fecha;
    
    cargarDatosDesdeArchivo("Productos.txt", lista);

    while(continuar){
        
        std::cout << "Menu de opciones" << std::endl;
        std::cout << "1. Insertar Producto" << std::endl;
        std::cout << "2. Eliminar Producto" << std::endl;
        std::cout << "3. Buscar Producto" << std::endl;
        std::cout << "4. Mostrar Producto" << std::endl;
        std::cout << "5. Actualizar Producto" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Ingrese la opcion: " << std::endl;
        opcion = ValidarDatos::validarEnteroMenu();

        switch(opcion)
        {
            case 1:

                system("cls");
                producto1 = FuncionesMenu::insertarProducto();
                lista.insertar(producto1);
                std::cout << "El producto ha sido añadido" << std::endl;
                break;
            
            case 2:

                system("cls");
                std::cout << "Ingrese el codigo del producto a eliminar: ";
                codigo = ValidarDatos::validarEntero();
                nodoTm = lista.buscar(codigo);
                if (nodoTm == NULL)
                {
                    std::cout << "El producto no existe" << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    system("cls");
                } else {
                    lista.eliminar(codigo);
                    std::cout << "El producto " << codigo << " se ha sido eliminado" << std::endl;
                }
                
                break;

            case 3:
                
                system("cls");
                std::cout << "Ingrese la fecha del producto a buscar: ";
                fecha = ValidarDatos::validarEntero();
                nodoTm = lista.buscar(fecha);
                if (nodoTm == NULL)
                {
                    std::cout << "El producto no existe" << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    system("cls");
                } else {
                    std::cout << "El producto encontrados con la fecha: "<< fecha << ":" << std::endl;
                    while (nodoTm)
                    {   
                        nodoTm->getProducto().toString();
                        nodoTm = nodoTm->getSiguiente();
                        std::cout << "---------------------" << std::endl;
                    }
                }
                
                //std::this_thread::sleep_for(std::chrono::seconds(10));
                //system("cls");
                break;
                
            case 4:
                
                system("cls");
                if (lista.size() == 0)
                {
                    std::cout << "No hay productos en la lista" << std::endl;
                } else {
                    std::cout << "Los productos son: " << std::endl;
                    lista.mostrar();
                }
                break;
            
            case 5:
                system("cls");
                std::cout << "Ingrese el codigo del producto a actualizar:\t";
                codigo = ValidarDatos::validarEntero();
                nodoTm = lista.buscar(codigo);
                if (nodoTm == NULL)
                {
                    std::cout << "El producto no existe" << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    system("cls");
                } else {
                    
                    //lista.eliminar(codigo);
                    lista.actualizar(nodoTm);
                    //lista.insertar(producto1);
                }
                break;
                
            case 6:
                
                system("cls");
                continuar = false;
                break;
                
            default:
                
                system("cls");
                std::cout << "Opcion no valida" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(3));
                system("cls");
                break;
        }

    }

    sobreescribirArchivo("Productos.txt", lista);

    return 0;
}