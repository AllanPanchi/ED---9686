#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <map>
#include <iomanip> 
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include "ManejoArchivos.cpp"


std::string unidades[] = {"Cero", "Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve"};
std::string decenas[] = {"", "", "Veinte", "Treinta", "Cuarenta", "Cincuenta", "Sesenta", "Setenta", "Ochenta", "Noventa"};
std::string especiales[] = {"Diez", "Once", "Doce", "Trece", "Catorce", "Quince", "Dieciséis", "Diecisiete", "Dieciocho", "Diecinueve"};
std::string centenas[] = {"", "Ciento", "Doscientos", "Trescientos", "Cuatrocientos", "Quinientos", "Seiscientos", "Setecientos", "Ochocientos", "Novecientos"};

std::string convertirUnidades(int num) {
    return unidades[num];
}

std::string convertirDecenas(int num) {
   
    if (num < 10) {
        return convertirUnidades(num);
    } else if (num >= 20) {
        return decenas[num / 10] + (num % 10 != 0 ? " y " + convertirUnidades(num % 10) : "");
    } else {
        return especiales[num - 10];
    }
    
}

std::string convertirCentenas(int num) {
    if (num == 100) {
        return "Cien";
    } else {
        return centenas[num / 100] + (num % 100 != 0 ? " " + convertirDecenas(num % 100) : "");
    }
}

std::string convertirDecimalAPalabras(float numero) {
    int decimales = 2;
    int parteEntera = static_cast<int>(numero);
    int parteDecimal = std::round( ((numero - static_cast<float>(parteEntera))* std::pow(10,decimales)))/std::pow(10, decimales) * 100;
    
    fflush(stdin);
   
    /*std::cout<< " oo-"<<static_cast<float>(parteEntera) << std::endl;
    std::cout <<"-><" <<std::round( ((numero - static_cast<float>(parteEntera))* std::pow(10,decimales)))/std::pow(10, decimales) << std::endl;
    std::cout << parteEntera << std::endl;
    std::cout << parteDecimal << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout<<numero<<std::endl;*/
    
    std::string resultado;

    // Parte entera
    if (parteEntera >= 1000) {
        resultado += unidades[parteEntera / 1000] + " Mil";
        parteEntera %= 1000;
    }

    if (parteEntera >= 100) {
        resultado += " " + centenas[parteEntera / 100];
        parteEntera %= 100;
    }

    if (parteEntera >= 20) {
        resultado += " " + decenas[parteEntera / 10];
        if (parteEntera % 10 != 0) {
            resultado += " y " + unidades[parteEntera % 10];
        }
    } else if (parteEntera >= 10) {
        resultado += " " + especiales[parteEntera - 10];
    } else if (parteEntera > 0) {
        resultado += " " + unidades[parteEntera];
    }

    if(parteEntera > 0){
        resultado += " Dolares";
    }

    // Parte decimal
    if (parteDecimal > 0) {
        if(parteEntera == 0){
            resultado += " Cero";
        }
        resultado += " punto ";

        if (parteDecimal >= 20) {
            resultado += decenas[parteDecimal / 10];
            if (parteDecimal % 10 != 0) {
                resultado += " y " + unidades[parteDecimal % 10];
            }
        } else if (parteDecimal >= 10 && parteDecimal < 20) {
            resultado += especiales[parteDecimal - 10];
        } else {
            resultado += unidades[parteDecimal];
        }

        resultado += " centavos";
    }

    return resultado;
}


void regresarMonedas(std::string nombre, Lista<Producto> lista){
    std::cout << "Se devolveran las monedas ingresadas" << std::endl;
    Nodo<Producto>* temp = lista.buscar(nombre);
    int stock = temp->getValor().getStock() + 1 ;
    temp->setValor(Producto(temp->getValor().getNombre(), temp->getValor().getPrecio(), stock));
    ManejoArchivos::guardarProductos("productos.txt", lista);
}

