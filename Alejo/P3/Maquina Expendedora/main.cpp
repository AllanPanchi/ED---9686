#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "ManejoArchivos.cpp"

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

void comprar_producto(std::map<std::string, Producto>& productos, const std::string& producto, float saldo, Lista<Producto> lista, Maquina maquina, std::map<float, int> monedasIngresadas) {
    auto iter = productos.find(producto);
    std::vector<int> cantidades;
    std::map<float, int> monedas_vuelto;
    if (iter != productos.end()) {
        Producto& seleccionado = iter->second;
        if (seleccionado.getStock() > 0 && saldo >= seleccionado.getPrecio()) {
            float vuelto = saldo - seleccionado.getPrecio();
            std::cout << "¡Compra exitosa! Tu vuelto es: $" << vuelto << std::endl;
            seleccionado.setStock(seleccionado.getStock()-1);
            std::vector<float> monedas = {20, 10, 5, 1, 0.5, 0.25, 0.10, 0.05};
            
            for (float moneda : monedas) {
                while (vuelto >= moneda - 0.01) {
                    vuelto -= moneda;
                    monedas_vuelto[moneda]++;
                }
            }

            std::cout << "Vuelto:" << std::endl;
            for (const auto& par : monedas_vuelto) {
                if(par.first == 0.05F){
                    if(par.second == 1){
                        std::cout << "una moneda de cinco centavos" << std::endl;
                    }else{ 
                        std::cout << par.second << " monedas de cinco centavos" << std::endl;
                    }
                }else if(par.first == 0.1F){
                    if(par.second == 1)
                        std::cout <<"una moneda de diez centavos" << std::endl;
                    else{ 
                        std::cout << par.second << " monedas de diez centavos" << std::endl;
                    }
                }else if(par.first == 0.25F){
                    if(par.second == 1)
                        std::cout << "una moneda de veinticinco centavos" << std::endl;
                    else{ 
                        std::cout << par.second << " monedas de veinticinco centavos" << std::endl;
                    }
                }else if(par.first == 0.5F){
                    if(par.second == 1)
                        std::cout << "una moneda de cincuenta centavos" << std::endl;
                    else{ 
                        std::cout << par.second << " monedas de cincuenta centavos" << std::endl;
                    }
                }else if(par.first == 1){
                    if(par.second == 1)
                        std::cout << "una moneda de dolar" << std::endl;
                    else{ 
                        std::cout << par.second << " monedas de un dolar" << std::endl;
                    }
                }else if(par.first == 5){
                    if(par.second == 1)
                        std::cout << "un billete de cinco dolares" << std::endl;
                    else{ 
                        std::cout << par.second << " billetes de cinco dolares" << std::endl;
                    }
                }else if(par.first == 10){
                    if(par.second == 1)
                        std::cout << "un billete de diez dolares" << std::endl;
                    else{ 
                        std::cout << par.second << " billetes de diez dolares" << std::endl;
                    }
                }else if(par.first == 20){
                    if(par.second == 1)
                        std::cout << "un billete de veinte dolares" << std::endl;
                    else{ 
                        std::cout << par.second << " billetes de veinte dolares" << std::endl;
                    }
                }
                cantidades.push_back(par.second);
                system("pause");
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
    }
}

void imprimirMenu(){
    std::cout << "Selecione una opcion: " << std::endl;
    std::cout << "1. Comprar" << std::endl;
    std::cout << "2. Salir" << std::endl;
}

void mostrarProductos(Lista<Producto> lista)
{
    std::cout << "|    \tProductos disponibles: \t\t|" << std::endl;
    std::cout << "|---------------------------------------|" << std::endl;
    std::cout << "|    \tNombre\t\tPrecio\tStock\t|" << std::endl;
    std::cout << "|---------------------------------------|" << std::endl;
    Nodo<Producto>* temp = lista.getPrimero();
    do {
        std::cout << "|    \t" << temp->getValor().getNombre() << "\t\t"
                << temp->getValor().getPrecio() << "\t"
                << temp->getValor().getStock() << "\t|" << std::endl;
        temp = temp->getSiguiente();
    } while (temp != lista.getPrimero());
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
            iss >> nombre >> precio;
            productos[nombre] = Producto(nombre, precio, 10); // Aquí puedes establecer el stock inicial de cada producto
        }
        archivo.close();
    } else {
        std::cout << "No se encontró el archivo de productos. Creando uno nuevo con valores predeterminados." << std::endl;
        std::ofstream nuevo_archivo("productos.txt");
        if (nuevo_archivo.is_open()) {
            nuevo_archivo << "Pepsi 0.25 15 \nJet 0.35 15 \n Tatos 0.5 20 \n KitKat 1 20 \nChifles 1.5 20 " << std::endl;
            nuevo_archivo.close();
            std::cout << "Archivo de productos creado exitosamente." << std::endl;
            return leer_productos(); // Llamada recursiva para leer el archivo recién creado
        } else {
            std::cout << "Error al crear el archivo de productos." << std::endl;
        }
    }
    return productos;
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
        std::cin >> opcion;

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

                    std::cout << "Ingrese su moneda: " << std::endl;
                    std::cin >> opcion2;

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

                std::cout << "Que desea comprar: " << std::endl;
                std::cin >> nombre;
                
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

    system("cls");
    return 0;
}