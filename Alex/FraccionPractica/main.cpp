/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes: 
        Alex Trejo
        Allan Panchi
        Sebastian Verdugo
        Alejandro Andrade
Fecha de inicio: 04/05/2023
Fecha de modificación: 09/05/2023

Realizar 4 operaciones en una interface que incluyan datos abstractos 
*/  
#include <iostream>
#include <string>
#include "Fraccion.cpp"
#include "IOperaciones.cpp"

using namespace std;

int main(int argc, char const *argv[])
{ 
    
    Fraccion fraccion;
    IOperaciones* op = new Operaciones();
    float numerador1, numerador2, denominador1, denominador2;

    cout<<"\nIngrese Numerador 1: \t";
    cin>>numerador1;
    //numerador1=fraccion.validarNumeroIngresado(numerador1);
   

    cout<<"\nIngrese denominador 1: \t";
    
    cin>>denominador1;
    denominador1=fraccion.validarDenominador(denominador1);

    cout<<"\nIngrese Numerador 2 : \t";
    cin>>numerador2;
    //numerador2=fraccion.validarNumeroIngresado(numerador2);

    cout<<"\nIngrese Denominador 2: \t";
    cin>>denominador2;
    denominador2=fraccion.validarDenominador(denominador2);



    Fraccion obj1(numerador1, denominador1);
    Fraccion obj2(numerador2, denominador2);

    fraccion = fraccion.proceso(obj1, obj2);

    obj1.toString();
    obj2.toString();

       

    fraccion.toString();

   

	std::cout << "Operacion 1: "<< op->operacion1(obj1, obj2);
	std::cout << "\nOperacion 2: ";
	op->operacion2(obj1, obj2).toString();
	std::cout << "Operacion 3: ";
	op->operacion3(-3.9, 3.9).toString();
	std::cout << "Operacion 4: "<< op->operacion4(2.3, 4.1);


   system("pause");
    return 0;
 
    



}