void modificarStockMaquina(Maquina& maquina, std::map<float, int> aRestar, std::map<float, int> aSumar, std::string nombre, Lista<Producto> lista){

    for (const auto& par : aSumar) {

        if (par.first == 0.05F) {
            maquina.setCincoC(maquina.getCincoC() + par.second);
        } else if (par.first == 0.10F) {
            maquina.setDiezC(maquina.getDiezC() + par.second);
        } else if (par.first == 0.25F) {
            maquina.setVeinticincoC(maquina.getVeinticincoC() + par.second);
        } else if (par.first == 0.50F) {
            maquina.setCincuentaC(maquina.getCincuentaC() + par.second);
        } else if (par.first == 1.00F) {
            maquina.setUnD(maquina.getUnD() + par.second);
        } else if (par.first == 5.00F) {
            maquina.setCincoDB(maquina.getCincoDB() + par.second);
        } else if(par.first == 10.00F){
            maquina.setDiezDB(maquina.getDiezDB() + par.second);
        } else if(par.first == 20.00F){
            maquina.setVeinteDB(maquina.getVeinteDB() + par.second);
        }
    }

    for (const auto& par : aRestar) {
        
        if (par.first == 0.05F) {
            maquina.setCincoC(maquina.getCincoC() - par.second);
        } else if (par.first == 0.10F) {
            maquina.setDiezC(maquina.getDiezC() - par.second);
        } else if (par.first == 0.25F) {
            maquina.setVeinticincoC(maquina.getVeinticincoC() - par.second);
        } else if (par.first == 0.50F) {
            maquina.setCincuentaC(maquina.getCincuentaC() - par.second);
        } else if (par.first == 1.00F) {
            maquina.setUnD(maquina.getUnD() - par.second);
        } else if(par.first == 5.00F) {
            maquina.setCincoDB(maquina.getCincoDB() - par.second);
        }else if(par.first == 10.00F) {
            maquina.setDiezDB(maquina.getDiezDB() - par.second);
        }else if(par.first == 20.00F) {
            maquina.setVeinteDB(maquina.getVeinteDB() - par.second);
        }
    }

    maquina.setMonto(maquina.getCincoC() * 0.05 +
                     maquina.getDiezC() * 0.10 + 
                     maquina.getVeinticincoC() * 0.25 + 
                     maquina.getCincuentaC() * 0.50 + 
                     maquina.getUnD() * 1.00 +
                     maquina.getCincoDB() * 5.00 +
                     maquina.getDiezDB() * 10.00 +
                     maquina.getVeinteDB() * 20.00);

    system("cls");
    if (maquina.getMonto() <= 0.0F){
        std::cout << "No hay dinero en la maquina" << std::endl;
        regresarMonedas(nombre, lista);
        return;
    } else if (maquina.getCincoC() <= 0){
        std::cout << "No hay monedas de 5 centavos" << std::endl;
        regresarMonedas(nombre, lista);
        return;
    } else if (maquina.getDiezC() <= 0){
        std::cout << "No hay monedas de 10 centavos" << std::endl;
        regresarMonedas(nombre, lista);
        return;
    } else if (maquina.getVeinticincoC() <= 0){
        std::cout << "No hay monedas de 25 centavos" << std::endl;
        regresarMonedas(nombre, lista);
        return;
    } else if (maquina.getCincuentaC() <= 0){
        std::cout << "No hay monedas de 50 centavos" << std::endl;
        regresarMonedas(nombre, lista);
        return;
    } else if (maquina.getUnD() <= 0){
        std::cout << "No hay monedas de 1 dolar" << std::endl;
        regresarMonedas(nombre, lista);
        return;
    } else if(maquina.getCincoDB() <= 0){
        std::cout << "No hay billetes de 5 dolares" << std::endl;
        regresarMonedas(nombre, lista);
        return;
    } else if(maquina.getDiezDB() <= 0){
        std::cout << "No hay billetes de 10 dolares" << std::endl;
        regresarMonedas(nombre, lista);
        return;
    } else if(maquina.getVeinteDB() < 0){
        std::cout << "No hay billetes de 20 dolares" << std::endl;
        regresarMonedas(nombre, lista);
        return;
    }

    ManejoArchivos::guardarMaquina("maquina.txt", maquina);
}

void modificarStockProductos(std::string nombre, Lista<Producto> lista){
    Nodo<Producto>* temp = lista.buscar(nombre);
    int stock = temp->getValor().getStock() - 1 ;
    temp->setValor(Producto(temp->getValor().getNombre(), temp->getValor().getPrecio(), stock));
    ManejoArchivos::guardarProductos("productos.txt", lista);
}

