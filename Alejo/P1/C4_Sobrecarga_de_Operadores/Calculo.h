#ifndef CALCULO_H
#define CALCULO_H

class Calculo
{
    public:
        virtual float operator +(const Operacion&) const = 0;
};

#endif