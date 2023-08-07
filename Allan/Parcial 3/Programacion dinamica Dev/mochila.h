

#pragma once
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <conio.h>

#define maxN 200	
#define maxC 1000	

using namespace std;


class Mochila{
    public:
    int tabela[maxN+1][maxC+1];
    int peso[maxN+1];
    int valor[maxN+1];
    void backpack();
    int validate_only_numbers(const char* msj);
    
};

int Mochila::validate_only_numbers(const char* msj)
{
	int dato = 0;
	char c;
	printf("%s", msj);
	while ((c = _getch()) != 13) {
		if (c >= '0' && c <= '9') {
			printf("%c", c);
			dato = dato * 10 + (c - '0');
		}
	}
	printf("\n");
	return dato;
}


void Mochila::backpack(){
	int c, v, x, i, b, n, s, soma, aux;
	vector<int> mochilaFinal;
 	
 	printf("\nDigite la capacidad de la mochila y el numeros de objetos \n");

c = validate_only_numbers("Digite la capacidad de la mochila: ");
n = validate_only_numbers("Digite el número de objetos: ");

for(i = 1; i<=n; i++){
    cout << "Digite el peso del item " << i << ": ";
    peso[i] = validate_only_numbers("");
    cout << "Digite el valor del item " << i << ": ";
    valor[i] = validate_only_numbers("");
}

for(i=0; i<=n; i++){
    tabela[i][0] = 0;
}

for(b = 1; b<=c; b++){
    tabela[0][b] = 0;

    for(i=1; i<=n; i++){
        s = tabela[i-1][b];

        if( peso[i] <= b){
            soma = tabela[i-1][b-peso[i]] + valor[i];
            if( s < soma){
                s = soma;
            }
        }

        tabela[i][b] = s;
    }
}

printf("%d\n", tabela[n][c]);

    
 
 
		for(i= 0; i<=n; i++){
			for(b = 0; b<=c; b++){
				printf("%d\t", tabela[i][b]);
			}
			puts("");
		}
 
 
 
		 i = n;
		 b = c;
		 aux = tabela[i][b];
 
		 while(aux){
			 if(tabela[i][b] != tabela[i-1][b]){ 
				 mochilaFinal.push_back(i);
				 b -= peso[i];
			 }
			 i--;
			 aux = tabela[i][b];
		 }
 
		 cout<<"Los items : ";
		 for(i=0; i<int(mochilaFinal.size()); i++){
			 printf("%d ", mochilaFinal[i]);
		 }
		 cout<<"->entraron en la mochila"<<endl;

        mochilaFinal.clear();
    
    

}


