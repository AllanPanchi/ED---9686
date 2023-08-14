#pragma once
#include "Operaciones.cpp"

class Postfijo {

public:

    /////////////////////////// INFIJA - POSTFIJA/SUFIJA ///////////////////////////

    Pila<std::string> infijaSufija(Pila<std::string> infija) {

        Operaciones op;
        Pila<std::string> cad = op.copiarPila(infija);
        cad.Push(")");
        cad = op.invertirPila(cad);
        cad.Push("(");

        std::string result;
        std::string aux;
        std::string anterior = "";
        Nodo<std::string>* caracter = cad.getPrimero();

        Pila<std::string> postfija;
        Pila<std::string> p;
        std::string caracter1 = "";

        while (caracter) {
            caracter1 = caracter->getValor();
            if (op.numero(caracter1)) {
                postfija.Push(caracter1);
            }
            else if (caracter1 == "(") {  
                p.Push(caracter1);
            }
            else if (caracter1 == ")") {
                while ((p.getPrimero()->getValor() != "(") && (!p.PilaVacia())) {
                    postfija.Push(p.getPrimero()->getValor());
                    p.Pop();
                }
                if (p.getPrimero()->getValor() == "(") {
                    p.Pop();
                }
            }
            else if (op.operadores(caracter1)) {

                if (p.PilaVacia()) {
                    p.Push(caracter1);
                }
                else {
                    if (op.prioridad(caracter1) > op.prioridad(p.getPrimero()->getValor())) {
                        p.Push(caracter1);
                    }
                    else if ((op.prioridad(caracter1) == op.prioridad(p.getPrimero()->getValor()))) {

                        while ((op.prioridad(caracter1) == op.prioridad(p.getPrimero()->getValor()))) {
                            postfija.Push(p.getPrimero()->getValor());
                            p.Pop();
                        }
                        p.Push(caracter1);
                    }
                    else if (op.prioridad(caracter1) == op.prioridad(p.getPrimero()->getValor())) {
                        p.Push(caracter1);
                    }
                    else {
                        while ((!p.PilaVacia()) && (op.prioridad(caracter1) < op.prioridad(p.getPrimero()->getValor()))) {
                            postfija.Push(p.getPrimero()->getValor());
                            p.Pop();
                        }
                        p.Push(caracter1);
                    }
                }
            }
            if (op.funTrigonometrica(anterior) && caracter1 == "(") {
                p.Push(anterior);
            }
            anterior = caracter1;
            caracter = caracter->getSiguiente();

        }
        while (!p.PilaVacia()) {

            postfija.Push(p.getPrimero()->getValor());
            p.Pop();
        }
        postfija = op.invertirPila(postfija);

        return postfija;
    }
};