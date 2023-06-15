/*
	UFA-ESPE
	Alumnos: Alex Trejo 
	Fecha de creación: 20/5/2022
	Fecha de modificación: 26/05/2023
	Enunciado: Usando recursividad cifrar una matriz
	Nivel.- 3   NRC: 7999
*/
#include "Cproceso.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstring>

//Constructor
Cproceso::Cproceso(){
	mat1=(int **)calloc (3,sizeof(int*));
	suma=0;
	//mat2=(int **)calloc (3,sizeof(int*));
	//matR=(int **)calloc (3,sizeof(int*));
}
//Get
int** Cproceso::getMat1() const{
	return mat1;
}

int Cproceso::getSuma(){
	return suma;
}

int Cproceso::getDim(){
	return dim;
}

/*int** Cproceso::getMat2(){
	return mat2;
}*/

/*int** Cproceso::getMatR(){
	return matR;
}*/

//Set
void Cproceso::setMat1(int** otroMat1){
	mat1=otroMat1;
}

void Cproceso::setSuma(int otrasuma){
	suma=otrasuma;

}

void Cproceso::setDim(int otradim){
    dim=otradim;
}

/*void Cproceso::setMat2(int** otroMat2){
	mat2=otroMat2;
}*/

/*void Cproceso::setMatR(int** otroMatR){
	matR=otroMatR;
}*/

//Funcion para sumar por memoria Dinamica datos randomicos

void Cproceso::validarCifrado(int sumaCifrado){
	int suma;
	if (sumaCifrado>=10){
        suma=(sumaCifrado%10)+(sumaCifrado/10);
	
		setSuma(suma);
    }
    else{
        setSuma(sumaCifrado);
    }


}

void Cproceso::sumaRecursivaMatrices(int** mat1, int suma, int f, int c, int dim){
		
		if (f<dim && c<dim){
		
				
		suma+= *(*(mat1+f)+c);
		validarCifrado(suma);
		
		
		sumaRecursivaMatrices( mat1,getSuma(),f,c+1,dim);

		if(c==0){
		sumaRecursivaMatrices( mat1,getSuma(),f+1,c=0,dim);

		}
		
		
		
	}

	
}


//Funcion por memoria Dinamica para capturar los valores randomicos
void Cproceso::encerarMatriz( int dim){
		for(int j=0;j<(dim);j++){
		*(mat1+j)=(int*)calloc(dim,sizeof(int*));
		//*(mat2+j)=(int*)calloc(4,sizeof(int*));
		//*(matR+j)=(int*)calloc(4,sizeof(int*));
	} 
}
//Funcion por memoria Dinamica para completar la matriz con datos randomicos
void Cproceso::llenarMatriz( int dim){
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			*(*(mat1+i)+j)=(int)((rand()%10));
			//*(*(mat2+i)+j)=(int)((rand()/32768.1)*1000);
			//*(*(matR+i)+j)=0;
		}
	}
}
//Funcion para imprimir el resultado con memoria Dinamica de datos randomicos
void Cproceso::imprimirMatriz(int **matAux,char *charMat, int dim){
	cout<<"\n>La matriz " <<*charMat<< " es :\n";
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			printf("%d",*(*(matAux+i)+j));
			printf("%*s",j+5,"");
		}
		cout<<"\n";
	}
}

void Cproceso::imprimir(){

	cout<<"La suma es:"<<getSuma()<<endl;
	
}

