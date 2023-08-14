#ifndef INGRESOEXPRESIONES_H
#define INGRESOEXPRESIONES_H
#include <string>

class IngresoExpresiones {
	public:
		static std::string ingresoExpresion(void);
		static bool esEspecial(char);
		static bool esOperador(char);
		static bool esParentesis(char);
	protected:
};

#endif