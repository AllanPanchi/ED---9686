#ifndef OPERACION_H
#define OPERACION_H

#include "Calculo.h"

class Operacion : public Calculo
{
    public:
    
        Operacion(const float floatante1,const float flotaante2);
        Operacion();
        ~Operacion();
        void setA(float floatante1);
        void setB(float flotaante2);
        float getA();
        float getB();
        float operator +(const Operacion&) const override;

    private:
        float a;
        float b;
};

#endif
