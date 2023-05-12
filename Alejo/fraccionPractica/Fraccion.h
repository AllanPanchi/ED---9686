/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
          Allan Panchi
          Sebastian Verdugo
          Alejandro Andrade
Fecha de inicio: 04/05/2023
Fecha de modificación: 11/05/2023

Imprementar la interface en una clase y llamar a esta clase en el main 
*/

#if !defined(__Fraccion_Fraccion_h)
#define __Fraccion_Fraccion_h

class Fraccion
{
public:
   float getNumerador(void);
   void setNumerador(float newNumerador);
   float getDenominador(void);
   void setDenominador(float newDenominador);
   Fraccion();
   Fraccion(float num, float den);
   ~Fraccion();
   Fraccion proceso(Fraccion object1, Fraccion object2);
   void toString();
   void validarDenominador();

protected:
private:
   float numerador;
   float denominador;


};

#endif