#include <iostream>
#include <string>
#include <conio.h>
#include "IngresoExpresiones.h"
#include "IngresoExpresiones.cpp"
#include "Prefijo.cpp"
#include "Postfijo.cpp"

// Función para imprimir el menú
void imprimirMenu(int opcionSeleccionada)
{
    system("cls"); // Limpiar la pantalla

    std::cout << "=== MENU CALCULADORA POLACA INVERSA ===" << std::endl;
    std::cout << (opcionSeleccionada == 1 ? "> " : "  ") << "Ver la operacion en expresion prefija: " << std::endl;
    std::cout << (opcionSeleccionada == 2 ? "> " : "  ") << "Ver la operacion en expresion sufija: " << std::endl;
    std::cout << (opcionSeleccionada == 3 ? "> " : "  ") << "Volver a ingresar expresion: " << std::endl;
    std::cout << (opcionSeleccionada == 4 ? "> " : "  ") << "Salir" << std::endl;
}

int main() {
    try{
        Operaciones op;
        Prefijo pr;
        Postfijo ps;

        Pila<string> datos;
        //datos = op.ingresarDatos(); //ESTE ES PARA INGRESAR DE UNO EN UNO

        std::cout<<"Ingrese la Expresion en NOTACION INFIJA: "<<std::endl;
        std::string expresion;
        expresion = IngresoExpresiones::ingresoExpresion();

        datos = op.expresionAPila(expresion);
        datos.mostrarPila();

        //Datos es una pila ordenada con los valores. //ESTOS SOLO SON PROTOTIPOS DE LA SALIDA
        //EJ: sen(90)+100-36
		//sen->(->90->)->100->-->36->NULL
        //YA TENEMOS LA PILA, CON TODOS LOS VALORES INGRESADOS Y SEPARADOS POR OPERADORES

        int opcionSeleccionada = 1;
        bool menuActivo = true;

        while (menuActivo)
        {
            imprimirMenu(opcionSeleccionada);

            // Leer la entrada del teclado
            char tecla = _getch();

            switch (tecla)
            {
                case 'w':
                    opcionSeleccionada = (opcionSeleccionada == 1) ? 4 : opcionSeleccionada - 1;
                    break;
                case 's':
                    opcionSeleccionada = (opcionSeleccionada == 4) ? 1 : opcionSeleccionada + 1;
                    break;
                case '\r':
                    // Ejecutar la opción seleccionada
                    switch (opcionSeleccionada)
                    {
                        case 1:
                            cout << ""<< endl;
                            std::cout << "Opcion 1 seleccionada" << std::endl;
                            if (op.validarExpresion(datos)) {

                                Pila<string> prefija;

                                prefija = pr.infijaPrefija(datos);
                                cout << "\nExpresion Prefija:   ";
                                prefija.mostrarNotacion();

                                cout << "\nResultado:   ";
                                cout << op.calcular(prefija) << endl;
                            }
                            else {
                                cout << "ERROR" << endl;
                            }
                            break;
                        case 2:
                            std::cout << "Opcion 2 seleccionada" << std::endl;
                            if (op.validarExpresion(datos)) {
                                Pila<string> postfija;
                                Pila<string> prefija;

                                postfija = ps.infijaSufija(datos);
                                cout << "\nExpresion Postfija:   ";
                                postfija.mostrarNotacion();

                                prefija = pr.infijaPrefija(datos);
                                cout << "\nResultado:   ";
                                cout << op.calcular(prefija) << endl;
                            }
                            else {
                                cout << "ERROR" << endl;
                            }
                            break;
                        case 3:
                            std::cout << "Ingrese la Expresion en NOTACION INFIJA: " << std::endl;
                            expresion = IngresoExpresiones::ingresoExpresion();
                            datos = op.expresionAPila(expresion);
                            break;
                        case 4:
                            menuActivo = false; // Salir del bucle
                            break;
                    }
                    std::cout << "\nPresione cualquier tecla para continuar...";
                    _getch();
                    break;
            }
        }

        std::cout << "\nSaliendo del programa." << std::endl;

        return 0;

        }
        catch (const std::exception&){
            std::cout << "Error" << std::endl;

        }
    return 0;
}
