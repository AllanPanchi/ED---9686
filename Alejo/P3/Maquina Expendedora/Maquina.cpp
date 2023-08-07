/***********************************************************************
 * Module:  Maquina.cpp
 * Author:  02ale
 * Modified: domingo, 6 de agosto de 2023 13:52:54
 * Purpose: Implementation of the class Maquina
 ***********************************************************************/

#include "Maquina.h"

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::Maquina(int monto, Lista<Moneda> valores)
// Purpose:    Implementation of Maquina::Maquina()
// Parameters:
// - monto
// - valores
// Return:
////////////////////////////////////////////////////////////////////////

Maquina::Maquina(float monto, int cincoC, int diezC, int veinticincoC, int cincuentaC, int unD)
{
   this->monto = monto;
   this->cincoC = cincoC;
   this->diezC = diezC;
   this->veinticincoC = veinticincoC;
   this->cincuentaC = cincuentaC;
   this->unD = unD;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::Maquina()
// Purpose:    Implementation of Maquina::Maquina()
// Return:     
////////////////////////////////////////////////////////////////////////

Maquina::Maquina()
{
   this->monto = 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::~Maquina()
// Purpose:    Implementation of Maquina::~Maquina()
// Return:     
////////////////////////////////////////////////////////////////////////

Maquina::~Maquina()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::getMonto()
// Purpose:    Implementation of Maquina::getMonto()
// Return:     int
////////////////////////////////////////////////////////////////////////

float Maquina::getMonto(void)
{
   return monto;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::setMonto(int newMonto)
// Purpose:    Implementation of Maquina::setMonto()
// Parameters:
// - newMonto
// Return:     void
////////////////////////////////////////////////////////////////////////

void Maquina::setMonto(float newMonto)
{
   monto = newMonto;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::getCincoC()
// Purpose:    Implementation of Maquina::getCincoC()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Maquina::getCincoC(void)
{
   return cincoC;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::setCincoC(int newCincoC)
// Purpose:    Implementation of Maquina::setCincoC()
// Parameters:
// - newCincoC
// Return:     void
////////////////////////////////////////////////////////////////////////

void Maquina::setCincoC(int newCincoC)
{
   cincoC = newCincoC;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::getDiezC()
// Purpose:    Implementation of Maquina::getDiezC()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Maquina::getDiezC(void)
{
   return diezC;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::setDiezC(int newDiezC)
// Purpose:    Implementation of Maquina::setDiezC()
// Parameters:
// - newDiezC
// Return:     void
////////////////////////////////////////////////////////////////////////

void Maquina::setDiezC(int newDiezC)
{
   diezC = newDiezC;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::getVeinticincoC()
// Purpose:    Implementation of Maquina::getVeinticincoC()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Maquina::getVeinticincoC(void)
{
   return veinticincoC;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::setVeinticincoC(int newVeinticincoC)
// Purpose:    Implementation of Maquina::setVeinticincoC()
// Parameters:
// - newVeinticincoC
// Return:     void
////////////////////////////////////////////////////////////////////////

void Maquina::setVeinticincoC(int newVeinticincoC)
{
   veinticincoC = newVeinticincoC;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::getCincuentaC()
// Purpose:    Implementation of Maquina::getCincuentaC()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Maquina::getCincuentaC(void)
{
   return cincuentaC;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::setCincuentaC(int newCincuentaC)
// Purpose:    Implementation of Maquina::setCincuentaC()
// Parameters:
// - newCincuentaC
// Return:     void
////////////////////////////////////////////////////////////////////////

void Maquina::setCincuentaC(int newCincuentaC)
{
   cincuentaC = newCincuentaC;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::getUnD()
// Purpose:    Implementation of Maquina::getUnD()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Maquina::getUnD(void)
{
   return unD;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::setUnD(int newUnD)
// Purpose:    Implementation of Maquina::setUnD()
// Parameters:
// - newUnD
// Return:     void
////////////////////////////////////////////////////////////////////////

void Maquina::setUnD(int newUnD)
{
   unD = newUnD;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::toString()
// Purpose:    Implementation of Maquina::toString()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Maquina::toString(void)
{
   std::cout << "Monto: " << this->getMonto() 
               << " 5c: " << this->getCincoC()
               << " 10c: " << this->getDiezC()
               << " 25c: " << this->getVeinticincoC()
               << " 50c: " << this->getCincuentaC()
               << " 1$: " << this->getUnD()
               << std::endl;
}
