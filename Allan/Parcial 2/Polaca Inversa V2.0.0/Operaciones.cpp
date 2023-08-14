﻿#pragma once
#include <string>
#include "Funciones.cpp"
using namespace std;

#include "Pila.cpp"

class Operaciones {
	public:

		//Validar los operadores menos la raíz
		bool operadores(string c) {
			if (c=="^"||c == "+" || c == "-" || c == "*" || c == "/") {
				return true;
			}
			return false;
		}

		bool funTrigonometrica(string c) {
			if (c == "sen" || c == "cos" || c == "tan"|| c=="raiz") {//BORRADO DENTRO DE LOS PARÁMETROS: || c == "senh" || c == "cosh" || c == "tanh" ||
				return true;
			}
			return false;
		}

		//Metodo para verificar la prioridad de los operadores
		int prioridad(string c) {
			if (c == "^" || c == "raiz")
				return 3;
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
					} else {
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

			for (char& c : cad) { //FOR EACH
				if (c == '.') {
					punto++;
				} else if (c == '-') {
					negativo++;
				} else if (c > '9' || c < '0') {
					caract++;
				}
			}

			if (punto > 1) {
				return false;
			}

			if (negativo > 1) {
				return false;
			} else if (negativo == 1 && sustraer(cad, 0, 1) != "-") {
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


					} else if (caracter1 == "+") {
						aux = p.getPrimero()->getValor();
						p.Pop();
						aux2 = p.getPrimero()->getValor();
						p.Pop();
						p.Push(to_string(stod(aux) + stod(aux2)));

					} else if (caracter1 == "-") {
						aux = p.getPrimero()->getValor();
						p.Pop();
						aux2 = p.getPrimero()->getValor();
						p.Pop();
						p.Push(to_string(stod(aux) - stod(aux2)));

					} else if (caracter1 == "*") {
						aux = p.getPrimero()->getValor();
						p.Pop();
						aux2 = p.getPrimero()->getValor();
						p.Pop();
						p.Push(to_string(stod(aux) * stod(aux2)));

					} else if (caracter1 == "/") {
						aux = p.getPrimero()->getValor();
						p.Pop();
						aux2 = p.getPrimero()->getValor();
						p.Pop();
						p.Push(to_string(stod(aux) / stod(aux2)));

					} else if (caracter1 == "^") {
						aux = p.getPrimero()->getValor();
						p.Pop();
						aux2 = p.getPrimero()->getValor();
						p.Pop();
						p.Push(to_string(Funciones::potencia(stod(aux), stod(aux2)))); //potencia

					} else if (caracter1 == "raiz") {
						aux = p.getPrimero()->getValor();
						p.Pop();

						p.Push(to_string(Funciones::raizCuadrada(stod(aux)))); //raiz

                	} else if (caracter1 == "sen") {
						aux = p.getPrimero()->getValor();
						p.Pop();
						p.Push(to_string(Funciones::seno(stod(aux)))); //seno

					} else if (caracter1 == "cos") {
						aux = p.getPrimero()->getValor();
						p.Pop();
						p.Push(to_string(Funciones::coseno(stod(aux)))); //coseno

					} else if (caracter1 == "tan") {
						aux = p.getPrimero()->getValor();
						p.Pop();
						p.Push(to_string(Funciones::tangente(stod(aux)))); //tangente
					}

					caracter = caracter->getSiguiente();

				}
				return stod(p.getPrimero()->getValor());
			} catch (...) {
				cout << "excepcion" << endl;

			}

		}

		///////////////////////////VALIDAR EXPRESION ALGEBRAICA///////////////////////////

		//Metodo para el ingreso de Datos
		bool validarExpresion(Pila<string> datos1) {

			Pila<string> datos = copiarPila(datos1);
			Nodo<string>* dato = datos.getPrimero();
			//cout<<"ADOHLADHO  "<<dato->getValor();
			//dato = datos.getActual();
			//cout<<"ADOHLADHO  "<<dato->getValor();

			string aux;
			string anterior;
			string cabeza;

			//bool resultado = false;
			int parentesisAbiertos = 0;
			int parentesisCerrados = 0;

			if (dato->getValor() == "(") {
				//Si se abre paréntesis al final y no se cierra es falso
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
				/*if (!funTrigonometrica(aux)) {
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

				}*/

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
		
		//METODO PARA DIVIDIR UNA EXPRESIÓN ENTERA VALIDADA EN UNA PILA:

		Pila<string> expresionAPila(string& expresion) {
			std::string temp;
			Pila<string> pilaTemporal;
			for(char c : expresion) {
				if(isdigit(c)) {
					temp+=c;

				} else if (isalpha(c)) {
					temp +=c;
				} else {
					if(!temp.empty()) {
						pilaTemporal.Push(temp);
						temp.clear();
					}
					if(c!=' ') {
						pilaTemporal.Push(std::string(1, c));
					}
				}
			}
			if(!temp.empty()) {
				pilaTemporal.Push(temp);
			}// HASTA AQUÍ YA SE GUARDAN LOS DATOS
			return invertirPila(pilaTemporal);;
		}
};