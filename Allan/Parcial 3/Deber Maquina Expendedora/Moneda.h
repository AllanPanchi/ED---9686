#include <iostream>

class Moneda{

    private:
        int cincoC;
        int diezC;
        int veinticincoC;
        int cincuentaC;
        int unD;

    public:
        Moneda(int cincoC, int diezC, int veinticincoC, int cincuentaC, int unD);
        Moneda();
        ~Moneda();
        int getCincoC() const;
        void setCincoC(int);
        int getDiezC() const;
        void setDiezC(int);
        int getVeinticincoC() const;
        void setVeinticincoC(int);
        int getCincuentaC() const;
        void setCincuentaC(int);
        int getUnD() const;
        void setUnD(int);
};