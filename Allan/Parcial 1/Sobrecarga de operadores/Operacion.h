/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: Alex Trejo
			 Allan Panchi
			 Sebastian Verdugo
			 Alejandro Andrade
Fecha de inicio: 10/05/2023
Fecha de modificación: 21/05/2023

Realizar una sobrecarga de 4 operadores y uno extra para poder pracitcar
*/

#if !defined(__SobreCargaDeDatos_Operacion_h)
#define __SobreCargaDeDatos_Operacion_h

#include "Operadores.h"

class Operacion: public Operadores
{
public:
   Operacion();
   Operacion(float, float);
   ~Operacion();
   float getNum1(void);
   void setNum1(float newNum1);
   float getNum2(void);
   void setNum2(float newNum2);
   float operator +(const Operacion&)const override;
   friend std::ostream& operator <<(std::ostream&, const Operacion&);
   float operator -(const Operacion&)const override;
   Operacion operator ||(const Operacion&)const override;
   Operacion operator &&(const Operacion&)const override;


private:
   float num1;
   float num2;
};

#endif
