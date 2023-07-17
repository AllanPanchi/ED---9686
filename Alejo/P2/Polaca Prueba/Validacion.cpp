#include "ValidacionDatos.h"
#include <cstdlib>
#include <conio.h>
#include <regex>
#include <stack>
#include <cctype>

class Validacion : public ValidacionDatos
{
public:

    std::string validarEntradaOperacion() override
    {
        std::string entradaCorrecta;

        std::regex patron("^(\\s*([-|+]\\s)?(\\d+\\.?\\d*|((sen|cos|tan) \\(\\s*(\\d+\\.?\\d*)\\s*\\))))(\\s*[+\\-\\*\\/\\^]\\s(\\d+\\.?\\d*|((sen|cos|tan) \\(\\s*(\\d+\\.?\\d*)\\s*\\))))*$");

        std::string entrada;
        std::cout << "Ingrese la expresion matematica en notacion infija separada por espacios: ";
        std::getline(std::cin, entrada);

        entrada = std::regex_replace(entrada, std::regex("^\\s+|\\s+$"), "");

        // validar con ciclo while que haya la misma cantidad de "(" y ")"
        while (!esParentesisEquilibrado(entrada))
        {
            std::cout << "La expresion no es valida. Ingrese nuevamente: ";
            std::getline(std::cin, entrada);
            entrada = std::regex_replace(entrada, std::regex("^\\s+|\\s+$"), "");
        }
        
        while (!std::regex_match(entrada, patron))
        {
            std::cout << "La expresion no es valida. Ingrese nuevamente: ";
            std::getline(std::cin, entrada);
            entrada = std::regex_replace(entrada, std::regex("^\\s+|\\s+$"), "");
        }

        entrada = std::regex_replace(entrada, std::regex("sen"), "s");
        entrada = std::regex_replace(entrada, std::regex("cos"), "c");
        entrada = std::regex_replace(entrada, std::regex("tan"), "t");

        // si la expresion empieza con un operador unario, agregar un 0 al inicio
        if (entrada[0] == '-' || entrada[0] == '+') {
            entradaCorrecta += "0 ";
        }
        entradaCorrecta += entrada;

        std::cout << "Expresion ingresada: " << entradaCorrecta << std::endl;

        return entradaCorrecta;

    }

    bool esParentesisEquilibrado(const std::string& expresion) override
    {
         std::stack<char> pila;

    for (char c : expresion) {
        if (c == '(') {
            pila.push(c);
        } else if (c == ')') {
            if (pila.empty() || pila.top() != '(') {
                return false;
            }
            pila.pop();
        }
    }

    return pila.empty();
        
    }

    
    bool esCaracterValido(char c) override{
        return isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == ' ' || c == '(' || c == ')' || c == 's' || c == 'c' || c == 't' || c == 'r';
        
    }


    bool esExpresionValida(const std::string& expresion) override{
    std::string expresionModificada;

    for (char c : expresion) {
        if (c == 's' || c == 'c' || c == 't') {
            if (expresionModificada.empty() || expresionModificada.back() != ' ') {
                return false;
            }

            expresionModificada.push_back(c);
        } else {
            expresionModificada.push_back(c);
        }
    }

    char prev = ' ';
    bool funcionVista = false;
    bool parentesisAbierto = false;

    for (char c : expresionModificada) {
        if (c == ' ') {
            if (prev == ' ' || prev == '(' || prev == ')' || prev == '-' || prev == 's' || prev == 'c' || prev == 't' || prev == 'r') {
                return false;
            }
            continue;
        } else if (c == '-') {
            if (!isdigit(prev) && prev != ')' && prev != ' ') {
                return false;
            }
        } else if (!esCaracterValido(c)) {
            return false;
        } else if (c == 's' || c == 'c' || c == 't') {
            // Verificar que las funciones tengan paréntesis de apertura y cierre
            if (prev != '(') {
                return false;
            }

            int funcionLength = 0;

            if (c == 's') {
                // Para "sen"
                funcionLength = 2;
            } else {
                // Para "cos" y "tan"
                funcionLength = 3;
            }

            std::string funcion = expresionModificada.substr(funcionLength);

            // Verificar si hay un espacio después de la función
            if (funcion.empty() || funcion[0] != ' ') {
                return false;
            }

            // Verificar si hay un paréntesis de cierre después de la función
            if (funcion.length() < 2 || funcion[1] != ')') {
                return false;
            }

            funcionVista = true;
        } else if (c == 'r') {
            // Verificar que la función "raiz" tenga paréntesis de apertura y cierre
            if (prev != '(') {
                return false;
            }

            std::string funcion = expresionModificada.substr(4);

            // Verificar si hay un espacio después de la función
            if (funcion.empty() || funcion[0] != ' ') {
                return false;
            }

            // Verificar si hay un paréntesis de cierre después de la función
            if (funcion.length() < 2 || funcion[1] != ')') {
                return false;
            }

            funcionVista = true;
        } else if (isdigit(c)) {
            if (isdigit(prev) || prev == ')' || prev == 's' || prev == 'c' || prev == 't' || prev == 'r') {
                return false;
            }
            funcionVista = false;
        } else if (c == '(') {
            if (isdigit(prev) || prev == ')' || prev == ' ') {
                return false;
            }
            parentesisAbierto = true;
        } else if (c == ')') {
            if (!isdigit(prev) && prev != ')' && prev != ' ') {
                return false;
            }
            parentesisAbierto = false;
        }

        prev = c;
    }

    if (funcionVista || parentesisAbierto) {
        return false;
    }

    return true;
       
    }
    
    bool esExpresionBalanceada(const std::string& expresion) override{

        std::stack<char> pila;
    
        for (char c : expresion) {
            if (c == '(') {
                pila.push(c);
            } else if (c == ')') {
                if (pila.empty() || pila.top() != '(') {
                    return false;
                }
                pila.pop();
            }
        }
        
        return pila.empty();
        }

};