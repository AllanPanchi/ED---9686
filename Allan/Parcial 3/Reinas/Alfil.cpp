#include "Alfil.h"
#include <fstream>
#include <iostream>
#define MAX 8

using namespace std;

Alfil::Alfil(int n1)
{
   	this->n=n1;
	this->validar=new bool *[MAX];
	this->tablero=new char *[MAX];
}

bool** Alfil::getValidar(void)
{
    return validar;
}

void Alfil::setValidar(bool **newValidar)
{
    validar = newValidar;
}

char** Alfil::getTablero(void)
{
    return tablero;
}

void Alfil::setTablero(char **newTablero)
{
    tablero= newTablero;
}

int Alfil::getContador(void)
{
    return contador;
}

void Alfil::setContador(int newContador)
{
    contador = newContador;
}

int Alfil::getN(void)
{
    return n;
}

void Alfil::setN(int newN)
{
    n = newN;
}

Alfil::~Alfil()
{
}
