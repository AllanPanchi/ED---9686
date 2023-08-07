#if !defined(__MaquinaExpendedora_Maquina_h)
#define __MaquinaExpendedora_Maquina_h


class Maquina
{
public:
   Maquina(int monto, int cincoC, int diezC, int veinticincoC, int cincuentaC, int unD);
   Maquina();
   ~Maquina();
   float getMonto(void);
   void setMonto(float newMonto);

   int getCincoC(void);
   void setCincoC(int newCincoC);
   int getDiezC(void);
   void setDiezC(int newDiezC);
   int getVeinticincoC(void);
   void setVeinticincoC(int newVeinticincoC);
   int getCincuentaC(void);
   void setCincuentaC(int newCincuentaC);
   int getUnD(void);
   void setUnD(int newUnD);

   void toString(void);

protected:
private:
   float monto;
   int cincoC;
   int diezC;
   int veinticincoC;
   int cincuentaC;
   int unD;

};

#endif