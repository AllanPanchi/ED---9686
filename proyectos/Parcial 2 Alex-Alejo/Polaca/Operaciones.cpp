/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Alex Trejo 
                
Fecha de inicio: 30/06/2023
Fecha de modificación: 16/07/2023

Proyecto sobre Calculadora polaca infija, posfija y prefija
*/
#include <iostream>
#include "Operaciones.h"

/// @brief Constructor por defecto de la clase Operaciones
Operaciones::Operaciones()
{
    // TODO : implement
}

/// @brief Destructor de la clase Operaciones
Operaciones::~Operaciones()
{
    // TODO : implement
}

/// @brief Retorna el valor de PI
/// @return double
double Operaciones::getPI()
{
    return PI;
}

/// @brief Retorna el valor de EPSILON
/// @return double
double Operaciones::getEPSILON()
{
    return EPSILON;
}

/// @brief Verificar si el valor cumple las propiedades de un NaN
/// @return double
bool Operaciones::isNaN(double valor) {
    return valor != valor;
}

/// @brief Obtenemos el valor absoluto de un numero
/// @param valor 
/// @return double
double Operaciones::abs(double valor)
{
    if (valor < 0.0)
    {
        return -valor;
    }
    return valor;
}

/// @brief Normaliza el valor de un radian
/// @param radian 
/// @return double
double Operaciones::normalizaRadian(double radian){
	while (radian <= -2 * PI) {
        radian += 2 * PI;
    }

    while (radian > 2 * PI) {
        radian -= 2 * PI;
    }
    
    return radian;
}

/// @brief Redondea un numero
/// @param numero 
/// @return int
int Operaciones::redondear(double numero)
{
    int numeroEntero = (int)numero;
    double diferencia = numero - numeroEntero;

    if (abs(diferencia) <= 0.5)
    {
        return numeroEntero;
    }
    else
    {
    	if (numeroEntero > 0) {
    		return numeroEntero + 1;
		} else {
			return numeroEntero - 1;
		}
    }
}

/// @brief Calcula el seno de un numero
/// @param operando 
/// @return double
double Operaciones::seno(double operando)
{
	operando = normalizaRadian(operando);
	
    double resultado = 0.0;
    double termino = operando;
    double contador = 1.0;

    while (abs(termino) > EPSILON)
    {
        resultado += termino;
        termino *= -(operando * operando) / ((contador + 1) * (contador + 2));
        contador += 2;
    }
    
    if ((abs(resultado - redondear(resultado)) < EPSILON * 1e+2)) {
    	return redondear(resultado);
	}

    return resultado;
}

/// @brief Calcula el coseno de un numero
/// @param operando 
/// @return double
double Operaciones::coseno(double operando)
{
	operando = normalizaRadian(operando);
	
    double resultado = 0.0;
    double termino = 1.0;
    double contador = 0.0;

    while (abs(termino) > EPSILON)
    {
        resultado += termino;
        termino *= -(operando * operando) / ((contador + 1) * (contador + 2));
        contador += 2;
    }
        
    if ((abs(resultado - redondear(resultado)) < EPSILON * 1e+2)) {
    	return redondear(resultado);
	}

    return resultado;
}

/// @brief Calcula la tangente de un numero
/// @param operando 
/// @return double
double Operaciones::tangente(double operando)
{
	operando = normalizaRadian(operando);
    return seno(operando) / coseno(operando);
}

/// @brief Calcula el logaritmo natural de un numero
/// @param operando 
/// @return double
double Operaciones::log(double operando) {
	if (operando <= 0) {
        // Manejo de casos especiales: logaritmo indefinido o no válido        
        return 0.0/0.0; // O devuelve NaN, dependiendo de tus necesidades
    }

    double resultado = 0.0;
    double termino = (operando - 1) / (operando + 1);
    double exponente = termino;
    int n = 1;

    // Calcula el logaritmo utilizando la serie de Taylor del logaritmo natural
    while (abs(exponente) > EPSILON) {
        resultado += exponente;
        n += 2;
        termino *= (operando - 1) * (operando - 1) / (operando + 1) / (operando + 1);
        exponente = termino / n;
    }

    return 2 * resultado;
}

/// @brief Calcula la raiz de un numero
/// @param base 
/// @param exponente 
/// @return double
double Operaciones::potencia(double base, double exponente)
{
	if (exponente == 0) {
		return 1;
	}
	
    double resultado = 1;
    double termino = 1;
    int numeroIteraciones = 100;
    double logBase = log(base);
    for (int i = 1; i <= numeroIteraciones; i++) {
        termino *= exponente * logBase / i;
        resultado += termino;
    }
    return resultado;
}