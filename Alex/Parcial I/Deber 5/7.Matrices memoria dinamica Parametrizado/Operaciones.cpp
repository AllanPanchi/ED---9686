#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include "Operaciones.h"

template<typename T> 
Operaciones<T>::Operaciones(){
}


template<typename T> 
Operaciones<T>::Operaciones(Matriz<T>& matriz){
	this->m_matriz=matriz;

}


template<typename T> 
void Operaciones<T>::segmentar(){
	int j, **matriz;
	T** matriz=m_matriz.getMatriz();
	//matriz=(int**)malloc(m_matriz.getDim()*sizeof(int*));
	matriz = new T*[m_matriz.getDim()]; 
	for(j=0;j<_matriz.getDim();j++){
		//*(matriz+j)=(int*)malloc(_matriz.getDim()*sizeof(int*));
		matriz[j] = new T[m_matriz.getDim()];
	}
	_matriz.setMatriz(matriz);
}

template<typename T>
void Operaciones<T>::encerar(){
	for(int i=0;i<m_matriz.getDim();i++){
		for(int j=0;j<m_matriz.getDim();j++){
			*(*(m_matriz.getMatriz()+i)+j)=0;
		}
	}
}

template<typename T>
void Operaciones<T>::imprimir(){
	printf("La matriz es:\n");
	for(int i=0;i<m_matriz.getDim();i++){
		for(int j=0;j<m_matriz.getDim();j++){
			printf("%d",*(*(m_matriz.getMatriz()+i)+j));
			printf("%*s",j+5,"");
		}
		printf("\n");
	}
}

template<typename T>
void Operaciones<T>::generar(){
	srand(time(NULL));
	for(int i=0;i<m_matriz.getDim();i++){
		for(int j=0;j<m_matriz.getDim();j++){
			*(*(m_matriz.getMatriz()+i)+j)= static_cast<T>(rand()%3);
		}
	}
}

template<typename T>
void Operaciones<T>::procesarPot(T exp, T **matriz){
	for(int e=1;e<=exp;e++){
		for(int i=0;i<m_matriz.getDim();i++){
			for(int j=0;j<m_matriz.getDim();j++){
				for(int k=0;k<m_matriz.getDim();k++){
					*(*(m_matriz.getMatrizR()+i)+j)=*(*(m_matriz.getMatrizR()+i)+j)+ 
					(*(*(m_matriz.getMatriz2()+i)+k) * (*(*(m_matriz.getMatriz2()+k)+j)));                				}
			}
		}
	}
}

template<typename T>
void Operaciones<T>::procesarMulti( Matriz<T> &objMatriz1, Matriz<T> &objMatriz2){
	int dim =m_matriz.getDim();
	T **matriz1 = objMatriz1.getMatriz();
	T **matriz2 = objMatriz2.getMatriz();
	T **matrizR = m_matriz.getMatriz();
	
	for(int i=0;i<dim;i++) {
		for(int j=0;j<dim;j++) {
			for(int k=0;k<dim;k++) {
				*(*(matrizR + i) + j) = *(*(matrizR + i) + j)
							+ (*(*(matriz1 + i ) + k) * (*(*(matriz2 + k) + j)));
			}
		}
	}

	
}


template class Operaciones<int>;
template class Operaciones<float>;
template class Operaciones<double>;

