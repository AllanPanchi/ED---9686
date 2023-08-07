#include "Moneda.h"
#include <iostream>
using namespace std;

Moneda::Moneda(int cincoC, int diezC, int veinticincoC, int cincuentaC, int unD){
   this->cincoC = cincoC;
   this->diezC = diezC;
   this->veinticincoC = veinticincoC;
   this->cincuentaC = cincuentaC;
   this->unD = unD;

}

Moneda::Moneda()
{
    cincoC = 0;
    diezC = 0;
    veinticincoC = 0;
    cincuentaC = 0;
    unD = 0;
}
void Moneda::setCincoC(int C) {
    cincoC = C;
}

void Moneda::setDiezC(int D) {
    diezC = D;
}

void Moneda::setVeinticincoC(int V) {
    veinticincoC = V;
}

void Moneda::setCincuentaC(int C) {
    cincuentaC = C;
}

void Moneda::setUnD(int U) {
    unD = U;
}

int Moneda::getCincoC() const {
    return cincoC;
}

int Moneda::getDiezC() const {
    return diezC;
}

int Moneda::getVeinticincoC() const {
    return veinticincoC;
}

int Moneda::getCincuentaC() const {
    return cincuentaC;
}

int Moneda::getUnD() const {
    return unD;
}

Moneda::~Moneda()
{
}

