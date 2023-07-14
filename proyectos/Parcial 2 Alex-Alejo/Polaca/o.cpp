#include <iostream>
#include <string>

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
        if (expresion[indiceNegativo - 1] == '(' && (expresion[indiceNegativo - 2] == 's' || expresion[indiceNegativo - 2] == 't')) {
            int n = expresion[indiceNegativo + 1] - '0';
            expresion[indiceNegativo] = n + '0';
            expresion[indiceNegativo + 1] = ' ';
            expresion = borrarEspacios(expresion);
            std::string part1 = expresion.substr(0, indiceNegativo);
            std::string part2 = expresion.substr(indiceNegativo + 2);
            part1 = part1 + "1)" + "*(-1)";
            expresion = part1 + part2;
            continue;
        }

        // Si el caracter anterior es un parentesis de apertura y el siguiente es un número y el siguiente al número es un parentesis de cierre, entonces el número negativo no es el primero
        if (expresion[indiceNegativo - 1] == '(' && isdigit(expresion[indiceNegativo + 1]) && expresion[indiceNegativo + 2] == ')') {
            continue;
        }
        
        int n1 = expresion[indiceNegativo + 1] - '0';
        int n2 = expresion[indiceNegativo + 3] - '0';

        expresion[indiceNegativo] = n2 + '0';
        expresion[indiceNegativo + 1] = '-';
        expresion[indiceNegativo + 2] = n1 + '0';
        expresion[indiceNegativo + 3] = ' ';

        expresion = borrarEspacios(expresion);
    }

    return expresion;
}

int main() {
    std::string expresion = "(-2+3)*s(-1)*(-2+3)";
    std::string expresionOrdenada = ordenarExpresion(expresion);
    std::cout << expresionOrdenada << std::endl;

    return 0;
}
