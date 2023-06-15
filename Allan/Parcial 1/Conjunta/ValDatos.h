#pragma once
#include <string>
#include <random>
#include <iostream>
#include <cstdlib>
#include <conio.h>

class ValidarDatos
{
    public:
        // static int generarCodigo();
        // static int validarEntero();
        // static int validarEnteroMenu();
        // static float validarFloat();
        //static std::string validarString();

        static int generarCodigo(){
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dis(10000, 99999);

            return dis(gen);
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
            char *entrada = new char[5];
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
                } else if (std::isalpha(tecla) || std::isspace(tecla)) {
                    entrada += tecla;
                    std::cout << tecla;
                }
            }

            return entrada;
        }

};