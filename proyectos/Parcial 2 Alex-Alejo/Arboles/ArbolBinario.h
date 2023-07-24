/**
 * @file ArbolBinario.h
 * @author Alejandro Andrade - Alex Trejo
 * @brief 
 * @version 1.0
 * @date 2023-07-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "OperacionArboles.h"
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
	    NodoArbol<T>* buscarNodo(T)override;
	    void eliminarNodo(T)override;
	    void mostrarArbol()override;
	    void mostrarRepetidos(T)override;
	private:
	    NodoArbol<T>* raiz;
	    NodoArbol<T>* encontrarNodoMinimo(NodoArbol<T>*);
    
};
#endif