
#include <iostream>
#include "Operaciones.h"

Operaciones::Operaciones()
{
    // TODO : implement
}

Operaciones::~Operaciones()
{
    // TODO : implement
}

double Operaciones::getPI()
{
    return PI;
}

double Operaciones::getEPSILON()
{
    return EPSILON;
}

bool Operaciones::isNaN(double valor) {
    // Verificar si el valor cumple las propiedades de un NaN
    return valor != valor;
}

double Operaciones::abs(double valor)
{
    if (valor < 0.0)
    {
        return -valor;
    }
    return valor;
}

double Operaciones::normalizaRadian(double radian){
	while (radian <= -2 * PI) {
        radian += 2 * PI;
    }

    while (radian > 2 * PI) {
        radian -= 2 * PI;
    }
    
    return radian;
}

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

double Operaciones::tangente(double operando)
{
	operando = normalizaRadian(operando);
    return seno(operando) / coseno(operando);
}

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