#include "funcion.h"

class FuncionesDEC: public funcion{
	private:
		char* cad;
	public:
		FuncionesHexa_Dec();
		char* getCad();
		int Transformar(void);
   		int tamano(void); 
};