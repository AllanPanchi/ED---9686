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
#include "Operaciones.cpp"

using namespace std;

class Postfijo {

public:

    /////////////////////////// INFIJA - POSTFIJA/SUFIJA ///////////////////////////

    Pila<string> infijaSufija(Pila<string> infija) {

        Operaciones op;
        Pila<string> cad = op.copiarPila(infija);
        cad.Push(")");
        cad = op.invertirPila(cad);
        cad.Push("(");

        string result;
        string aux;
        string anterior = "";
        Nodo<string>* caracter = cad.getPrimero();

        Pila<string> postfija;
        Pila<string> p;
        string caracter1 = "";

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