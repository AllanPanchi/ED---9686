#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "ManejoArchivos.cpp"
#include "Moneda.cpp"
#include "ValDatos.h"

void modificarStockMaquina(Maquina& maquina, std::map<float, int> aRestar, std::map<float, int> aSumar){
    
    for (const auto& par : aSumar) {

        if (par.first == 0.05F) {
            maquina.setCincoC(maquina.getCincoC() + par.second);
        } else if (par.first == 0.10F) {
            maquina.setDiezC(maquina.getDiezC() + par.second);
        } else if (par.first == 0.25F) {
            maquina.setVeinticincoC(maquina.getVeinticincoC() + par.second);
        } else if (par.first == 0.50F) {
            maquina.setCincuentaC(maquina.getCincuentaC() + par.second);
        } else if (par.first == 1.00F) {
            maquina.setUnD(maquina.getUnD() + par.second);
        }
    }

    for (const auto& par : aRestar) {
        
        if (par.first == 0.05F) {
            maquina.setCincoC(maquina.getCincoC() - par.second);
        } else if (par.first == 0.10F) {
            maquina.setDiezC(maquina.getDiezC() - par.second);
        } else if (par.first == 0.25F) {
            maquina.setVeinticincoC(maquina.getVeinticincoC() - par.second);
        } else if (par.first == 0.50F) {
            maquina.setCincuentaC(maquina.getCincuentaC() - par.second);
        } else if (par.first == 1.00F) {
            maquina.setUnD(maquina.getUnD() - par.second);
        }
    }

    maquina.setMonto(maquina.getCincoC() * 0.05 +
                     maquina.getDiezC() * 0.10 + 
                     maquina.getVeinticincoC() * 0.25 + 
                     maquina.getCincuentaC() * 0.50 + 
                     maquina.getUnD() * 1.00);

    ManejoArchivos::guardarMaquina("maquina.txt", maquina);
}

void modificarStockProductos(std::string nombre, Lista<Producto> lista){
    Nodo<Producto>* temp = lista.buscar(nombre);
    if (temp) {
        int stock = temp->getValor().getStock();
        if (stock > 0) {
            stock--;
            temp->setValor(Producto(temp->getValor().getNombre(), temp->getValor().getPrecio(), stock));
            ManejoArchivos::guardarProductos("productos.txt", lista);
        } else {
            std::cout << "Producto agotado: " << temp->getValor().getNombre() << std::endl;
            system("pause");
        }
    } else {
        std::cout << "Producto no encontrado" << std::endl;
    }
}

void comprar_producto(std::map<std::string, Producto>& productos, const std::string& producto, float saldo, Lista<Producto> lista, Maquina maquina, std::map<float, int> monedasIngresadas) {
    auto iter = productos.find(producto);
    std::vector<int> cantidades;
    std::map<float, int> monedas_vuelto;
    if (iter != productos.end()) {
        Producto& seleccionado = iter->second;
        if (seleccionado.getStock() > 0 && saldo >= seleccionado.getPrecio()) {
            float vuelto = saldo - seleccionado.getPrecio();
            std::cout << "¡Compra exitosa! Tu vuelto es: $" << vuelto << std::endl;
            seleccionado.setStock(seleccionado.getStock()-1);
            std::vector<float> monedas = {1, 0.5, 0.25, 0.10, 0.05};
            
            for (float moneda : monedas) {
                while (vuelto >= moneda) {
                    vuelto -= moneda;
                    monedas_vuelto[moneda]++;
                }
            }
            std::cout << "Vuelto en monedas:" << std::endl;
            for (const auto& par : monedas_vuelto) {
                std::cout << "$" << par.first << " x " << par.second << std::endl;
                cantidades.push_back(par.second);
            }
            system("Pause");
        } else {
            std::cout << "Dinero insuficiente o producto agotado. Introduce más monedas o elige otro producto." << std::endl;
            system("Pause");
        }
    } else {
        std::cout << "Producto no encontrado." << std::endl;
        system("Pause");
    }

    modificarStockProductos(producto, lista);
    modificarStockMaquina(maquina, monedas_vuelto, monedasIngresadas);

}

std::map<std::string, Producto> leer_productos() {
    std::map<std::string, Producto> productos;
    std::ifstream archivo("productos.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string nombre;
            float precio;
            iss >> nombre >> precio;
            productos[nombre] = Producto(nombre, precio, 10); // Aquí puedes establecer el stock inicial de cada producto
        }
        archivo.close();
    } else {
        std::cout << "No se encontró el archivo de productos. Creando uno nuevo con valores predeterminados." << std::endl;
        std::ofstream nuevo_archivo("productos.txt");
        if (nuevo_archivo.is_open()) {
            nuevo_archivo << "ProductoA 10.50" << std::endl;
            nuevo_archivo << "ProductoB 5.75" << std::endl;
            nuevo_archivo << "ProductoC 8.20" << std::endl;
            nuevo_archivo.close();
            std::cout << "Archivo de productos creado exitosamente." << std::endl;
            return leer_productos(); // Llamada recursiva para leer el archivo recién creado
        } else {
            std::cout << "Error al crear el archivo de productos." << std::endl;
        }
    }
    return productos;
}

