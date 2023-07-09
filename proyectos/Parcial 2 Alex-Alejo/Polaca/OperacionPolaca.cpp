
#include "OperacionPolaca.h"
#include "Operaciones.cpp"
#include <iostream>
#include <stack>
#include <cstring>
#include <cctype>

bool esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 's' || c == 'c' || c == 't');
}

int prioridad(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

std::string infija_a_postfija(std::string expresion) {
    std::string postfija = "";
    std::stack<char> pila;

    for (size_t i = 0; i < expresion.length(); i++) {
        char caracter = expresion[i];

        if (isdigit(caracter) || (caracter == '-' && (i == 0 || !isdigit(expresion[i - 1])))) {
            // Si el caracter es un dígito o un signo negativo seguido de un número, lo agregamos a la salida
            postfija += caracter;
        } else if (esOperador(caracter)) {
            // Si el caracter es un operador, desalojamos los operadores de mayor o igual prioridad de la pila y los agregamos a la salida
            while (!pila.empty() && esOperador(pila.top()) && prioridad(pila.top()) >= prioridad(caracter)) {
                postfija += pila.top();
                pila.pop();
            }
            pila.push(caracter);
        } else if (caracter == '(') {
            // Si el caracter es un paréntesis de apertura, lo agregamos a la pila
            pila.push(caracter);
        } else if (caracter == ')') {
            // Si el caracter es un paréntesis de cierre, desalojamos los operadores de la pila hasta encontrar el paréntesis de apertura
            while (!pila.empty() && pila.top() != '(') {
                postfija += pila.top();
                pila.pop();
            }
            pila.pop(); // Desalojamos el paréntesis de apertura
        }
    }

    // Desalojamos cualquier operador restante de la pila y lo agregamos a la salida
    while (!pila.empty()) {
        postfija += pila.top();
        pila.pop();
    }

    return postfija;
}

double evaluar_postfija(std::string postfija) {
    std::stack<double> pila;
    Operaciones operaciones = Operaciones();

    for (size_t i = 0; i < postfija.length(); i++) {
        char caracter = postfija[i];

        if (isdigit(caracter)) {
            // Si el caracter es un dígito, lo convertimos a número y lo agregamos a la pila
            pila.push(caracter - '0');
        } else if (esOperador(caracter)) {
            // Si el caracter es un operador, evaluamos el operador con los dos últimos valores de la pila
            double op2 = pila.top();
            pila.pop();
            double op1 = pila.top();
            pila.pop();

            double resultado = 0.0;
            switch (caracter) {
                case '+':
                    resultado = op1 + op2;
                    break;
                case '-':
                    resultado = op1 - op2;
                    break;
                case '*':
                    resultado = op1 * op2;
                    break;
                case '/':
                    resultado = op1 / op2;
                    break;
                case '^':
                    resultado = operaciones.potencia(op1, op2);
                    break;
                case 's':
                    resultado = operaciones.seno(op1);
                    break;
                case 'c':
                    resultado = operaciones.coseno(op1);
                    break;
                case 't':
                    resultado = operaciones.tangente(op1);
                    break;
            }

            pila.push(resultado);
        }
    }

    // El resultado final se encuentra en la cima de la pila
    return pila.top();
}

std::string invertir_expresion(std::string expresion) {
    std::string invertida = "";

    for (int i = expresion.length() - 1; i >= 0; i--) {
        if (expresion[i] == '(')
            invertida += ')';
        else if (expresion[i] == ')')
            invertida += '(';
        else
            invertida += expresion[i];
    }

    return invertida;
}

void OperacionPolaca::operacionPolacaPrefija(std::string operacion)
{
    std::string op = operacion;
    std::cout << "Operacion Polaca Prefija: " << std::endl;
    op = invertir_expresion(operacion);
    op = infija_a_postfija(op);
    operacion = infija_a_postfija(operacion);
    float resultado = evaluar_postfija(operacion);

    std::cout << op << std::endl;
    std::cout << "Resultado: " << resultado << std::endl;
}

void OperacionPolaca::operacionPolacaPostfija(std::string operacion)
{
    std::cout << "Operacion Polaca Postfija: " << std::endl;
    operacion = infija_a_postfija(operacion);
    float resultado = evaluar_postfija(operacion);
    
    std::cout << operacion << std::endl;
    std::cout << "Resultado: " << resultado << std::endl;
}