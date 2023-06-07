/*
	UFA-ESPE
	Alumnos: Ricardo Rivadeneira, Sebastián Rivera.
	Fecha de creación: 12/11/2022
	Fecha de modificación: 16/11/2022
	Enunciado: Usando recursividad, realizar suma  de matrices.
	Nivel.- 3   NRC: 7999
*/
#ifndef CPROCESO_H
#define CPROCESO_H
#include <iostream>
using namespace std;

class Cproceso{
    public:

        //void sumaRecursivaMatrices( int **, int **, int **, int, int); //arreglo dinamico
		void sumaRecursivaMatrices( int **, int , int, int,int);
		void encerarMatriz(int); //arreglo dinamico
		void llenarMatriz(int); //arreglo dinamico
		void imprimirMatriz(int**,char*, int); //arreglo dinamico
		void imprimir(); //arreglo dinamico
		void validarCifrado(int);
		


        int** getMat1() const; 
		int getSuma();
		int getDim();
		int** getMat2();
		int** getMatR();

		void setMat1(int**);
		void setSuma(int);
		void setDim(int);
		void setMat2(int**);
		void setMatR(int**);
        Cproceso(); //Constructor
        
    private:
        int **mat1,**mat2,**matR, suma,dim; //Uso para funcion por datos randomicos
};
#endif