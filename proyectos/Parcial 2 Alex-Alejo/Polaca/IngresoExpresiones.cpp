/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Alex Trejo 
                
Fecha de inicio: 30/06/2023
Fecha de modificación: 16/07/2023

Proyecto sobre Calculadora polaca infija, posfija y prefija
*/


#include "IngresoExpresiones.h"
#include <conio.h> //getch()
#include <iostream>
#include <regex>
#include <cctype>
#include <string>
#include <cstdlib>
#include <conio.h>

/// @brief Función para verificar si un caracter es un parentesis
/// @param c 
/// @return 
bool IngresoExpresiones::esParentesis(char c){
	return (c == '('|| c == ')');
} 

/// @brief Función para verificar si un caracter es especial
/// @param c 
/// @return 
bool IngresoExpresiones::esEspecial(char c){
	return(c == 'c' || c == 's' || c == 't');
}

/// @brief Función para verificar si un caracter es un operador
/// @param c
/// @return
bool IngresoExpresiones::esOperador(char c){
	return (c == '+' || c == '-' || c == '*' || c == '/'|| c == '^');
}

/// @brief Función para borrar los espacios de una expresión
/// @param expresion 
/// @return 
std::string borrarEspacios(std::string expresion) {
    std::string expresionSinEspacios;

    for (char c : expresion) {
        if (c != ' ') {
            expresionSinEspacios.push_back(c);
        }
    }

    return expresionSinEspacios;
}

/// @brief Función para ordenar una expresión
/// @param expresion 
/// @return std::string
std::string ordenarExpresion(std::string expresion) {
    // Encontrar el índice del primer número negativo
    int contador = 0;
    // recorrer la expresión desde el principio hasta el final
    for(int i = 0; i <= expresion.length(); i++){
        int indiceNegativo = expresion.find_first_of("-", contador);
        contador = indiceNegativo + 1;

		if(expresion[indiceNegativo -1] == '('){
			if(isdigit(expresion[indiceNegativo + 1]) && IngresoExpresiones::esOperador(expresion[indiceNegativo + 2]) && !std::isdigit(expresion[indiceNegativo + 3]) && expresion[indiceNegativo + 3] != 'p'){
				int n = expresion[indiceNegativo + 1] - '0';
				expresion[indiceNegativo] = '0';
				expresion[indiceNegativo + 1] = '-';
				std::string part1 = expresion.substr(0, indiceNegativo);
				std::string part2 = expresion.substr(indiceNegativo + 2);

				std::string p = part1.substr(part1.length() - 1);

				part1 = part1 + std::to_string(n) + part2[0];
				part2 = part2.substr(1);
				
				part1 = part1.substr(1);
				expresion = p + "0-" + part1 + part2;
				continue;
			}
		}

        // Si no hay números negativos, retornar la expresión sin cambios
        if (indiceNegativo == std::string::npos) {
            continue;
        }

        // Si el caracter anterior es un número, entonces el número negativo no es el primero
        if (indiceNegativo > 0 && isdigit(expresion[indiceNegativo - 1])) {
            continue;
        }

        // Si el caracter anterior es un paréntesis de apertura y el anterior al paraéntesis es "c", entonces el número negativo no es el primero
        if (expresion[indiceNegativo - 1] == '(' && expresion[indiceNegativo - 2] == 'c') {
            int n = expresion[indiceNegativo + 1] - '0';
            expresion[indiceNegativo] = n + '0';
            expresion[indiceNegativo + 1] = ' ';
            expresion = borrarEspacios(expresion);
            continue;
        }

		// Si el caracter anterior es un paréntesis de apertura y el anterior al paraéntesis es "s" o "t", entonces el número negativo no es el primero
        if(expresion[indiceNegativo + 1] == 'p'){
			if (expresion[indiceNegativo - 1] == '(' && (expresion[indiceNegativo - 2] == 's' || expresion[indiceNegativo - 2] == 't')) {
				int n = expresion[indiceNegativo + 1] - '0';
				expresion[indiceNegativo] = n + '0';
				expresion[indiceNegativo + 1] = ' ';
				expresion = borrarEspacios(expresion);
				std::string part1 = expresion.substr(0, indiceNegativo);
				std::string part2 = expresion.substr(indiceNegativo + 2);
				part1 = part1 + "p)" + "n";
				expresion = part1 + part2;
				continue;
			}
		}

        // Si el caracter anterior es un paréntesis de apertura y el anterior al paraéntesis es "s" o "t", entonces el número negativo no es el primero
        if (expresion[indiceNegativo - 1] == '(' && (expresion[indiceNegativo - 2] == 's' || expresion[indiceNegativo - 2] == 't')) {
            int n = expresion[indiceNegativo + 1] - '0';
			std::string c = expresion.substr(indiceNegativo + 1, 1);
            expresion[indiceNegativo] = n + '0';
            expresion[indiceNegativo + 1] = ' ';
            expresion = borrarEspacios(expresion);
            std::string part1 = expresion.substr(0, indiceNegativo);
            std::string part2 = expresion.substr(indiceNegativo + 2);
            part1 = part1 + c + ")" + "n";
            expresion = part1 + part2;
            continue;
        }

        // Si el caracter anterior es un parentesis de apertura y el siguiente es un número y el siguiente al número es un parentesis de cierre, entonces el número negativo no es el primero
        if (expresion[indiceNegativo - 1] == '(' && isdigit(expresion[indiceNegativo + 1]) && expresion[indiceNegativo + 2] == ')') {
            continue;
        }

		// si la antes del menos hay un parentesis de apertura y el siguiente es un numero y el siguiente al numero es un operador, entonces el numero negativo no es el primero
		if (expresion[indiceNegativo - 1] == '(' && isdigit(expresion[indiceNegativo + 1]) && IngresoExpresiones::esOperador(expresion[indiceNegativo + 2]) && std::isdigit(expresion[indiceNegativo + 3])) {
			int n1 = expresion[indiceNegativo + 1] - '0';
			int n2 = expresion[indiceNegativo + 3] - '0';

			expresion[indiceNegativo] = n2 + '0';
			expresion[indiceNegativo + 1] = '-';
			expresion[indiceNegativo + 2] = n1 + '0';
			expresion[indiceNegativo + 3] = ' ';

			expresion = borrarEspacios(expresion);
			continue;
		}
    }

    return expresion;
}

