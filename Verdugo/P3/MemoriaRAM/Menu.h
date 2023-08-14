#ifndef MENU_H
#define MENU_H

#include "ListaCircularDoble.h"
#include "NodoDoble.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>

class Menu
{
private:
    ListaCircularDoble<std::string> options;
    NodoDoble<std::string>* selectedOption;

public:
    // Constructor
    Menu(ListaCircularDoble<std::string> opts) : options(opts) {
        selectedOption = options.getCabeza();
    }

    // Mostrar el menú en la pantalla
    void displayMenu() {
        system("cls"); // Limpiar la pantalla (Windows)

        // Imprimir el encabezado
        std::cout << "====================" << std::endl;
        std::cout << " Programa Recuperar " << std::endl;
        std::cout << " Datos de la Memoria" << std::endl;
        std::cout << "====================" << std::endl;
        std::cout << std::endl;

        NodoDoble<std::string>* node = options.getCabeza();
        do {
            if (node == selectedOption) {
                std::cout << "> ";
            } else {
                std::cout << "  ";
            }
            std::cout << node->getDato() << std::endl;
            node = node->getSiguiente();
        } while (node != options.getCabeza());
    }

    // Mover hacia arriba en el menú
    void moveUp() {
        selectedOption = selectedOption->getAnterior();
    }

    // Mover hacia abajo en el menú
    void moveDown() {
        selectedOption = selectedOption->getSiguiente();
    }

    // Obtener la opción seleccionada
    std::string getSelectedOption() {
        return selectedOption->getDato();
    }
    
    
    static std::string correrMenu() {
        // Crear el menú con las opciones deseadas
        ListaCircularDoble<std::string> options;
        options.insertar("Recuperar datos de la memoria RAM y guardar en archivo .txt");
        options.insertar("Salir del Programa");
        Menu menu(options);

        int choice;
        bool quit = false;

        do {
            menu.displayMenu();
            std::cout << "\nSeleccione una opcion con las teclas de flecha y presione Enter." << std::endl;

            // Leer la tecla presionada sin esperar por Enter (utilizando conio.h en Windows)
            choice = _getch();

            switch (choice) {
                case 72: // Tecla de flecha arriba
                    menu.moveUp();
                    break;
                case 80: // Tecla de flecha abajo
                    menu.moveDown();
                    break;
                case 13: // Tecla Enter
                    quit = true;
                    break;
            }
        } while (!quit);

        return menu.getSelectedOption();
    }
};

#endif
