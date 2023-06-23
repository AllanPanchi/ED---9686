/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Allan Panchi
                Alex Trejo 
                Sebastian Verdugo
Fecha de inicio: 15/06/2023
Fecha de modificación: 15/06/2023

Ordenamiento de lista circular doblemente enlazadas
*/
#pragma once
#include <string>
#include <random>
#include <iostream>
#include <cstdlib>
#include <conio.h>

class ValidarDatos
{
    public:

        static int validarFecha(int fecha)
        {
            fecha = ValidarDatos::validarEntero();
            while (fecha <1956  || fecha > 2006)
            {
                std::cout << "Ingrese un anio valido: ";
                fecha = ValidarDatos::validarEntero();
            }

            return fecha;
        }


        
        bool validarCedula(const std::string& cedula) {
            if (cedula.length() == 10) {
            
                int sum = 0;
                for (int i = 0; i < 9; i++) {
                    int digit = cedula[i] - '0';
                    if (i % 2 == 0) {
                        digit *= 2;
                        if (digit > 9) {
                            digit -= 9;
                        }
                    }
                    sum += digit;
                }

                int checksum = (sum % 10 == 0) ? 0 : (10 - sum % 10);
                int lastDigit = cedula[9] - '0';

                if (checksum == lastDigit) {
                    return true;
                }
            }
            return false;
        }
        
        std::string ingresarCedulaValida() {
            std::string cedula;

            while (true) {
                
                cedula = "";

                char tecla;
                while (true) {
                    tecla = getch();

                    if (tecla == '\r') {
                        std::cout << std::endl;
                        break;
                    } else if (tecla == '\b' && !cedula.empty()) {
                        cedula.pop_back();
                        std::cout << "\b \b";
                    } else if (std::isdigit(tecla) && cedula.length() < 10) {
                        cedula += tecla;
                        std::cout << tecla;
                    }
                }

                if (validarCedula(cedula)) {
                    break;
                } else {
                    std::cout << "Cedula invalida. Por favor, intentelo nuevamente." << std::endl;
                }
            }

            return cedula;
        }
        

        


        

        static std::string validarNombreYApellido(std::string nombre){
            
            nombre = ValidarDatos::validarString();
            while (nombre == "")
            {
                std::cout << "Ingrese un nombre valido: ";
                nombre = ValidarDatos::validarString();
            }
            return nombre;
        }

        static int generarCodigo(){

            // lambda para generar un numero aleatorio entre 10000 y 99999
            auto random = []() -> int {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<int> dis(10000, 99999);

                return dis(gen);
            };

            return random();
        }

        static int validarEnteroMenu() {		
            char entrada;
            char tecla;
            while (true) {
                tecla = getch();
                
                if (tecla == '\r') {
                    std::cout << std::endl;
                    break;
                } else if (tecla == '\b') {
                    if (entrada) {
                        std::cout << "\b \b";
                        entrada = '\0';
                    }
                } else if (isdigit(tecla) && !entrada) {
                    entrada = tecla;
                    std::cout << tecla;
                }
            }
            
            if (entrada) {
                int numero = entrada - '0';
                if (numero >= 1 || numero <= 6)
                {
                    return numero;
                }
                
            } else {
                return -1;
            }
            return 1;
        }

        static int validarEntero() {		
            char *entrada = new char[30];
            char tecla;
            int i = 0;
            
            while (true) {
                tecla = getch(); 
                
                if (tecla == '\r') { 
                std::cout << std::endl;
                break;
                } else if (tecla == '\b' && i > 0) { 
                    i--;						
                    std::cout << "\b \b"; 
                    entrada[i] = 0; 
                } else if (isdigit(tecla) && i<12) {
                    entrada[i++] = tecla;
                    std::cout << tecla; 
                }
            }

            return atoi(entrada); 
        }

        static float validarFloat() {
            char *entrada = new char[30];
            char tecla;
            int i = 0;
            bool punto = false;
            int signoMenosPos = -1;
            while(true){
                tecla = getch();
                
                if (tecla == '\r') { 
                std::cout << std::endl;
                break;
                } else if (tecla == '\b' && i > 0) { 		
                    i--;						
                    std::cout << "\b \b";
                    if (entrada[i] == '.') { 
                        punto = false;
                    }
                    if (i == signoMenosPos) { 
                        signoMenosPos = -1;
                    }
                    entrada[i] = 0; 
                } else if (isdigit(tecla) && i < 15) {
                    entrada[i++] = tecla;
                    std::cout << tecla;
                } else if (tecla == '.' && !punto) {
                    entrada[i++] = tecla;
                    punto = true;
                    std::cout << tecla;
                } else if (tecla == '-' && i == 0) {
                    entrada[i++] = tecla;
                    signoMenosPos = i - 1;
                    std::cout << tecla;
                }
            }

            return atof(entrada);
        
        }

        static std::string validarString() {
            std::string entrada;
            char tecla;

            while (true) {
                
                tecla = getch();

                if (tecla == '\r') {
                    std::cout << std::endl;
                    break;
                } else if (tecla == '\b' && !entrada.empty()) {
                    entrada.pop_back();
                    std::cout << "\b \b";
                } else if (std::isalpha(tecla) && !std::isspace(tecla)) {
                    entrada += tecla;
                    std::cout << tecla;
                }
            }

            return entrada;
        }

};