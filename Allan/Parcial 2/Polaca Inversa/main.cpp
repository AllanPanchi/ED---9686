#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

bool esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluarPolacaPrefija(string expresion) {
    stack<int> pila;

    for (int i = expresion.length() - 1; i >= 0; i--) {
        char caracter = expresion[i];
        if(isspace(caracter))
            continue;
        else if (esOperador(caracter)) {
            int a = pila.top();
            pila.pop();
            int b = pila.top();
            pila.pop();

            switch (caracter) {
                case '+':
                    pila.push(a + b);
                    break;
                case '-':
                    pila.push(a - b);
                    break;
                case '*':
                    pila.push(a * b);
                    break;
                case '/':
                    pila.push(a / b);
                    break;
            }
        } else {
            // Es un operando, convertirlo a entero y agregarlo a la pila
            int valor = caracter - '0';
            pila.push(valor);
        }
    }

    return pila.top();
}

int main() {
    string expresion;
    cout << "Ingrese una expresión en notación polaca inversa prefija: ";
    getline(cin, expresion);

    int resultado = evaluarPolacaPrefija(expresion);
    cout << "El resultado es: " << resultado << endl;

    return 0;
}
