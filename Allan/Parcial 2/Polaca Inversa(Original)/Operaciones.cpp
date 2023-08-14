/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
		INGENIERA DE SOFTWARE
                
	AUTORES:
		-Luis Burbano
        -Mateo Condor
        -Camila Morales
        -Ricardo Rivadeneira
        -Steven Pozo
        -Jairo Quilumbaquin
        -Edwin Cantuña

	FECHA DE CREACION:
		26/12/2022       	
	FECHA DE MODIFICACION:
		05/01/2023
*/

#pragma once
#include <string>
#include <math.h>

#include "Pila.hpp"

class Operaciones {
public:

    //Metodo validar Operadores
    bool operadores(string c) {
        if (c == "+" || c == "-" || c == "*" || c == "/" || c == "%" || c == "^") {
            return true;
        }
        return false;
    }

    //Metodo para funciones trigonom�ticas
    bool funTrigonometrica(string c) {
        if (c == "sen" || c == "cos" || c == "tan" || c == "senh" || c == "cosh" || c == "tanh" || c == "raiz") {
            return true;
        }
        return false;
    }

    //Metodo para verificar la prioridad de los operadores
    int prioridad(string c) {
        if (c == "^" || c == "raiz")
            return 3;
        else if (c == "%")
            return 2;
        else if (c == "*" || c == "/")
            return 2;
        else if (c == "+" || c == "-")
            return 1;
        else
            return -1;
    }

    //Metodo para copiar pila
    Pila<string> copiarPila(Pila<string> datos) {
        Nodo<string>* dato = datos.getPrimero();
        Pila<string> datos1;
        string aux;
        while (dato) {
            aux = dato->getValor();
            datos1.Push(aux);
            dato = dato->getSiguiente();

        }
        return datos1;
    }

    //Metodo para sustraer  
    string sustraer(string cad, int posInicial, int numCaracter) {

        string cadenaSub;
        int contador = 0;

        for (char& c : cad) {
            if (contador >= posInicial && contador < (posInicial + numCaracter)) {
                if (c == ' ') {
                    cadenaSub += " ";
                }
                else {
                    cadenaSub += c;
                }
            }
            contador++;
        }
        return cadenaSub;
    }

    //Metodo para comprobar si es un numero
    bool numero(string cad) {
        int punto = 0;
        int caract = 0;
        int negativo = 0;

        if (cad == "pi") {
            return true;
        }

        for (char& c : cad) {
            if (c == '.') {
                punto++;
            }
            else if (c == '-') {
                negativo++;
            }
            else if (c > '9' || c < '0') {
                caract++;
            }
        }

        if (punto > 1) {
            return false;
        }

        if (negativo > 1) {
            return false;
        }
        else if (negativo == 1 && sustraer(cad, 0, 1) != "-") {
            return false;
        }

        if (negativo == 1 && cad.length() == 1) {
            return false;
        }

        if (caract > 0) {
            return false;
        }
        return true;
    }

    ///////////////////////////CALCULAR VALOR///////////////////////////

   //Metodo para Invertir Pila
    Pila<string> invertirPila(Pila<string> datos) {

        Nodo<string>* dato = datos.getPrimero();
        Pila<string> datos1;
        string aux;

        while (!datos.PilaVacia()) {
            aux = datos.getPrimero()->getValor();
            datos.Pop();
            datos1.Push(aux);
        }
        free(datos.getPrimero());
        return datos1;
    }