/// @brief Función para ingresar una expresión matemática
/// @return std::string
std::string IngresoExpresiones::ingresoExpresion(void) {
    char *entrada = new char[25];    
    char tecla;                      
    int i = 0;                       
    int parentesisApertura = 0;      
    int parentesisCierre = 0;        
	bool eliminarEspeciales = false; 
	int caracteresEliminar= 0;       
	char elementoAnterior = '\0';    
	
    while (true) {
        tecla = getch(); 
        elementoAnterior = (i > 0) ? entrada[i - 1] : '\0'; 
		if (tecla == '\r' && i > 0) { 
            if (parentesisApertura == parentesisCierre){ 
            	break;
			}
	
        }else if (tecla == '\b' && i > 0) { 
        
		      if (elementoAnterior == 'i' || (elementoAnterior == '(' && (entrada[i - 2] == 's' || 
			                                  entrada[i - 2] == 'n' || entrada[i - 2] == 'z'))) {
		        caracteresEliminar = 4;
				if(elementoAnterior == 'i'){
		        	caracteresEliminar = 2;
		    	}else if(entrada[i - 2] == 'z'){
		    		caracteresEliminar = 5;
				}
				eliminarEspeciales = true;
		
		    } else if (esParentesis(elementoAnterior)) {
		        std::cout << "\b \b";
			    entrada[i] = 0; 
			    i--;
			    parentesisCierre -= (elementoAnterior == ')'); 
			    parentesisApertura -= (elementoAnterior == '(');
			    
		    } else {
		        std::cout << "\b \b";
		        i--;
		        entrada[i] = 0;
		    }
		
		    if (eliminarEspeciales){
		        for (int j = 1; j<=caracteresEliminar; j++){ 
		        	std::cout << "\b \b";
		        	elementoAnterior = 0;
		        	i--;
				}
				if(caracteresEliminar > 2){
					parentesisApertura--;
				}
				eliminarEspeciales = false;
			}
	
        } else if (isalpha(tecla) && (esOperador(elementoAnterior) || elementoAnterior == '('|| i == 0)) {
        
			if (esEspecial(tecla)){
			    const char* texto = "";
			    switch (tecla) {
			        case 'c':
			            entrada[i++] = 'c';
			            entrada[i++] = 'o';
			            entrada[i++] = 's';
			            texto = "os(";
			            break;
			        case 's':
			            entrada[i++] = 's';
			            entrada[i++] = 'e';
			            entrada[i++] = 'n';
			            texto = "en(";
			            break;
			        case 't':
			            entrada[i++] = 't';
			            entrada[i++] = 'a';
			            entrada[i++] = 'n';
			            texto = "an(";
			            break;
			        case 'r':
			            entrada[i++] = 'r';
			            entrada[i++] = 'a';
			            entrada[i++] = 'i';
			            entrada[i++] = 'z';
			            texto = "aiz(";
			            break;
			    	}
		        entrada[i++] = '(';
			    parentesisApertura++;
			    std::cout << tecla << texto;
					
			}else if ((tecla == 'p')){
			    entrada[i++] = tecla;
			    entrada[i++] = 'i';
			    std::cout << tecla << "i";
			}
	
        }else if(esParentesis(tecla)){
       	
        	if (tecla == '(' && (esOperador(elementoAnterior) || elementoAnterior == '(' || i == 0)) {
			    parentesisApertura++;
			    entrada[i++] = tecla;
				std::cout << tecla;
		
			} else if (tecla == ')' && elementoAnterior != '(' && !esOperador(elementoAnterior) && (isdigit(elementoAnterior) || elementoAnterior == ')'|| elementoAnterior == 'i')) {
			    parentesisCierre++;
				if(parentesisApertura>0 && parentesisCierre <= parentesisApertura){
				    entrada[i++] = tecla;
					std::cout << tecla;	
				}else{
					parentesisCierre--;
				}
			}
	
		} else if (isdigit(tecla) && elementoAnterior!= 'i' && (esOperador(elementoAnterior)|| 
		                       elementoAnterior == '(' || isdigit(elementoAnterior) || i == 0)){
			entrada[i++] = tecla;
			std::cout << tecla;
	
		} else if(esOperador(tecla) && !esOperador(elementoAnterior) && tecla != '-' && (elementoAnterior!='(' || i>0)){	
			entrada[i++] = tecla;
			std::cout << tecla;
	
		} else if(tecla == '-' && !esOperador(elementoAnterior)){
			entrada[i++] = tecla;
			std::cout << tecla;
		}
    }
    entrada[i] = '\0';

	std::string entradaString(entrada);
	delete[] entrada;
	
	entradaString.erase(std::remove_if(entradaString.begin(), entradaString.end(), isspace), entradaString.end());
	
	entradaString = std::regex_replace(entradaString, std::regex("sen"), "s");
	entradaString = std::regex_replace(entradaString, std::regex("cos"), "c");
	entradaString = std::regex_replace(entradaString, std::regex("tan"), "t");
	entradaString = std::regex_replace(entradaString, std::regex("pi"), "p");

	std::string entradaCorrecta;
	if (entradaString[0] == '-' || entradaString[0] == '+') {
        entradaCorrecta += "0";
    }
    entradaCorrecta += entradaString;
	
	entradaCorrecta = ordenarExpresion(entradaCorrecta);

	return entradaCorrecta;
}