#pragma once
#include <string>

template <typename T>
class OperacionArboles{
	public:
		virtual void insertarNodo(T)=0;
	    virtual bool buscarNodo(T)=0;
	    virtual void eliminarNodo(T)=0;
	    virtual void mostrarArbol()=0;
	    //Recorridos
	    virtual std::string obtenerRecorridoPreorden()=0;
	    virtual std::string obtenerRecorridoInorden()=0;
	    virtual std::string obtenerRecorridoPostorden()=0;
};
