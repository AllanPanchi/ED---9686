/***********************************************************************
 * UFA-ESPE
 * Autores:  Jeimy Marley Morales Sosa & Camilo Andres Orrico Emme 
 * Modificacion: Jueves, 19 de Enero de 2023 21:17:59
 * Purpose: Grafico del Arbol Radix
 *Nivel: Tercero           NRC:7999
 ***********************************************************************/
#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
using namespace std;

class ValidarDatos
{
	public:

/*int exponente(int base, int exponent);


int funcion_atoi(char const *str,size_t len);
double funcion_strtod(char *s);
char *ingresarDatosEnteros(char const *msj);
char *str_cpy(char *cadena1 ,char *cadena2);//copia la cadena dos en la cadena uno 
char *ingresocaracteres(char *msj);
char *ingresoflotantes(char const *msj);*/



static int validarEnteroMenu() {		
    char entrada;
    char tecla;
        while (true) {
                tecla = getch();
                
                if (tecla == '\r') {
                    std::cout << std::endl;
                    break;
                } else if (tecla == '\b') {
                    if (entrada) {
                        std::cout << "\b \b";
                        entrada = '\0';
                    }
                } else if (isdigit(tecla) && !entrada) {
                    entrada = tecla;
                    std::cout << tecla;
                }
            }
            
        if (entrada) {
                int numero = entrada - '0';
            if (numero >= 0 || numero <= 7)
                {
                return numero;
                }
                
            } else {
                return -1;
            }
            return 1;
        }

static int validarEntero() {		
     char *entrada = new char[30];
            char tecla;
            int i = 0;
            
            while (true) {
                tecla = getch(); 
                
                if (tecla == '\r') { 
                std::cout << std::endl;
                break;
                } else if (tecla == '\b' && i > 0) { 
                    i--;						
                    std::cout << "\b \b"; 
                    entrada[i] = 0; 
                } else if (isdigit(tecla) && i<12) {
                    entrada[i++] = tecla;
                    std::cout << tecla; 
                }
            }

            return atoi(entrada); 

}
};


/*
//Funcion pow
int exponente(int base, int exponent){
	if (exponent == 0) {
    return 1;
  } else {
    int result = base;
    for (int i = 1; i < exponent; i++) {
      result *= base;
    }
    return result;
  }
}
//Funcion atoi combierte a entero
int funcion_atoi(char const *str,size_t len){
	int i;
	int res;
	int signo;
	i = 0;
	res = 0;
	signo = 1;
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if(str[i] == '-')
	{
		signo = -1;
    	i++;
	}
	else if(str[i] == '+')
	{
    	signo = 1;
    	i++;
	}
	int j = i-1;
	i = len;
	while (str[i] < '0' || str[i] > '9') {
    	i--;
	}
	int num_final = i;
	while(i > j)
	{
    	if (str[i] >= '0' && str[i] <= '9') {
		res += exponente(10, num_final-i) * (str[i] - '0');
    } else {
		num_final--;
    }
    	i--;
	}	
	return(res * signo);
}


char *str_cpy(char *cadena1 ,char *cadena2){
	if(cadena1 == NULL) return NULL;
	int i=0;
	while (cadena2[i] !='\0')
	{
		cadena1[i]=cadena2[i];
		i++;
	}
	cadena1[i]='\0';
	return cadena1;
}

double funcion_strtod(char *s)
{
    int count=0;
    int i;
    for(i=0; i<=strlen(s)-1; i++)
    {

        if(s[i]=='.')
        {
            count++;
        }
        if(count==2)
        {
            return -1;
        }

        if( !((s[i]>=48 && s[i]<=57)|| (s[i]=='.')) )
        {
		return -1;
        }
    }

    if(count==0)
    {
        return -1;
    }
    double d;
    sscanf(s,"%lf",&d);
    return d;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char *ingresoflotantes(char const *msj)
{
    char *dato=new char[50];
	char c;
	int	sum=0;
	int i=0;
	printf("%s",msj);
	while (((c=getch())!=13)&& sum<=1){
		if ((c>='0'&&c<='9') || c=='.'){
			printf("%c",c);
			dato[i++]=c;
			if (c=='.'){
				sum++;
				if (sum>=2){
					putchar(8);
					putchar(32);
					putchar(8);	
					sum--;	
				}	
			}
		}else if(c==8){
			dato[i]=0;
			i--;
			putchar(8);
			putchar(32);
			putchar(8);
		}	
	}
	dato[i]='\0';//fin del while
	return dato;
}

char *ingresocaracteres(char const *msj)
{
    char *dato=new char[10];
	char c;
	int i=0;
	printf("%s",msj);
	while ((c=getch())!=13){
		if((c>='a'&& c<='z')||(c>='A'&&c<='Z')){
			printf("%c",c);
			dato[i++]=c;
		}else if(c==8){
			dato[i]=0;
			i--;
			putchar(8);
			putchar(32);
			putchar(8);
		}
		
	}
	dato[i]='\0';//fin del while
	return dato;
}
////clase 
char *ingresarDatosEnteros(char const *msj){
	char *dato=new char[10];
	char c;
	int i=0;
	printf("%s",msj);
	while((c=getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
		}else if(c==8){
			dato[i]=0;
			i--;
			putchar(8);
			putchar(32);
			putchar(8);
		}	
	}
	dato[i]='\0';
	return dato;
}

template<typename T>
class Datos{
	public:
		void setData(T d);
		T getData() const;
	private:
		T data;
}
/*template<typename T>
	void Datos<T>::setData(T d){
		this->data=d;
	}
template<typename T>
	T Datos<T>::getData()const{
		return this->data;
	}*/
/*
int main(int argc, char** argv) {
	Datos<int> entero;
	Datos<float> flotante;
	Datos<char*> caracter;
	Datos<double> real;
	int valorEntero;
	float valorFlotante;
	double valorReal;
	char datoEntero[10],datoFlotante[10],datoReal[20],datoCaracter[10];
	str_cpy(datoEntero,ingresarDatosEnteros("\n Ingrese el valor entero"));
	valorEntero=funcion_atoi(datoEntero,strlen(datoEntero));
	entero.setData(valorEntero);
	str_cpy(datoReal,ingresoflotantes("\n Ingrese el valor real"));
	valorReal=funcion_strtod(datoReal);
	real.setData(valorReal);
	
	str_cpy(datoCaracter,ingresocaracteres("\n Ingrese el valor caracter"));
	caracter.setData(datoCaracter);
	

	cout<<"\n Numero de tipo int: "<<entero.getData();
	cout<<"\n Numero de tipo double: "<<real.getData();
	cout<<"\n Numero de tipo caracter: "<<caracter.getData()<<"\n";
	system("pause");

	return 0;
}*/
