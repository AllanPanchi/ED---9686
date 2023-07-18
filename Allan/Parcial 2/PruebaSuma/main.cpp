#include <iostream>

using namespace std;

int sumar(int a){
    int resultado;
    int j = 1;
    for (int i = 2; i <= a; i+=2)
    {
        if(j % 2 == 0)
            resultado -= i;
        else
            resultado += i;
        j++;
    }
    
    return resultado;
}

void imprimir(){
    int a;
    cout << "ingrese el numero: " << endl;
    cin >> a;
    cout << sumar(a) << endl;
}

int main(){
    imprimir();
}

