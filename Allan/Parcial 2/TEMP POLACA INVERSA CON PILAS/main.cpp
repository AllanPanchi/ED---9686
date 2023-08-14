#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(T value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    T pop() {
        if (head == nullptr) {
            throw std::runtime_error("Pila vacía");
        }

        T value = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return value;
    }

    T top() const {
        if (head == nullptr) {
            throw std::runtime_error("Pila vacía");
        }
        return head->data;
    }

    bool empty() const {
        return head == nullptr;
    }
};

bool esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int obtenerPrioridad(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

std::string convertirRPN(const std::string& expresion) {
    LinkedList<char> pila;
    std::stringstream rpnPrefija;
    std::stringstream rpnPostfija;

    for (char c : expresion) {
        if (std::isdigit(c)) {
            rpnPrefija << c;
            rpnPostfija << c;
        } else if (c == '(') {
            pila.push(c);
            rpnPrefija << c;
            rpnPostfija << c;
        } else if (c == ')') {
            while (!pila.empty() && pila.top() != '(') {
                rpnPrefija << ' ' << pila.top();
                rpnPostfija << pila.top() << ' ';
                pila.pop();
            }
            if (!pila.empty() && pila.top() == '(') {
                pila.pop();
            }
            rpnPrefija << c;
            rpnPostfija << c;
        } else if (esOperador(c)) {
            while (!pila.empty() && esOperador(pila.top()) && obtenerPrioridad(pila.top()) >= obtenerPrioridad(c)) {
                rpnPrefija << ' ' << pila.top();
                rpnPostfija << pila.top() << ' ';
                pila.pop();
            }
            pila.push(c);
            rpnPrefija << c << ' ';
            rpnPostfija << ' ';
        } else if (std::isalpha(c)) {
            std::string funcion;
            funcion += c;
            while (std::isalpha(expresion[++c])) {
                funcion += expresion[c];
            }
            if (funcion == "sin" || funcion == "cos" || funcion == "tan") {
                pila.push('(');
                rpnPrefija << funcion << ' ';
            }
        }
    }

    while (!pila.empty()) {
        rpnPrefija << ' ' << pila.top();
        rpnPostfija << pila.top() << ' ';
        pila.pop();
    }

    return rpnPrefija.str() + "\n" + rpnPostfija.str();
}

double resolverRPN(const std::string& rpn) {
    LinkedList<double> pila;

    std::stringstream ss(rpn);
    std::string token;
    while (ss >> token) {
        if (std::isdigit(token[0])) {
            double numero = std::stod(token);
            pila.push(numero);
        } else if (esOperador(token[0])) {
            double segundoOperando = pila.pop();
            double primerOperando = pila.pop();

            double resultado;
            switch (token[0]) {
                case '+':
                    resultado = primerOperando + segundoOperando;
                    break;
                case '-':
                    resultado = primerOperando - segundoOperando;
                    break;
                case '*':
                    resultado = primerOperando * segundoOperando;
                    break;
                case '/':
                    resultado = primerOperando / segundoOperando;
                    break;
            }

            pila.push(resultado);
        } else if (std::isalpha(token[0])) {
            if (token == "sin") {
                double angulo = pila.pop();
                double resultado = sin(angulo * M_PI / 180.0);
                pila.push(resultado);
            } else if (token == "cos") {
                double angulo = pila.pop();
                double resultado = cos(angulo * M_PI / 180.0);
                pila.push(resultado);
            } else if (token == "tan") {
                double angulo = pila.pop();
                double resultado = tan(angulo * M_PI / 180.0);
                pila.push(resultado);
            }
        }
    }

    return pila.pop();
}

int main() {
    std::string expresion;
    std::cout << "Ingrese la expresion en notacion infija: ";
    std::getline(std::cin, expresion);

    std::string rpn = convertirRPN(expresion);
    double resultado = resolverRPN(rpn);

    std::cout << "Notacion Polaca Prefija:\n" << rpn << std::endl;
    std::cout << "Notacion Polaca Postfija:\n" << rpn << std::endl;
    std::cout << "Resultado: " << resultado << std::endl;

    return 0;
}
