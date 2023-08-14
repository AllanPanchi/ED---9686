/***********************************************************************
 * Module:  Producto.h
 * Author:  02ale
 * Modified: domingo, 6 de agosto de 2023 13:44:58
 * Purpose: Declaration of the class Producto
 ***********************************************************************/

#if !defined(__MaquinaExpendedora_Producto_h)
#define __MaquinaExpendedora_Producto_h

#include <string>

class Producto
{
public:
   Producto(std::string nombre, float precio, int stock);
   Producto();
   ~Producto();
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   float getPrecio(void);
   void setPrecio(float newPrecio);
   int getStock(void);
   void setStock(int newStock);
   void toString(void);

protected:
private:
   std::string nombre;
   float precio;
   int stock;


};

#endif