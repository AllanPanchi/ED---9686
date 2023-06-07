/*
	UFA-ESPE
	Alumnos: Ricardo Rivadeneira, Sebastián Rivera.
	Fecha de creación: 12/11/2022
	Fecha de modificación: 16/11/2022
	Enunciado: Usando recursividad, realizar suma  de matrices.
	Nivel.- 3   NRC: 7999
*/
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "Cproceso.cpp"
#include <time.h>
#include <functional>



void validarNumeroEnteroPositivo(int& dimIngresada) {
    std::string input;
	Cproceso p;
	
    std::cout << "Ingrese la dimension de la matriz: ";
    std::cin >> input;

    auto validarEnteroPositivo = [](const std::string& str) {
        if (str.empty()) {
            return false;
        }
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        int num = std::stoi(str);
        return num > 0;
    };

    if (validarEnteroPositivo(input)) {
        std::cout << "¡El numero es un entero positivo!" << std::endl;
		dimIngresada=std::stoi(input);


		
    } else {
        std::cout << "El numero no es un entero positivo. Intentelo nuevamente." << std::endl;
        validarNumeroEnteroPositivo( dimIngresada);
    }

	

}

int main(){
	
	srand (time(NULL)); 
	Cproceso p;
	int dim;	
	std::string input;
	// Función lambda para validar si el número es un entero positivo
    
	

	
	
    //Menu del Programa
    system("cls");
    printf("\t\tSuma de Matrices con datos random\n");
	//printf("Ingrese la dimension de la matriz :\t");
	//std::cin>> input;

	validarNumeroEnteroPositivo(dim);

	
	
    p.encerarMatriz(dim);
	p.llenarMatriz(dim);
	p.imprimirMatriz(p.getMat1(),"A", dim);
	cout<<"\n";
	

	//p.imprimirMatriz(p.getMat2(),"B");
	//cout<<"\n";
	//p.sumaRecursivaMatrices( p.getMat1(),p.getMat2(),p.getMatR(), dim, dim);

	/*const std:: function <int(int)> sumaRecursivaMatrices=[ ](int n){
		p.sumaRecursivaMatrices(p.getMat1(),p.getSuma(), 0,0,dim);
		
		return p.getSuma();

	};*/

	auto lambda_funct = [=](int n, Cproceso p ){

		p.sumaRecursivaMatrices(p.getMat1(),p.getSuma(), 0,0,dim);
		return p.getSuma();

        
      
	};


	int resultado= lambda_funct(dim,p);
	std::cout<<"la suma es:"<<resultado <<std::endl;

	

	//p.sumaRecursivaMatrices(p.getMat1(), p.getSuma(), 0,0,dim);

	

	//p.imprimirMatriz(p.getSuma(),"R", dim);
	//p.imprimir();

	cout<<"\nPulse enter para continuar\n"<<endl;

	

	


                
    system("pause");
    return 0;
}
