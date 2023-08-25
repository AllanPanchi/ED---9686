#pragma once
#include "OperacionArboles.h"
#include "NodoArbol.h"
#include <string>

template <typename T>
class ArbolBinario: public OperacionArboles<T>{
	public:
		//Constructor
	    ArbolBinario();
	    ~ArbolBinario();
	    
	    //Getter y Setter
	    NodoArbol<T>* getRaiz();
	    void setRaiz(NodoArbol<T>*);
	    
	    //Operaciones
	    void insertarNodo(T)override;
	    bool buscarNodo(T)override;
	    void eliminarNodo(T)override;
	    void mostrarArbol()override;
	    std::string obtenerRecorridoPreorden()override;
	    std::string obtenerRecorridoInorden()override;
	    std::string obtenerRecorridoPostorden()override;
	private:
	    NodoArbol<T>* raiz;
	    NodoArbol<T>* encontrarNodoMinimo(NodoArbol<T>*);
    
};
