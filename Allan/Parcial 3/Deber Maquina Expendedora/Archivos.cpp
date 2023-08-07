#include "Archivos.h"
using namespace std;

Archivos::Archivos()
{
}

Archivos::~Archivos()
{
}

void Archivos::escribirArchivoProducto(const string nombreArchivo, const vector<Producto>& productos)
{
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (const auto& producto : productos) {
            archivo << producto.getNombre() << " "
                    << producto.getPrecio() << " "
                    << producto.getCantidad() << " "
                    << std::endl;
        }
        archivo.close();
        std::cout << "Productos guardados en el archivo exitosamente." << std::endl;
    } else {
        std::cout << "No se pudo abrir el archivo para guardar los productos." << std::endl;
    }
}

void Archivos::leerArchivo(string nombreArchivo)
{
    ifstream archivo;
    string texto;
    archivo.open(nombreArchivo, ios::in);
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    while (!archivo.eof())
    {
        getline(archivo, texto);
        cout << texto << endl;
    }
    archivo.close();
}

void Archivos::sobreescribirArchivo(string nombreArchivo, string texto)
{
    ofstream archivo;
    archivo.open(nombreArchivo, ios::out);
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    archivo << texto << endl;
    archivo.close();
}

