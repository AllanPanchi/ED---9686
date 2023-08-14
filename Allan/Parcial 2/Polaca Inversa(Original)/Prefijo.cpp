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

class Prefijo {

public:

    /////////////////////////// INFIJA - PREFIJO ///////////////////////////

	Pila<string> infijaPrefija(Pila<string> infija) {
		
        Operaciones op;
        Pila<string> cad = op.copiarPila(infija);
      
        string resultado, aux;
        string anterior = "";

        Nodo<string>* caracter = cad.getPrimero();
        Pila<string> prefija;
        Pila<string> p;

        while (caracter) {
            if (caracter->getValor() == "(") {
                caracter->setValor(")");
            }
            else if (caracter->getValor() == ")") {
                caracter->setValor("(");
            }
            caracter = caracter->getSiguiente();
        }

        caracter = cad.getPrimero();
        string caracter1 = "";

        while (caracter) {
            caracter1 = caracter->getValor();

            if (op.numero(caracter1)) {
                prefija.Push(caracter1);
            }else if (caracter1 == "(") {
                p.Push(caracter1);
            }else if (caracter1 == ")") {
                while ((p.getPrimero()->getValor() != "(") && (!p.PilaVacia())) {
                    prefija.Push(p.getPrimero()->getValor());
                    p.Pop();
                }

                if (p.getPrimero()->getValor() == "(") {
                    p.Pop();
                }
            }
            else if (op.operadores(caracter1)) {

                if (p.PilaVacia()) {
                    p.Push(caracter1);
                }else {
                    if (op.prioridad(caracter1) > op.prioridad(p.getPrimero()->getValor())) {
                        p.Push(caracter1);
                    }
                    else if ((op.prioridad(caracter1) == op.prioridad(p.getPrimero()->getValor()))
                        && (caracter1 == "^")) {
                        while ((op.prioridad(caracter1) == op.prioridad(p.getPrimero()->getValor()))
                            && (caracter1 == "^")) {
                            prefija.Push(p.getPrimero()->getValor());
                            p.Pop();
                        }
                        p.Push(caracter1);
                    }
                    else if (op.prioridad(caracter1) == op.prioridad(p.getPrimero()->getValor())) {
                        p.Push(caracter1);
                    }
                    else {
                        while ((!p.PilaVacia()) && (op.prioridad(caracter1) < op.prioridad(p.getPrimero()->getValor()))) {
                            prefija.Push(p.getPrimero()->getValor());
                            p.Pop();
                        }
                        p.Push(caracter1);
                    }
                }
            }

            else if (op.funTrigonometrica(caracter1) && anterior == ")") {
                prefija.Push(caracter1);
            }
            anterior = caracter1;
            caracter = caracter->getSiguiente();
        }
        while (!p.PilaVacia()) {
            prefija.Push(p.getPrimero()->getValor());
            p.Pop();
        }

        return prefija;
    }
   	
    

};