std::string transformarNumerosALetrasInt(int numero){
    std::string cantidad[] = {"dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez"};
    if(numero >= 2 && numero <= 10)
        return cantidad[numero - 2];
    else   
        return "Numero Fuera del rango";
}

void mostrarProductos(Lista<Producto> lista)
{
    std::cout << "|    \tProductos disponibles: \t\t|" << std::endl;
    std::cout << "___________________________________________" << std::endl;
    std::cout << "    \tNombre\t\tPrecio\tStock\t" << std::endl;
    std::cout << "____________________________________________" << std::endl;
    Nodo<Producto>* temp = lista.getPrimero();
    do {
        std::cout << "|    \t" << temp->getValor().getNombre() << "\t\t"
                << temp->getValor().getPrecio() << "\t"
                << temp->getValor().getStock() << "\t|" << std::endl;
        temp = temp->getSiguiente();
    } while (temp != lista.getPrimero());
}

void comprar_producto(std::map<std::string, Producto>& productos, std::string& producto, float saldo, Lista<Producto> lista, Maquina maquina, std::map<float, int> monedasIngresadas) {
        
    std::vector<int> cantidades;
    std::map<float, int> monedas_vuelto;
    bool encontrado = false;
    bool salir = false;

    while(!encontrado && !salir){

        system("cls");
        mostrarProductos(lista);
        std::cout << "|-----------------------|" << std::endl;
        std::cout << "|Su saldo es: \t" << saldo << std::endl;
        std::cout << "|-----------------------|" << std::endl;
        std::cout << "Ingrese el nombre del producto: ";
        std::cin >> producto;
        auto iter = productos.find(producto);
        if (iter != productos.end()) {
        Producto& seleccionado = iter->second;
        if (seleccionado.getStock() > 0 && saldo >= seleccionado.getPrecio()) {
            float vuelto = saldo - seleccionado.getPrecio();
            fflush(stdin);
            std::cout << "¡Compra exitosa! Tu vuelto es: $" << vuelto;
            std::string resultado = convertirDecimalAPalabras(vuelto);
            std::cout <<"->"<< resultado << std::endl;
            seleccionado.setStock(seleccionado.getStock()-1);
            std::vector<float> monedas = {20, 10, 5, 1, 0.5, 0.25, 0.10, 0.05};
            
            for (float moneda : monedas) {
                while (vuelto >= moneda - 0.01) {
                    vuelto -= moneda;
                    monedas_vuelto[moneda]++;
                }
            }
            std::cout << "Vuelto en monedas:" << std::endl;
            for (const auto& par : monedas_vuelto) {
                std::cout << "$" << par.first << " x " << par.second << std::endl;
            }

            system("pause");
            //std::cout << "Vuelto:" << std::endl;
            for (const auto& par : monedas_vuelto) {
                if(par.first == 0.05F){
                    if(par.second == 1){
                        //std::cout << "una moneda de cinco centavos" << std::endl;
                    }else{ 
                        //std::cout << par.second << " monedas de cinco centavos" << std::endl;
                    }
                }else if(par.first == 0.1F){
                    if(par.second == 1){
                        //std::cout <<"una moneda de diez centavos" << std::endl;
                    }else{ 
                        //std::cout << par.second << " monedas de diez centavos" << std::endl;
                    }
                }else if(par.first == 0.25F){
                    if(par.second == 1){
                        //std::cout << "una moneda de veinticinco centavos" << std::endl;
                    }else{ 
                        //std::cout << par.second << " monedas de veinticinco centavos" << std::endl;
                    }
                }else if(par.first == 0.5F){
                    if(par.second == 1){
                        //std::cout << "una moneda de cincuenta centavos" << std::endl;
                    }else{ 
                        //std::cout << par.second << " monedas de cincuenta centavos" << std::endl;
                    }
                }else if(par.first == 1){
                    if(par.second == 1){
                        //std::cout << "una moneda de dolar" << std::endl;
                    }else{ 
                        //std::cout << par.second << " monedas de un dolar" << std::endl;
                    }
                }else if(par.first == 5){
                    if(par.second == 1){
                        //std::cout << "un billete de cinco dolares" << std::endl;
                    }else{ 
                        //std::cout << par.second << " billetes de cinco dolares" << std::endl;
                    }
                }else if(par.first == 10){
                    if(par.second == 1){
                        //std::cout << "un billete de diez dolares" << std::endl;
                    }else{ 
                        //std::cout << par.second << " billetes de diez dolares" << std::endl;
                    }
                }else if(par.first == 20){
                    if(par.second == 1){
                        //std::cout << "un billete de veinte dolares" << std::endl;
                    }else{ 
                        //std::cout << par.second << " billetes de veinte dolares" << std::endl;
                    }
                }
                cantidades.push_back(par.second);
                //system("pause");
            }
            modificarStockProductos(producto, lista);
            modificarStockMaquina(maquina, monedas_vuelto, monedasIngresadas, producto, lista);
            system("pause");
            encontrado = true;

        } else {
            std::cout << "Dinero insuficiente o producto agotado. Introduce más monedas o elige otro producto." << std::endl;
            system("pause");
        }
    } else {
        std::cout << "Producto no encontrado. ¿Desea ingresar otro producto? (s/n): ";
        char respuesta;
        std::cin >> respuesta;
        if (respuesta == 'n' || respuesta == 'N') {
            std::cout << "Saliendo del programa." << std::endl;
            salir = true; // Salimos del bucle si el usuario no desea reingresar un producto
            }
        //system("pause");
    }

    }
    /*
    if (iter != productos.end()) {
        Producto& seleccionado = iter->second;
        if (seleccionado.getStock() > 0 && saldo >= seleccionado.getPrecio()) {
            float vuelto = saldo - seleccionado.getPrecio();
            fflush(stdin);
            std::cout << "¡Compra exitosa! Tu vuelto es: $" << vuelto;
            std::string resultado = convertirDecimalAPalabras(vuelto);
            std::cout <<"->"<< resultado << std::endl;
            seleccionado.setStock(seleccionado.getStock()-1);
            std::vector<float> monedas = {20, 10, 5, 1, 0.5, 0.25, 0.10, 0.05};
            
            for (float moneda : monedas) {
                while (vuelto >= moneda - 0.01) {
                    vuelto -= moneda;
                    monedas_vuelto[moneda]++;
                }
            }
            std::cout << "Vuelto en monedas:" << std::endl;
            for (const auto& par : monedas_vuelto) {
                std::cout << "$" << par.first << " x " << par.second << std::endl;
            }

            system("pause");
            //std::cout << "Vuelto:" << std::endl;
            for (const auto& par : monedas_vuelto) {
                if(par.first == 0.05F){
                    if(par.second == 1){
                        //std::cout << "una moneda de cinco centavos" << std::endl;
                    }else{ 
                        //std::cout << par.second << " monedas de cinco centavos" << std::endl;
                    }
                }else if(par.first == 0.1F){
                    if(par.second == 1){
                        //std::cout <<"una moneda de diez centavos" << std::endl;
                    }else{ 
                        //std::cout << par.second << " monedas de diez centavos" << std::endl;
                    }
                }else if(par.first == 0.25F){
                    if(par.second == 1){
                        //std::cout << "una moneda de veinticinco centavos" << std::endl;
                    }else{ 
                        //std::cout << par.second << " monedas de veinticinco centavos" << std::endl;
                    }
                }else if(par.first == 0.5F){
                    if(par.second == 1){
                        //std::cout << "una moneda de cincuenta centavos" << std::endl;
                    }else{ 
                        //std::cout << par.second << " monedas de cincuenta centavos" << std::endl;
                    }
                }else if(par.first == 1){
                    if(par.second == 1){
                        //std::cout << "una moneda de dolar" << std::endl;
                    }else{ 
                        //std::cout << par.second << " monedas de un dolar" << std::endl;
                    }
                }else if(par.first == 5){
                    if(par.second == 1){
                        //std::cout << "un billete de cinco dolares" << std::endl;
                    }else{ 
                        //std::cout << par.second << " billetes de cinco dolares" << std::endl;
                    }
                }else if(par.first == 10){
                    if(par.second == 1){
                        //std::cout << "un billete de diez dolares" << std::endl;
                    }else{ 
                        //std::cout << par.second << " billetes de diez dolares" << std::endl;
                    }
                }else if(par.first == 20){
                    if(par.second == 1){
                        //std::cout << "un billete de veinte dolares" << std::endl;
                    }else{ 
                        //std::cout << par.second << " billetes de veinte dolares" << std::endl;
                    }
                }
                cantidades.push_back(par.second);
                //system("pause");
            }
            modificarStockProductos(producto, lista);
            modificarStockMaquina(maquina, monedas_vuelto, monedasIngresadas, producto, lista);
            system("pause");

        } else {
            std::cout << "Dinero insuficiente o producto agotado. Introduce más monedas o elige otro producto." << std::endl;
            system("pause");
        }
    } else {
        std::cout << "Producto no encontrado." << std::endl;
        system("pause");
    }*/
}

