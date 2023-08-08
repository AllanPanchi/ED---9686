#include <fstream>
#include "ManejoArchivos.h"

    void ManejoArchivos::guardarProductos(const std::string& nombreArchivo, Lista<Producto>& lista) {
        std::ofstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            Nodo<Producto>* temp = lista.getPrimero();
            do {
                archivo << temp->getValor().getNombre() << " "
                        << temp->getValor().getPrecio() << " "
                        << temp->getValor().getStock() << " "
                        << std::endl;
                temp = temp->getSiguiente();
            } while (temp != lista.getPrimero());

            archivo.close();
            std::cout << "Archivo sobrescrito exitosamente." << std::endl;
        } else {
            std::cout << "No se pudo abrir el archivo para sobrescribir." << std::endl;
        }
    }

    void ManejoArchivos::cargarProductos(const std::string& nombreArchivo, Lista<Producto>& lista) {
        std::ifstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            std::string nombre;
            float precio;
            int stock;
            Producto producto;
            while (archivo >> nombre >> precio >> stock) {
                producto.setNombre(nombre);
                producto.setPrecio(precio);
                producto.setStock(stock);
                lista.insertar(producto);
            }
            archivo.close();
        } else {
            std::cout << "No se pudo abrir el archivo." << std::endl;
        }
    }

    void ManejoArchivos::guardarMaquina(const std::string& nombreArchivo, Maquina& maquina) {
        std::ofstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            Maquina temp = maquina;
            archivo << temp.getMonto() << " "
                    << temp.getCincoC() << " " 
                    << temp.getDiezC() << " " 
                    << temp.getVeinticincoC() << " "
                    << temp.getCincuentaC() << " "
                    << temp.getUnD()
                    << std::endl;

            archivo.close();
            std::cout << "Archivo sobrescrito exitosamente." << std::endl;
        } else {
            std::cout << "No se pudo abrir el archivo para sobrescribir." << std::endl;
        }
    }

    void ManejoArchivos::cargarMaquina(const std::string& nombreArchivo, Maquina& maquina) {
        std::ifstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            float monto;
            int cincoC, diezC, veinticincoC, cincuentaC, unD;
            while (archivo >> monto >> cincoC >> diezC >> veinticincoC >> cincuentaC >> unD) {
                maquina.setMonto(monto);
                maquina.setCincoC(cincoC);
                maquina.setDiezC(diezC);
                maquina.setVeinticincoC(veinticincoC);
                maquina.setCincuentaC(cincuentaC);
                maquina.setUnD(unD);
            }
            archivo.close();
        } else {
            std::cout << "No se pudo abrir el archivo." << std::endl;
        }
    }

