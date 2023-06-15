/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: 
        Alex Trejo
        Allan Panchi
        Sebastian Verdugo
        Alejandro Andrade
Fecha de inicio: 04/05/2023
Fecha de modificación: 09/05/2023

Realizar 4 operaciones en una interface que incluyan datos abstractos 
*/

/***********************************************************************
 * Module:  Fraccion.cpp
 * Author:  Alex_22
 * Modified: mi�rcoles, 10 de mayo de 2023 2:10:30
 * Purpose: Implementation of the class Fraccion
 ***********************************************************************/

#include "Fraccion.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>


////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::setNumerador(float newNumerador)
// Purpose:    Implementation of Fraccion::setNumerador()
// Parameters:
// - newNumerador
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fraccion::setNumerador(float newNumerador)
{
   numerador = newNumerador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::getDenominador()
// Purpose:    Implementation of Fraccion::getDenominador()
// Return:     float
////////////////////////////////////////////////////////////////////////

float Fraccion::getDenominador(void)
{
   return denominador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::getNumerador()
// Purpose:    Implementation of Fraccion::getNumerador()
// Return:     float
////////////////////////////////////////////////////////////////////////

float Fraccion::getNumerador(void)
{
   return numerador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::setDenominador(float newDenominador)
// Purpose:    Implementation of Fraccion::setDenominador()
// Parameters:
// - newDenominador
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fraccion::setDenominador(float newDenominador)
{
   denominador = newDenominador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::Fraccion(float num, float den)
// Purpose:    Implementation of Fraccion::Fraccion()
// Parameters:
// - num
// - den
// Return:     
////////////////////////////////////////////////////////////////////////

Fraccion::Fraccion(float num, float den)
{
   // TODO : implement
   
   numerador=num;
   denominador=den;

   
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::~Fraccion()
// Purpose:    Implementation of Fraccion::~Fraccion()
// Return:     
////////////////////////////////////////////////////////////////////////

Fraccion::~Fraccion()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::proceso(Fraccion obj1, Fraccion obj2)
// Purpose:    Implementation of Fraccion::proceso()
// Parameters:
// - obj1
// - obj2
// Return:     Fraccion
////////////////////////////////////////////////////////////////////////

Fraccion Fraccion::proceso(Fraccion obj1, Fraccion obj2)
{
   // TODO : implement
   Fraccion fraccioningreso;
   float numerador_=(obj1.getNumerador() * obj2.getDenominador())+(obj2.getNumerador() * obj1.getDenominador());
   float denominador_= (obj1.getDenominador()+obj2.getDenominador());

   
  
   fraccioningreso.setNumerador(numerador_);
   fraccioningreso.setDenominador(denominador_);
   return fraccioningreso;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::Fraccion()
// Purpose:    Implementation of Fraccion::Fraccion()
// Return:     
////////////////////////////////////////////////////////////////////////

Fraccion::Fraccion()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::toString()
// Purpose:    Implementation of Fraccion::toString()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fraccion::toString(void)
{
   // TODO : implement
   std::cout << numerador << "/" << denominador << std::endl;

}


////////////////////////////////////////////////////////////////////////
// Name:       Fraccion::validarDenominador()
// Purpose:    Implementation of Fraccion::validarDenominador()
// Return:     void
////////////////////////////////////////////////////////////////////////

float Fraccion::validarDenominador(float denominador)
{
   // TODO : implement

   //denominador= validarNumeroIngresado(denominador);
   
   while(denominador==0){

          

      std::cout << "El denominador no puede ser 0, reingrese: \n";
      std::cin >> denominador;
    
      denominador=validarDenominador(denominador);
      //denominador= validarNumeroIngresado(denominador);

   }

  
   return denominador;
}

float Fraccion::validarNumeroIngresado(float numeroIngresado){

   std::string numero= std::to_string(numeroIngresado);
   bool validar=true;


   while(validar){
   if(validarNumero(numero)){
      validar = false;
   }else{
      std::cin.ignore();
      std::cout<< "No se permite ingresar letras, reingrese:";
      getline(std::cin,numero);
      numero=std::to_string(validarNumeroIngresado(std::atof(numero.c_str())));
      validar=false;
   }
   }

   

   numeroIngresado= std::atof(numero.c_str());

   return(numeroIngresado);
   

}

bool Fraccion::validarNumero(std::string numero){

   bool validador= true;
   int longitud= numero.size();
   
   if(longitud == 0){
      validador=false;

   } else if (longitud == 1 && !isdigit(numero[0])){

      validador=false;
   }else {

      int i;
      if(numero[0]=='+' || numero[0]== '-')
         i=1;
      else 
         i=0;

      while(i < longitud){

         if(!isdigit(numero[i])){

            validador=false;
            break;
         }
         i++;

      }
   }

   return validador;
}