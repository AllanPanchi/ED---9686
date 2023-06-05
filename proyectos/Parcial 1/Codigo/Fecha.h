#ifndef FECHA_H
#define FECHA_H

class Fecha {
public:
    virtual ~Fecha() {} 
    
    virtual int getDia() const = 0;
    virtual int getMes() const = 0;
    virtual int getAnio() const = 0;

    virtual void setDia(int dia) = 0;
    virtual void setMes(int mes) = 0;
    virtual void setAnio(int anio) = 0;

    virtual void print() const = 0;
};

#endif