void mostrarProductos(Lista<Producto> lista)
{
    std::cout << "Productos disponibles: " << std::endl;
    std::cout << "Nombre - Precio - Stock" << std::endl;
    Nodo<Producto>* temp = lista.getPrimero();
    do {
        std::cout << temp->getValor().getNombre() << " - "
                << temp->getValor().getPrecio() << " - "
                << temp->getValor().getStock() << std::endl;
        temp = temp->getSiguiente();
    } while (temp != lista.getPrimero());
}

void asignarCambio(Maquina& maquina){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for(int i = 0; i < 6; ++i){
        int cambioAleatorio = std::rand() % 100 + 1;
        switch (i) {
            case 0:
                maquina.setUnD(cambioAleatorio);
                break;
            case 1:
                maquina.setCincuentaC(cambioAleatorio);
                break;
            case 2:
                maquina.setVeinticincoC(cambioAleatorio);
                break;
            case 3:
                maquina.setDiezC(cambioAleatorio);
                break;
            case 4:
                maquina.setCincoC(cambioAleatorio);
                break;
            case 5:
                maquina.setMonto(maquina.getCincoC() + maquina.getCincuentaC() + maquina.getDiezC() 
                + maquina.getVeinticincoC() + maquina.getUnD());
                break;
        }
    }

}



int main()
{
    system("cls");

    std::map<std::string, Producto> productos = leer_productos();

    Maquina maquina;
    asignarCambio(maquina);
    ManejoArchivos::guardarMaquina("maquina.txt", maquina);
    ValidarDatos valDatos;

    std::vector<Moneda> cambio;
    std::string nombre;
    bool salir = false;
    int opcion = 0;
    int opcion2 = 0;
    float saldo = 0;
    bool salir2 = false;

    while (!salir)
    {
        system("cls");
        std::map<float, int> monedasIngresadas;
        Lista<Producto> lista;
        ManejoArchivos::cargarProductos("productos.txt", lista);
        ManejoArchivos::cargarMaquina("maquina.txt", maquina);
        
        mostrarProductos(lista);
        
        std::cout << "Selecione una opcion: " << std::endl;
        std::cout << "1. Comprar" << std::endl;
        std::cout << "2. Salir" << std::endl;
        
        opcion = valDatos.validarEnteroMenu();

        switch (opcion)
        {
            case 1:                
                while (!salir2)
                {
                    std::cout << "Ingreso del Saldo" << std::endl;
                    std::cout << "1. 5 centavos" << std::endl;
                    std::cout << "2. 10 centavos" << std::endl;
                    std::cout << "3. 25 centavos" << std::endl;
                    std::cout << "4. 50 centavos" << std::endl;
                    std::cout << "5. 1 dolar" << std::endl;
                    std::cout << "6. Salir" << std::endl;
                    std::cout << "Su saldo es: " << saldo << std::endl;

                    std::cout << "Ingrese su moneda: " << std::endl;
                    opcion2 = valDatos.validarEnteroMenu();

                    switch (opcion2)
                    {
                    case 1:
                        saldo += 0.05F;
                        monedasIngresadas[0.05]++;
                        break;

                    case 2:
                        saldo += 0.10F;
                        monedasIngresadas[0.10]++;
                        break;

                    case 3:
                        saldo += 0.25F;
                        monedasIngresadas[0.25]++;
                        break;

                    case 4:
                        saldo += 0.50F;
                        monedasIngresadas[0.50]++;
                        break;

                    case 5:
                        saldo += 1.0F;
                        monedasIngresadas[1]++;
                        break;
                    
                    case 6:
                        salir2 = true;
                        break;
                    
                    default:
                        std::cout << "Ingrese una opcion valida." << std::endl;
                        break;
                    }

                }
                mostrarProductos(lista);
                std::cout << "Ingrese el producto que desee comprar: ";
                nombre = valDatos.validarString();
                
                comprar_producto(productos, nombre, saldo, lista, maquina, monedasIngresadas);
                break;
            case 2:
                salir = true;
                break;
            default:
                std::cout << "Ingrese una opcion valida." << std::endl;
                break;
        }

        
    }

    system("cls");
    return 0;
}