    //Metodo para calcular operaciones
    double calcular(Pila<string> prefija) {
        if (prefija.PilaVacia()) {
            return 0;
        }

        //Excepciones
        try {

            Pila<string> cad = invertirPila(prefija);

            string aux, aux2;
            string charac = "";
            char anterior = '.';
            Pila<string> p;

            Nodo<string>* caracter = cad.getPrimero();
            string caracter1 = "";

            while (caracter) {
                caracter1 = caracter->getValor();
                if (numero(caracter1)) {
                    if (caracter1 == "pi") {
                        caracter1 = "3.141592653589793";
                    }
                    p.Push(caracter1);


                }
                else if (caracter1 == "+") {
                    aux = p.getPrimero()->getValor();
                    p.Pop();
                    aux2 = p.getPrimero()->getValor();
                    p.Pop();
                    p.Push(to_string(stod(aux) + stod(aux2)));

                }
                else if (caracter1 == "-") {
                    aux = p.getPrimero()->getValor();
                    p.Pop();
                    aux2 = p.getPrimero()->getValor();
                    p.Pop();
                    p.Push(to_string(stod(aux) - stod(aux2)));

                }
                else if (caracter1 == "*") {
                    aux = p.getPrimero()->getValor();
                    p.Pop();
                    aux2 = p.getPrimero()->getValor();
                    p.Pop();
                    p.Push(to_string(stod(aux) * stod(aux2)));

                }
                else if (caracter1 == "/") {
                    aux = p.getPrimero()->getValor();
                    p.Pop();
                    aux2 = p.getPrimero()->getValor();
                    p.Pop();
                    p.Push(to_string(stod(aux) / stod(aux2)));

                }
                else if (caracter1 == "%") {
                    aux = p.getPrimero()->getValor();
                    p.Pop();
                    aux2 = p.getPrimero()->getValor();
                    p.Pop();
                    p.Push(to_string(int(stod(aux)) % int(stod(aux2))));

                }
                else if (caracter1 == "^") {
                    aux = p.getPrimero()->getValor();
                    p.Pop();
                    aux2 = p.getPrimero()->getValor();
                    p.Pop();
                    p.Push(to_string(pow(stod(aux), stod(aux2)))); //potencia

                }
                else if (caracter1 == "raiz") {
                    aux = p.getPrimero()->getValor();
                    p.Pop();

                    p.Push(to_string(sqrt(stod(aux)))); //raiz

                }
                else if (caracter1 == "sen") {
                    aux = p.getPrimero()->getValor();
                    p.Pop();

                    p.Push(to_string(sin(stod(aux)))); //seno

                }
                else if (caracter1 == "cos") {
                    aux = p.getPrimero()->getValor();
                    p.Pop();

                    p.Push(to_string(cos(stod(aux)))); //coseno

                }
                else if (caracter1 == "tan") {
                    aux = p.getPrimero()->getValor();
                    p.Pop();

                    p.Push(to_string(tan(stod(aux)))); //tangente

                }
                else if (caracter1 == "senh") {
                    aux = p.getPrimero()->getValor();
                    p.Pop();

                    p.Push(to_string(sinh(stod(aux)))); //seno hiperbolico

                }
                else if (caracter1 == "cosh") {
                    aux = p.getPrimero()->getValor();
                    p.Pop();

                    p.Push(to_string(cosh(stod(aux)))); //coseno hiperbolico

                }
                else if (caracter1 == "tanh") {
                    aux = p.getPrimero()->getValor();
                    p.Pop();

                    p.Push(to_string(tanh(stod(aux)))); //tangente hiperbolico

                }

                caracter = caracter->getSiguiente();

            }
            return stod(p.getPrimero()->getValor());
        }
        catch (...)
        {
            cout << "excepcion" << endl;

        }

    }

    ///////////////////////////INGRESAR DATOS///////////////////////////

