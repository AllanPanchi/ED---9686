#include "Funciones.h"
#include <cmath>

double Funciones::potenciaTrigonometrica(double base, double exponente){
    if (exponente <= 0) {
        return 1.0;
    }
    else{
        return base * potenciaTrigonometrica(base, exponente - 1);
    }
}

double Funciones::seno(double valor) {
    const int terminos = 10; 
    double resultado = 0.0;

    valor = fmod(valor, 2 * M_PI);

    for (int n = 0; n < terminos; n++) {
        double numerador = Funciones::potenciaTrigonometrica(-1, n);
        double denominador = 1.0;

        for (int i = 1; i <= (2 * n + 1); i++) {
            denominador *= i;
        }

        resultado += (numerador / denominador) * potenciaTrigonometrica(valor, (2 * n + 1));
    }

    return resultado;
}

double Funciones::coseno(double valor){
    double epsilon = 1e-10;
    double resultado = 0.0;
    double termino = 1.0;
    double contador = 0.0;

    while(Funciones::valorAbsoluto(termino) > epsilon)
    {
        resultado += termino;
        termino *= -(valor * valor) / ((contador + 1) * (contador + 2));
        contador += 2;
    }
    return resultado;
}

double Funciones::potencia(double base, double exponente) {
	if (exponente == 0) {
		if (base == 0) {
			return 0.0/0.0;
		}
		return 1;
	}
	
	if (base == 0) {
		return 0;
	}
	
    double resultado = 1;
    double termino = 1;
    int numeroIteraciones = 100;
    double logBase = Funciones::calcularLogaritmoNatural(base);
    for (int i = 1; i <= numeroIteraciones; i++) {
        termino *= exponente * logBase / i;
        resultado += termino;
    }
    return resultado;
}

double Funciones::calcularLogaritmoNatural(double valor) {
    double epsilon = 1e-10;
    double x = (valor - 1.0) / (valor + 1.0);
    double x2 = x * x;
    double logaritmo = 0.0;
    double termino = x;
    int n = 1;
    
    while (valorAbsoluto(termino) > epsilon) {
        logaritmo += termino / n;
        termino *= x2;
        n += 2;
    }
    
    return 2.0 * logaritmo;
}

double Funciones::raizCuadrada(double valor){
    if (valor == 0.0) {
        return 0.0;
    }
    
    double numero = valor;
    double epsilon = 1e-10;
    
    while (true) {
        double raizAnterior = numero;
        numero = 0.5 * (numero + valor / numero);
        
        if (valorAbsoluto(numero - raizAnterior) < epsilon) {
            break;
        }
    }
    
    return numero;
}

double Funciones::raizCubica(double valor){
    double epsilon = 1e-10;

    double numero = valor;
    double pivote = 1.0;

    while (valorAbsoluto(numero - pivote) > epsilon) {
        pivote = numero;
        numero = (2.0 * pivote + valor / (pivote * pivote)) / 3.0;
    }

    return numero;

}

double Funciones::tangente(double valor){
    return seno(valor) / coseno(valor);
}

double Funciones::valorAbsoluto(double valor){
    if(valor < 0)
        return -valor;
    else
        return valor;
}