#include "Reina.h"
#include <fstream>
#define DIMENSION 8
using namespace std;

Reina::Reina(int n1)
{
   	this->n=n1;
	this->validar=new bool *[DIMENSION];
	this->tablero=new char *[DIMENSION];
	
   
}

bool** Reina::getValidar(void)
{
   return validar;
}

void Reina::setValidar(bool **newValidar)
{
   validar = newValidar;
}

char** Reina::getTablero(void)
{
   return tablero;
}

void Reina::setTablero(char **newTablero)
{
   tablero= newTablero;
}

int Reina::getContador(void)
{
   return contador;
}

void Reina::setContador(int newContador)
{
   contador = newContador;
}

int Reina::getN(void)
{
   return n;
}

void Reina::setN(int newN)
{
   n = newN;
}

Reina::~Reina()
{
}