    //Metodo para el ingreso de Datos
    Pila<string> ingresarDatos() {

        Pila<string> datos;
        Pila<string> datos1;
        Pila<string> datos2;
        string dato = "";

        while (dato != "=") {
            system("cls");
            cout << "       POLACA INVERSA  " << endl;
            cout << "\nIngrese la expresion infija dato a dato y para terminar de ingresar digite el simbolo [=]: ";
            datos.mostrarIngreso();
            cin >> dato;

            if (!datos.PilaVacia()) {
                if (numero(dato) && datos.getPrimero()->getValor() == ")") {
                    datos.Push("*");
                }
                if (funTrigonometrica(dato) && numero(datos.getPrimero()->getValor())) {
                    datos.Push("*");
                }
                if (funTrigonometrica(dato) && datos.getPrimero()->getValor() == ")") {
                    datos.Push("*");
                }
                if (dato == "(" && datos.getPrimero()->getValor() == ")") {
                    datos.Push("*");
                }
                if (dato == "(" && numero(datos.getPrimero()->getValor())) {
                    datos.Push("*");
                }
            }
            if (numero(dato)) {
                datos.Push(dato);
            }
            else {
                if (dato == "=" || dato == "sen" || dato == "cos" || dato == "tan" ||
                    dato == "senh" || dato == "cosh" || dato == "tanh" ||
                    dato == "+" || dato == "-" || dato == "/" || dato == "*" ||
                    dato == "(" || dato == ")" || dato == "%" || dato == "^" ||
                    dato == "raiz") {
                    datos.Push(dato);
                }
                else {
                    cout << "\nIngrese datos validos" << endl;
                    system("pause");
                }
            }
        }

        datos.Pop();
        if (datos.PilaVacia()) {
            return datos;
        }
        return invertirPila(datos);
    }

    ///////////////////////////VALIDAR EXPRESION ALGEBRAICA///////////////////////////

    //Metodo para el ingreso de Datos
    bool validarExpresion(Pila<string> datos1) {

        Pila<string> datos = copiarPila(datos1);
        Nodo<string>* dato = datos.getPrimero();

        if (datos.PilaVacia()) {
            return true;
        }

        string aux;
        string anterior;
        string cabeza;

        //bool resultado = false;
        int parentesisAbiertos = 0;
        int parentesisCerrados = 0;

        if (dato->getValor() == "(") {
            // cout << "aqui 13" << endl;
            return false;
        }
        if (dato->getValor() == ")") {
            parentesisCerrados++;
        }
        anterior = dato->getValor();
        if (!funTrigonometrica(anterior)) {
            if (!numero(anterior)) {
                if (!operadores(anterior)) {
                    if (anterior != "(") {
                        if (anterior != ")") {
                            cout << "Termino INVALIDO" << endl;
                            return false;
                        }
                    }
                }
            }

        }
        datos.Pop();
        int cont_data = 0;
        while (!datos.PilaVacia()) {
            aux = datos.getPrimero()->getValor();
            if (aux == "(") {
                if (operadores(anterior)) {
                    cout << "INVALIDO" << endl;
                    return false;
                }
                if (anterior == ")") {
                    cout << "INVALIDO" << endl;
                    return false;
                }
                parentesisAbiertos++;

            }
            if (aux == ")") {
                parentesisCerrados++;
            }

            if (operadores(aux)) {
                if (operadores(anterior)) {
                    cout << "INVALIDO" << endl;
                    return false;
                }

                if (anterior == ")") {
                    cout << "INVALIDO" << endl;
                    return false;
                }
            }

            if (numero(aux)) {
                if (numero(anterior)) {
                    cout << "INVALIDO" << endl;
                    return false;
                }
                if (funTrigonometrica(anterior)) {
                    cout << "INVALIDO" << endl;
                    return false;
                }
            }

            if (funTrigonometrica(aux)) {
                if (numero(anterior)) {
                    cout << "INVALIDO" << endl;
                    return false;
                }
                if (funTrigonometrica(anterior)) {
                    cout << "INVALIDO" << endl;
                    return false;
                }
            }
            if (!funTrigonometrica(aux)) {
                if (!numero(aux)) {
                    if (!operadores(aux)) {
                        if (aux != "(") {
                            if (aux != ")") {
                                cout << "INVALIDO" << endl;
                                return false;
                            }
                        }
                    }
                }

            }

            anterior = aux;
            datos.Pop();
            cont_data++;
        }

        if (operadores(anterior)) {
            cout << "INVALIDO" << endl;
            return false;
        }
        if (funTrigonometrica(anterior) && cont_data == 0) {
            cout << "INVALIDO" << endl;
            return false;
        }
        if (anterior == ")") {
            cout << "INVALIDO" << endl;
            return false;
        }
        if (parentesisAbiertos != parentesisCerrados) {
            cout << "Faltan parentesis en la expresion ingresada" << endl;
            return false;
        }

        return true;
    }
};