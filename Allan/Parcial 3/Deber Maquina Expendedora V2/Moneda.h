#include <iostream>
#include <string>
#include <vector>

class Moneda
{
public:
   Moneda(int newValor, std::string newNombre);
   Moneda();
   ~Moneda();
   float getValor(void);
   void setValor(int newValor);
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   void toString(void);
private:
    float valor;
    std::string nombre;
};