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
#include "OperacionPolaca.h"
#include "Operaciones.cpp"
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <sstream>

/// @brief Verifica si un carácter es un operador
/// @param c 
/// @return bool
bool esOperador(char c) {
    return (c == 'n' || c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 's' || c == 'c' || c == 't');
}

/// @brief Obtiene la precedencia de un operador(Orden de operaciones)
/// @param operador 
/// @return int
int obtenerPrecedencia(char operador) {
    if (operador == '+' || operador == '-')
        return 1;
    else if (operador == '*' || operador == '/')
        return 2;
    else if (operador == '^')
        return 3;
    else if (operador == 's' || operador == 'c' || operador == 't')
        return 4;
    return 0;
}

///@brief Realiza la operación aritmética dada dos operandos y un operador
///@param op1
///@param op2
///@param operador
///@return double
double realizarOperacion(double op1, double op2, char operador) {
    Operaciones operaciones = Operaciones();
    if (operador == '+')
        return op1 + op2;
    else if (operador == '-')
        return op1 - op2;
    else if (operador == '*')
        return op1 * op2;
    else if (operador == '/')
        return op1 / op2;
    else if (operador == '^')
        return operaciones.potencia(op1, op2);
    else if (operador == 's')
        return operaciones.seno(op1);
    else if (operador == 'c')
        return operaciones.coseno(op1);
    else if (operador == 't')
        return operaciones.tangente(op1);
    
    return 0.0;
}

/// @brief Convierte una expresión algebraica en notación polaca prefija
/// @param expresion 
/// @return std::string
std::string aPrefija(std::string expresion) {
    std::stack<char> pilaOperadores;
    std::string resultado;

    for (int i = expresion.length() - 1; i >= 0; i--) {
        char caracter = expresion[i];

        if (esOperador(caracter)) {
            while (!pilaOperadores.empty() && obtenerPrecedencia(pilaOperadores.top()) > obtenerPrecedencia(caracter)) {
                resultado = pilaOperadores.top() + resultado;
                pilaOperadores.pop();
            }
            pilaOperadores.push(caracter);
        }
        else if (caracter == ')') {
            pilaOperadores.push(caracter);
        }
        else if (caracter == '(') {
            while (!pilaOperadores.empty() && pilaOperadores.top() != ')') {
                resultado = pilaOperadores.top() + resultado;
                pilaOperadores.pop();
            }
            if (!pilaOperadores.empty())
                pilaOperadores.pop(); // Eliminar el paréntesis de apertura
        }
        else {
            resultado = caracter + resultado;
        }
    }

    while (!pilaOperadores.empty()) {
        resultado = pilaOperadores.top() + resultado;
        pilaOperadores.pop();
    }

    return resultado;
}

/// @brief Convierte una expresión algebraica en notación polaca postfija
/// @param expresion 
/// @return std::string
std::string aPostfija(const std::string& expresion) {
    std::string postfija;
    std::stack<char> pila;

    // Recorre la expresión de izquierda a derecha
    for (char c : expresion) {
        // Si es un carácter alfanumérico o un operador de función, agrégalo a la expresión postfija
        if (!esOperador(c) && c != '(' && c != ')') {
            postfija += c;
        }
        // Si es un operador
        else if (esOperador(c)) {
            // Desapila los operadores de mayor o igual precedencia
            while (!pila.empty() && obtenerPrecedencia(pila.top()) >= obtenerPrecedencia(c)) {
                postfija += pila.top();
                pila.pop();
            }
            pila.push(c); // Apila el operador actual
        }
        // Si es un paréntesis de apertura, apílalo
        else if (c == '(') {
            pila.push(c);
        }
        // Si es un paréntesis de cierre, desapila hasta encontrar el paréntesis de apertura correspondiente
        else if (c == ')') {
            while (!pila.empty() && pila.top() != '(') {
                postfija += pila.top();
                pila.pop();
            }
            pila.pop(); // Elimina el paréntesis de apertura correspondiente
        }
    }

    // Desapila los operadores restantes y los agrega a la expresión postfija
    while (!pila.empty()) {
        postfija += pila.top();
        pila.pop();
    }

    return postfija;
}

/// @brief Evalúa una expresión en notación polaca prefija y devuelve el resultado
/// @param expresion 
/// @return 
double evaluarPrefija(const std::string& expresion) {
    std::stack<double> pila;

    // Recorre la expresión desde el final hasta el inicio
    for (int i = expresion.length() - 1; i >= 0; i--) {
        char c = expresion[i];

        // Si es un operador, desapila los operandos, realiza la operación y apila el resultado
        if (esOperador(c)) {
            double op1, op2;

            if (c == 's' || c == 'c' || c == 't') {
                op1 = pila.top();
                pila.pop();
                pila.push(realizarOperacion(op1, 0, c));
            } else {
                op1 = pila.top();
                pila.pop();
                op2 = pila.top();
                pila.pop();
                pila.push(realizarOperacion(op1, op2, c));
            }
        }
        // Si es un número, conviértelo a double y apílalo
        else if (std::isdigit(c)) {
            double numero = c - '0';
            pila.push(numero);
        }

        else if (c == 'p'){
            pila.push(3.141592653589793238463);

        }
    }

    // El elemento restante en la pila será el resultado final
    return pila.top();
}