void imprimirMenu(){
    std::cout << "Selecione una opcion: " << std::endl;
    std::cout << "1. Comprar" << std::endl;
    std::cout << "2. Salir" << std::endl;
}



std::map<std::string, Producto> leer_productos() {
    std::map<std::string, Producto> productos;
    std::ifstream archivo("productos.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string nombre;
            float precio;
            int stock;
            iss >> nombre >> precio >> stock;
            productos[nombre] = Producto(nombre, precio, stock); // Aquí puedes establecer el stock inicial de cada producto
        }
        archivo.close();
    } else {
        std::cout << "No se encontró el archivo de productos. Creando uno nuevo con valores predeterminados." << std::endl;
        std::ofstream nuevo_archivo("productos.txt");
        if (nuevo_archivo.is_open()) {
            nuevo_archivo << "Coca 0.75 15 \nOreo 0.80 15 \nTango 0.35 20 \nGalak 0.50 20 \nJugo 1.60 20 " << std::endl;
            nuevo_archivo.close();
            std::cout << "Archivo de productos creado exitosamente." << std::endl;
            return leer_productos(); // Llamada recursiva para leer el archivo recién creado
        } else {
            std::cout << "Error al crear el archivo de productos." << std::endl;
        }
    }
    return productos;
}

int validarEntero() {		
            char *entrada = new char[1];
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

int main()
{

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    system("cls");

    std::map<std::string, Producto> productos = leer_productos();

    int cincoC = std::rand() % 41 + 10;
    int diezC = std::rand() % 41 + 10;
    int veinticincoC = std::rand() % 41 + 10;
    int cincuentaC = std::rand() % 41 + 10;
    int unD = std::rand() % 41 + 10;
    int cincoDB = std::rand() % 21 + 10;
    int diezDB = std::rand() % 11 + 10;
    int veinteDB = 0;

    float monto = cincoC * 0.05F +
                  diezC * 0.10F + 
                  veinticincoC * 0.25F + 
                  cincuentaC * 0.50F + 
                  unD * 1.00F +
                  cincoDB * 5.00F +
                  diezDB * 10.00F +
                  veinteDB * 20.00F;


    Maquina maquina = Maquina(monto, cincoC, diezC, veinticincoC, cincuentaC, unD, cincoDB, diezDB, veinteDB);
    ManejoArchivos::guardarMaquina("maquina.txt", maquina);

    std::string nombre;
    float saldo = 0;
    bool salir = false;
    bool salir2 = false;
    int opcion = 0;
    int opcion2 = 0;

    float exedente = 0.0F;

    while (!salir)
    {
        system("cls");
        std::map<float, int> monedasIngresadas;
        Lista<Producto> lista;
        ManejoArchivos::cargarProductos("productos.txt", lista);
        ManejoArchivos::cargarMaquina("maquina.txt", maquina);
        saldo = 0;
        
        mostrarProductos(lista);
        imprimirMenu();
        std::cout << "Opcion: ";
        //std::cin >> opcion;
        opcion = validarEntero();

        switch (opcion)
        {
            case 1:

                monedasIngresadas[0.05] = 0;
                monedasIngresadas[0.10] = 0;
                monedasIngresadas[0.25] = 0;
                monedasIngresadas[0.50] = 0;
                monedasIngresadas[1] = 0;
                monedasIngresadas[5] = 0;
                monedasIngresadas[10] = 0;
                monedasIngresadas[20] = 0;
                
                saldo = 0;
                salir2 = false;

                while (!salir2 && saldo <= 20.0F)
                {
                    system("cls");
                    std::cout << "|---Ingreso del Saldo---|" << std::endl;
                    std::cout << "/ Centavos \tDolares \\" << std::endl;
                    std::cout << "|1. 5       \t 5. 1   |" << std::endl;
                    std::cout << "|2. 10      \t 6. 5   |" << std::endl;
                    std::cout << "|3. 25      \t 7. 10  |" << std::endl;
                    std::cout << "|4. 50      \t 8. 20  |" << std::endl;
                    std::cout << "\\-----------------------/" << std::endl;
                    std::cout << "       9. Salir" << std::endl;

                    std::cout << "|-----------------------|" << std::endl;
                    std::cout << "|Su saldo es: \t" << saldo << std::endl;
                    std::cout << "|-----------------------|" << std::endl;

                    std::cout << "Ingrese su moneda: ";
                    opcion2= validarEntero();

                    switch (opcion2)
                    {
                    case 1:
                        saldo += 0.05F;
                        exedente = 0.05F;
                        monedasIngresadas[0.05]++;
                        break;

                    case 2:
                        saldo += 0.10F;
                        exedente = 0.10F;
                        monedasIngresadas[0.10]++;
                        break;

                    case 3:
                        saldo += 0.25F;
                        exedente = 0.25F;
                        monedasIngresadas[0.25]++;
                        break;

                    case 4:
                        saldo += 0.50F;
                        exedente = 0.50F;
                        monedasIngresadas[0.50]++;
                        break;

                    case 5:
                        saldo += 1.0F;
                        exedente = 1.0F;
                        monedasIngresadas[1]++;
                        break;
                    
                    case 6:
                        saldo += 5.0F;
                        exedente = 5.0F;
                        monedasIngresadas[5]++;
                        break;

                    case 7:
                        saldo += 10.0F;
                        exedente = 10.0F;
                        monedasIngresadas[10]++;
                        break;

                    case 8:
                        saldo += 20.0F;
                        exedente = 20.0F;
                        monedasIngresadas[20]++;
                        break;

                    case 9:
                        salir2 = true;
                        break;
                    
                    default:
                        std::cout << "Ingrese una opcion valida." << std::endl;
                        break;
                    }

                }

                if (saldo > 20.0F) {
                    saldo -= exedente;
                    if(exedente == 0.05F){
                        monedasIngresadas[0.05]--;
                    }else if(exedente == 0.10F){
                        monedasIngresadas[0.10]--;
                    }else if(exedente == 0.25F){
                        monedasIngresadas[0.25]--;
                    }else if(exedente == 0.50F){
                        monedasIngresadas[0.50]--;
                    }else if(exedente == 1.0F){
                        monedasIngresadas[1]--;
                    }else if(exedente == 5.0F){
                        monedasIngresadas[5]--;
                    }else if(exedente == 10.0F){
                        monedasIngresadas[10]--;
                    }else if(exedente == 20.0F){
                        monedasIngresadas[20]--;
                    }
                    fflush(stdin);
                    std::cout << "No puede ingresar mas de 20 dolares." << std::endl;
                    std::cout << "|-----------------------|" << std::endl;
                    std::cout << "|Su saldo es: \t" << saldo << std::endl;
                    std::cout << "|-----------------------|" << std::endl;
                    system("pause");
                }

                system("cls");
                mostrarProductos(lista);

                std::cout << "|-----------------------|" << std::endl;
                std::cout << "|Su saldo es: \t" << saldo << std::endl;
                std::cout << "|-----------------------|" << std::endl;

                /*std::cout << "Que desea comprar: " << std::endl;
                std::cin >> nombre;*/
                fflush(stdin);
                comprar_producto(productos, nombre, saldo, lista, maquina, monedasIngresadas);
                break;
            case 2:
                salir = true;
                break;
            default:
                std::cout << "Ingrese una opcion valida." << std::endl;
                break;
        }

        
    }
    system("pause");
    system("cls");
    return 0;
}