#include "Archivos.h"
using namespace std;

Archivos::Archivos()
{
}

Archivos::~Archivos()
{
}

void Archivos::escribirArchivo(string nombreArchivo, string texto)
{
    ofstream archivo;
    archivo.open(nombreArchivo, ios::app);
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    archivo << texto << endl;
    archivo.close();
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

