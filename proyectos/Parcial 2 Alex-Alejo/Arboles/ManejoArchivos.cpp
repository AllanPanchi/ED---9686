#include <fstream>
#include "ManejoArchivos.h"

    void ManejoArchivos::guardarPersonas(const std::string& nombreArchivo, Lista<Empleado>& lista) {
        std::ofstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            Nodo<Empleado>* temp = lista.getPrimero();
            do {
                archivo << temp->getValor().getCedula() << " " << temp->getValor().getNombre() 
                << " " << temp->getValor().getApellido()
                << " " << temp->getValor().getSueldo()
                << " " << temp->getValor().getFechaNacimiento() << std::endl;
                temp = temp->getSiguiente();
            } while (temp != lista.getPrimero());

            archivo.close();
            std::cout << "Archivo sobrescrito exitosamente." << std::endl;
        } else {
            std::cout << "No se pudo abrir el archivo para sobrescribir." << std::endl;
        }
    }

    void ManejoArchivos::cargarPersonas(const std::string& nombreArchivo, Lista<Empleado>& lista) {
        std::ifstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            float sueldo;
            std::string cedula, nombre, apellido;
            int dia, mes, anio, hora, minuto, segundo;
            while (archivo >> cedula >> nombre >> apellido >> sueldo >> dia >> mes >> anio >> hora >> minuto >> segundo) {
                Fecha fechaNacimiento(dia, mes, anio, hora, minuto, segundo);
                Empleado persona(cedula, nombre, apellido, fechaNacimiento, sueldo);
                lista.insertar(persona);
            }
            archivo.close();
        } else {
            std::cout << "No se pudo abrir el archivo." << std::endl;
        }
    }

    void ManejoArchivos::guardarRegistros(const std::string& nombreArchivo, Lista<Registro>& lista) {
        std::ofstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            Nodo<Registro>* temp = lista.getPrimero();
            do {
                archivo << temp->getValor().getCedula() 
                << " " << temp->getValor().getEntrada() 
                << " " << temp->getValor().getSalida()
                << " " << temp->getValor().getEstado()
                << std::endl;
                temp = temp->getSiguiente();
            } while (temp != lista.getPrimero());

            archivo.close();
            std::cout << "Archivo sobrescrito exitosamente." << std::endl;
        } else {
            std::cout << "No se pudo abrir el archivo para sobrescribir." << std::endl;
        }
    }

    void ManejoArchivos::cargarRegistros(const std::string& nombreArchivo, Lista<Registro>& lista) {
        std::ifstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            std::string cedula, estado;
            int dia, mes, anio, hora, minuto, segundo;
            int dia2, mes2, anio2, hora2, minuto2, segundo2;
            while (archivo >> cedula >> dia >> mes >> anio >> hora >> minuto >> segundo >> dia2 >> mes2 >> anio2 >> hora2 >> minuto2 >> segundo2 >> estado) {
                Fecha entrada(dia, mes, anio, hora, minuto, segundo);
                Fecha salida(dia2, mes2, anio2, hora2, minuto2, segundo2);
                Registro registro(cedula, entrada, salida, estado);
                lista.insertar(registro);
            }

            archivo.close();
        } else {
            std::cout << "No se pudo abrir el archivo." << std::endl;
        }
    }

