#include "Maquina.h"

Maquina::Maquina(float monto, int cincoC, int diezC, int veinticincoC, int cincuentaC, int unD, int cincoDB, int diezDB, int veinteDB)
{
   this->monto = monto;
   this->cincoC = cincoC;
   this->diezC = diezC;
   this->veinticincoC = veinticincoC;
   this->cincuentaC = cincuentaC;
   this->unD = unD;
   this->cincoDB = cincoDB;
   this->diezDB = diezDB;
   this->veinteDB = veinteDB;
}

Maquina::Maquina()
{
   this->monto = 0;
}

Maquina::~Maquina()
{
}

float Maquina::getMonto(void)
{
   return monto;
}

void Maquina::setMonto(float newMonto)
{
   monto = newMonto;
}

int Maquina::getCincoC(void)
{
   return cincoC;
}

void Maquina::setCincoC(int newCincoC)
{
   cincoC = newCincoC;
}

int Maquina::getDiezC(void)
{
   return diezC;
}

void Maquina::setDiezC(int newDiezC)
{
   diezC = newDiezC;
}

int Maquina::getVeinticincoC(void)
{
   return veinticincoC;
}

void Maquina::setVeinticincoC(int newVeinticincoC)
{
   veinticincoC = newVeinticincoC;
}

int Maquina::getCincuentaC(void)
{
   return cincuentaC;
}

void Maquina::setCincuentaC(int newCincuentaC)
{
   cincuentaC = newCincuentaC;
}

int Maquina::getUnD(void)
{
   return unD;
}

void Maquina::setUnD(int newUnD)
{
   unD = newUnD;
}

int Maquina::getCincoDB(void)
{
   return cincoDB;
}

void Maquina::setCincoDB(int newCincoDB)
{
   cincoDB = newCincoDB;
}

int Maquina::getDiezDB(void)
{
   return diezDB;
}

void Maquina::setDiezDB(int newDiezDB)
{
   diezDB = newDiezDB;
}

int Maquina::getVeinteDB(void)
{
   return veinteDB;
}

void Maquina::setVeinteDB(int newVeinteDB)
{
   veinteDB = newVeinteDB;
}

void Maquina::toString(void)
{
   std::cout << "Monto: " << this->getMonto() 
               << " 5c: " << this->getCincoC()
               << " 10c: " << this->getDiezC()
               << " 25c: " << this->getVeinticincoC()
               << " 50c: " << this->getCincuentaC()
               << " 1$: " << this->getUnD()
               << " 5$B: " << this->getCincoDB()
               << " 10$B: " << this->getDiezDB()
               << " 20$B: " << this->getVeinteDB()
               << std::endl;
}
