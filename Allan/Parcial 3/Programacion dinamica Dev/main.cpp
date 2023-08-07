


#include "mochila.h"
#include "Cambio.h"
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <time.h>
#include <iostream>
using namespace std;



void cambioDinero();
void mochila();
bool isNumber(string s);

int main()
{
    string opcion;

    system("cls");

    do{
        cout << "\t\t--Resolucion problema de la mochila y cambio de monedas--" << endl;
        cout << "1. Cambio de dinero" << endl;
        cout << "2. Mochila" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        if(isNumber(opcion)){
            int opcion1 = atoi(opcion.c_str());
            switch(opcion1){
                case 1:
                    system("cls");
                    cambioDinero();
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    mochila();
                    system("pause");
                    break;
                case 3:
                    cout << "Saliendo del programa" << endl;
                    system("pause");
                    break;
                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }
        }else{
            cout << "Opcion no valida" << endl;
        }
        system("cls");
    }while(opcion != "3");
    return 0;
}

bool isNumber(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }

    }
    
    return true;
}



void cambioDinero(){
    srand(time(NULL));
    	Mochila m;
    Cambio cambio_monedas;
    cambio_monedas.cantidad = m.validate_only_numbers("Ingrese cantidad: ");
    cambio_monedas.gen_cambio();
}


void mochila(){
    Mochila m;
    m.backpack();

}



