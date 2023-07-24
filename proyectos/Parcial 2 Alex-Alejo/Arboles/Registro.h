/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Allan Panchi
                Alex Trejo 
                Sebastian Verdugo
Fecha de inicio: 15/06/2023
Fecha de modificación: 15/06/2023

Ordenamiento de lista circular doblemente enlazadas
*/

/**
 * @file Persona.h
 * @author Alejandro Andrade - Alex Trejo  
 * @brief 
 * @version 0.1
 * @date 2023-07-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include <iostream>
#include "Empleado.cpp"

class Registro
{
public:
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   std::string getEstado(void);
   void setEstado(std::string newEstado);
   Fecha getEntrada(void);
   void setEntrada(Fecha newEntrada);
   Fecha getSalida(void);
   void setSalida(Fecha newSalida);
   void toString(void);
   Registro();
   Registro(std::string cedula, Fecha entrada, Fecha salida, std::string estado);
   ~Registro();

private:
   std::string cedula, estado;
   Fecha entrada;
   Fecha salida;

};