/// @brief Evalúa una expresión en notación polaca postfija y devuelve el resultado
/// @param expresion 
/// @return double
double evaluarPostfija(const std::string& expresion) {
    std::stack<double> pila;

    // Recorre la expresión de izquierda a derecha
    for (int i = 0; i < expresion.length(); i++) {
        char c = expresion[i];
        // Si es un operador, desapila los operandos, realiza la operación y apila el resultado
        if (esOperador(c)) {
            double op1, op2;

            if(c == 'n' && isdigit(expresion[i-2])){
                double num = expresion[i-2] - '0';
                num = num * -1;
                pila.push(realizarOperacion(num, 0, expresion[i-1]));
            }

            else if (c == 'n' && expresion[i-2] == 'p'){
                double num = -3.141592653589793238463;
                pila.push(realizarOperacion(num, 0, expresion[i-1]));
            }

            else if (c == 's' || c == 'c' || c == 't') {
                op1 = pila.top();
                pila.pop();
                pila.push(realizarOperacion(op1, 0, c));
            } else {
                op2 = pila.top();
                pila.pop();
                op1 = pila.top();
                pila.pop();
                pila.push(realizarOperacion(op1, op2, c));
            }
        }
        // Si es un número, conviértelo a double y apílalo
        else if (std::isdigit(c)) {
            double numero = c - '0';
            pila.push(numero);
        }

        else if (c == 'p'){
            pila.push(3.141592653589793238463);

        }
    }

    // El elemento restante en la pila será el resultado final
    return pila.top();
}

/// @brief Realiza la operacion polaca prefija
/// @param operacion 
void OperacionPolaca::operacionPolacaPrefija(std::string operacion)
{

    std::string operacionPrefija;
    float resultado;
    std::cout << "Operacion Polaca Prefija: " << std::endl;
    if(operacion.find_first_of("sct") != std::string::npos){
        operacionPrefija = aPostfija(operacion);
        resultado = evaluarPostfija(operacionPrefija);
    } else
    {
        operacionPrefija = aPrefija(operacion);
        resultado = evaluarPrefija(operacionPrefija);
    }

    std::cout << aPrefija(operacion) << std::endl;
    std::cout << "Resultado: " << resultado << std::endl;
}

/// @brief Realiza la operacion polaca postfija
/// @param operacion 
void OperacionPolaca::operacionPolacaPostfija(std::string operacion)
{
    std::string operacionPostfija;
    std::cout << "\nOperacion Polaca Postfija: " << std::endl;
    operacionPostfija = aPostfija(operacion);
    float resultado = evaluarPostfija(operacionPostfija);
    
    std::cout << operacionPostfija << std::endl;
    std::cout << "Resultado: " << resultado << std::endl;
}

void OperacionPolaca::funcion(const std::string& entrada)
{
    Lista<int> lista = Lista<int>();
    std::stack<double> pila;
    Lista<int> lista2 = Lista<int>();
    int op1, op2;
    std::string resultado;
    int contador1 = 2, contador2 = 4;
    int s1 = 0, s2 = 0;
    int ca1 = 0, ca2 = 0;
    int ca = 0;
    int j = 0;

    for(int i = 0; contador2 < entrada.length(); i++){
        
        contador1 = 2 + i*8;
        contador2 = 4 + i*8;
        lista2.insertar(contador1);
        lista2.insertar(contador2);
        
    }

    for(int i = 0; i < entrada.length()-1; i++){
        char c = entrada.at(i);

        if (esOperador(c) && op1 != 0 && op2 != 0){
            int r;
            if((i+2) <= entrada.length() - 1){
                r = realizarOperacion(op1, op2, entrada.at(i+2));

            } else {
                r = 0;
            }
            pila.pop();
            pila.pop();

            if(lista2.buscar(i+1)){
                
                if (r == 0 && (i + 2) >= entrada.length() - 1){
                    resultado = resultado + " " + std::to_string(op1);
                } else {
                    resultado = resultado + " " + std::to_string(r);
                }
            } else {
                continue;
            }

            // if((i + 1) == contador1 || (i + 1) == contador2 || (i + 1) == entrada.length() - 1){
            //     if((i+1) != ca1 && (i+1) != ca2){
            //         j++;
            //         c++;
            //     }
            //     if (r == 0 && (i + 2) >= entrada.length() - 1){
            //         resultado = resultado + " " + std::to_string(op1);
            //     } else {
            //         resultado = resultado + " " + std::to_string(r);
            //     }
            // } else {
            //     continue;
            // }
            op1 = 0;
            op2 = 0;
        }
        if (std::isdigit(c)) {
            op1 = c - '0';
            if((i+4) <= entrada.length() - 1){
                op2 = entrada.at(i+4) - '0';
            } else {
                if((i+2) <= entrada.length() - 1){
                    op2 = entrada.at(i+2) - '0';
                } else {
                    op2 = 0;
                }
                
            }
            pila.push(op1);
            pila.push(op2);
            // contador1 = 2 + j*8;
            // contador2 = 4 + j*8;
            // ca1 = 1 + ca*4;
            // ca2 = 2 + ca*4;
            
        } else {
            op1 = 0;
            op2 = 0;
        }
    }
    std::cout << resultado << std::endl;
}