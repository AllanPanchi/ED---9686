#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

struct Producto {
    std::string nombre;
    float precio;
    int stock;

    Producto() : nombre(""), precio(0.0), stock(0) {}

    Producto(std::string nombre, float precio, int stock) : nombre(nombre), precio(precio), stock(stock) {}

};

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
            nuevo_archivo << "ProductoA 10.50" << std::endl;
            nuevo_archivo << "ProductoB 5.75" << std::endl;
            nuevo_archivo << "ProductoC 8.20" << std::endl;
            nuevo_archivo.close();
            std::cout << "Archivo de productos creado exitosamente." << std::endl;
            return leer_productos(); // Llamada recursiva para leer el archivo recién creado
        } else {
            std::cout << "Error al crear el archivo de productos." << std::endl;
        }
    }
    return productos;
}

void mostrar_productos(const std::map<std::string, Producto>& productos) {
    std::cout << "Productos disponibles:" << std::endl;
    for (const auto& par : productos) {
        const Producto& producto = par.second;
        std::cout << producto.nombre << " - $" << producto.precio << " - Stock: " << producto.stock << std::endl;
    }
}

void comprar_producto(std::map<std::string, Producto>& productos, const std::string& producto, float monedas_ingresadas) {
    auto iter = productos.find(producto);
    if (iter != productos.end()) {
        Producto& seleccionado = iter->second;
        if (seleccionado.stock > 0 && monedas_ingresadas >= seleccionado.precio) {
            float vuelto = monedas_ingresadas - seleccionado.precio;
            std::cout << "¡Compra exitosa! Tu vuelto es: $" << vuelto << std::endl;
            seleccionado.stock--;
            std::vector<float> monedas = {20, 10, 5, 1, 0.5, 0.25, 0.1, 0.05, 0.01};
            std::map<float, int> monedas_vuelto;
            for (float moneda : monedas) {
                while (vuelto >= moneda) {
                    vuelto -= moneda;
                    monedas_vuelto[moneda]++;
                }
            }
            std::cout << "Vuelto en monedas:" << std::endl;
            for (const auto& par : monedas_vuelto) {
                std::cout << "$" << par.first << " x " << par.second << std::endl;
            }
        } else {
            std::cout << "Dinero insuficiente o producto agotado. Introduce más monedas o elige otro producto." << std::endl;
        }
    } else {
        std::cout << "Producto no encontrado." << std::endl;
    }
}

int main() {
    std::map<std::string, Producto> productos = leer_productos();

    while (true) {
        mostrar_productos(productos);
        std::cout << "Opciones: comprar / salir" << std::endl;
        std::string opcion;
        std::cin >> opcion;

        if (opcion == "comprar") {
            std::string producto;
            float monedas_ingresadas;
            std::cout << "Ingresa el nombre del producto que deseas comprar: ";
            std::cin >> producto;
            std::cout << "Ingresa el monto en monedas: $";
            std::cin >> monedas_ingresadas;
            comprar_producto(productos, producto, monedas_ingresadas);
        } else if (opcion == "salir") {
            break;
        } else {
            std::cout << "Opción inválida. Intenta nuevamente." << std::endl;
        }
    }

    return 0;
}
