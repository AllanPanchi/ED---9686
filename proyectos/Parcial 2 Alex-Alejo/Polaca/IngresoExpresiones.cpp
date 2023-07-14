#include "IngresoExpresiones.h"
#include <conio.h> //getch()
#include <iostream>
#include <regex>
#include <cctype>
#include <string>
#include <cstdlib>
#include <conio.h>

bool IngresoExpresiones::esParentesis(char tecla){
	return (tecla == '('|| tecla == ')');
} 

bool IngresoExpresiones::esEspecial(char tecla){
	return(tecla == 'c' || tecla == 's' ||tecla == 'r'  || tecla == 't');
}

bool IngresoExpresiones::esOperador(char tecla){
	return (tecla == '+' || tecla == '-' || tecla == '*' || tecla == '/'|| tecla == '^');
}

std::string borrarEspacios(std::string expresion) {
    std::string expresionSinEspacios;

    for (char c : expresion) {
        if (c != ' ') {
            expresionSinEspacios.push_back(c);
        }
    }

    return expresionSinEspacios;
}

std::string ordenarExpresion(std::string expresion) {
    // Encontrar el índice del primer número negativo
    int contador = 0;
    // recorrer la expresión desde el principio hasta el final
    for(int i = 0; i <= expresion.length(); i++){
        int indiceNegativo = expresion.find_first_of("-", contador);
        contador = indiceNegativo + 1;

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
		if (expresion[indiceNegativo - 1] == '(' && isdigit(expresion[indiceNegativo + 1]) && IngresoExpresiones::esOperador(expresion[indiceNegativo + 2])) {
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

std::string IngresoExpresiones::ingresoExpresion(void) {
    char *entrada = new char[25];    //Arreglo dinámico para la entrada
    char tecla;                      //Caracter de entrada
    int i = 0;                       //Contador de caracteres
    int parentesisApertura = 0;      //Contador de paréntesis de apertura
    int parentesisCierre = 0;        //Contador de paréntesis de cierre
	bool eliminarEspeciales = false; //Verificador de eliminación de sin(, cos(, tan(, raiz( y pi
	int caracteresEliminar= 0;       //Cantidad de caracteres de expresiones especiales para eliminar
	char elementoAnterior = '\0';    //Caracter anterior al actual
	
    while (true) {
        tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
        elementoAnterior = (i > 0) ? entrada[i - 1] : '\0'; //Guarda el elemento anterior del arreglo de la entrada
    // Si el usuario presiona Enter
		if (tecla == '\r' && i > 0) { 
            if (parentesisApertura == parentesisCierre){ // Validar que se encuentren cerrados todos los paréntesis
            	break;
			}
	// si el usuario presiona Backspace y hay caracteres en la entrada
        }else if (tecla == '\b' && i > 0) { 
        // Si el elemento a borrar es pi, sin(, cos(, tan( o raiz(
		      if (elementoAnterior == 'i' || (elementoAnterior == '(' && (entrada[i - 2] == 's' || 
			                                  entrada[i - 2] == 'n' || entrada[i - 2] == 'z'))) {
		        caracteresEliminar = 4;
				if(elementoAnterior == 'i'){
		        	caracteresEliminar = 2;
		    	}else if(entrada[i - 2] == 'z'){
		    		caracteresEliminar = 5;
				}
				eliminarEspeciales = true;
		//Si el usuario borra únicamente un paréntesis
		    } else if (esParentesis(elementoAnterior)) {
		        std::cout << "\b \b";
			    entrada[i] = 0; // elimina el último caracter de la entrada
			    i--;
			    parentesisCierre -= (elementoAnterior == ')'); //Disminución de contadores
			    parentesisApertura -= (elementoAnterior == '(');
		//Si el usuario intneta eliminar cualquier caracter fuera de las categorías anteriores	    
		    } else {
		        std::cout << "\b \b";
		        i--;
		        entrada[i] = 0;// elimina el último caracter de la entrada
		    }
		// Condicional para eliminar elementos especiales sin(, cos(, tan(, raiz(, pi
		    if (eliminarEspeciales){
		        for (int j = 1; j<=caracteresEliminar; j++){ //Elimina la cantidad de caracteres según la funci´n
		        	std::cout << "\b \b";
		        	elementoAnterior = 0;
		        	i--;
				}
				if(caracteresEliminar > 2){
					parentesisApertura--;
				}
				eliminarEspeciales = false;
			}
	// Si el usuario ingresa una letra que además puede ser el primer caracter o puede precedida por un operador o paréntesis de apertura
        } else if (isalpha(tecla) && (esOperador(elementoAnterior) || elementoAnterior == '('|| i == 0)) {
        // Si la legra es 's', 'c', 't' o 'r'
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
		//Si la letra es 'p'			
			}else if ((tecla == 'p')){
			    entrada[i++] = tecla;
			    entrada[i++] = 'i';
			    std::cout << tecla << "i";
			}
	//Si el usuario ingresa un paréntesis
        }else if(esParentesis(tecla)){
       	//Paréntesis de apertura: puede ser el primer caracter o puede ser precedido por un operador u otro paréntesis de apertura
        	if (tecla == '(' && (esOperador(elementoAnterior) || elementoAnterior == '(' || i == 0)) {
			    parentesisApertura++;
			    entrada[i++] = tecla;
				std::cout << tecla;
		//Paréntesis de cierre: no puede ser precedido por uno de apertura o un operador pero si por un número, otro paréntesis de cierre o pi
			} else if (tecla == ')' && elementoAnterior != '(' && !esOperador(elementoAnterior) && (isdigit(elementoAnterior) || elementoAnterior == ')'|| elementoAnterior == 'i')) {
			    parentesisCierre++;
				if(parentesisApertura>0 && parentesisCierre <= parentesisApertura){
				    entrada[i++] = tecla;
					std::cout << tecla;	
				}else{
					parentesisCierre--;
				}
			}
	//Si el usuario ingresa un número entonces no puede ser precedido por pi pero si por 
	//un operador, un paréntesis de apertura u otro número, así también puede ser el primer caracter de la expresión
		} else if (isdigit(tecla) && elementoAnterior!= 'i' && (esOperador(elementoAnterior)|| 
		                       elementoAnterior == '(' || isdigit(elementoAnterior) || i == 0)){
			entrada[i++] = tecla;
			std::cout << tecla;
	//Si el usuario ingresa un operador entonces no puede ser precedido por otro operador
	//a excepción del '-' (menos) los operadores no pueden ser precedidos por un paréntesis de apertura ni ser el primer caracter de la expresión
		} else if(esOperador(tecla) && !esOperador(elementoAnterior) && tecla != '-' && (elementoAnterior!='(' || i>0)){	
			entrada[i++] = tecla;
			std::cout << tecla;
	//Si el usuario ingresa un signo negativo entonces solo no puede ser precedido por otro operador
		} else if(tecla == '-' && !esOperador(elementoAnterior)){
			entrada[i++] = tecla;
			std::cout << tecla;
		}
    }
    entrada[i] = '\0';

	// Tranformar arreglo de caracteres a std::string
	std::string entradaString(entrada);
	delete[] entrada;
	
	// Eliminar espacios en blanco
	entradaString.erase(std::remove_if(entradaString.begin(), entradaString.end(), isspace), entradaString.end());
	
	// Reemplazar sen, cos y tan por s, c y t respectivamente
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