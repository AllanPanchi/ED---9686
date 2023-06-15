
#include "ListaProducto.h"
#include "Nodo.h"
#include "ValDatos.h"
#include <fstream>


    Nodo* ListaProducto::getPrimero(){
        return this->primero;
    }

    Nodo* ListaProducto::getActual(){
        return this->actual;
    }

    void ListaProducto::setPrimero(Nodo *primero){
        this->primero=primero;
    }

    void ListaProducto::setActual(Nodo *actual){
        this->actual=actual;
    }

    int ListaProducto::size(){
        int cont=0;
        Nodo *tmp=this->primero;
        while(tmp){
            cont++;
            tmp=tmp->getSiguiente();
        }
        return cont;
    }

    bool ListaProducto::listaVacia(){
        return (this->actual==NULL);
    }

    ListaProducto::ListaProducto(){
        this->primero=NULL;
        this->actual=NULL;
    }

    void ListaProducto::insertar(Producto producto){
        Nodo *nuevo = new Nodo(producto);
        if (listaVacia()){
            this->primero=nuevo;
        }
        else{
            this->actual->setSiguiente(nuevo);
        }
        this->actual=nuevo;
    }
    
    void ListaProducto::eliminar(int codigo){
        Nodo *tmp = this->primero;
        while(tmp){
            if(tmp->getProducto().getCodigo() == codigo){
                if(tmp == this->primero){
                    this->primero = tmp->getSiguiente();
                    delete tmp;
                    break;
                }
                else{
                    tmp->getAnterior()->setSiguiente(tmp->getSiguiente());
                    tmp->getSiguiente()->setAnterior(tmp->getAnterior());
                    delete tmp;
                    break;
                }
            }
        }
    }

    // Buscar un producto en la lista por medio del atrubuto codigo que es int y retornarlo
    Nodo* ListaProducto::buscar(int codigo) {
    Nodo *tmp = this->primero;
    Nodo *productosEncontrados = nullptr; // Variable para almacenar los productos encontrados

    while (tmp) {
        if (tmp->getProducto().getCodigo() == codigo) {
            // Si se encuentra un producto con la fecha especificada, se agrega a la lista de productos encontrados
            Nodo *nuevoNodo = new Nodo(tmp->getProducto());
            if (productosEncontrados == nullptr) {
                productosEncontrados = nuevoNodo;
            } else {
                Nodo *ultimoNodo = productosEncontrados;
                while (ultimoNodo->getSiguiente() != nullptr) {
                    ultimoNodo = ultimoNodo->getSiguiente();
                }
                ultimoNodo->setSiguiente(nuevoNodo);
            }
        }
        tmp = tmp->getSiguiente();
    }

    if (productosEncontrados == nullptr) {
        std::cout << "No se encontraron productos con la fecha especificada." << std::endl;
    }

    return productosEncontrados;
}

    void ListaProducto::actualizar(Nodo *actual){
        
        
        actual->getProducto().toString();
        std::cout << "Ingrese el nuevo nombre de producto:\t";
       
        actual->producto.setNombre(ValidarDatos::validarString());

        std::cout <<"Ingrese el nuevo precio:\t";
        actual->producto.setPrecio(ValidarDatos::validarFloat());

        std::cout <<"Ingrese el nuevo anio de elaboracion:\t";
        actual->producto.setAnioElaboracion(ValidarDatos::validarEntero());
        
        std::cout <<"Ingrese el nuevo anio de vencimiento:\t";
        actual->producto.setAnioCaducidad(ValidarDatos::validarEntero());
        

        actual->getProducto().toString();
        
        std::cout <<"El producto ha sido actualizado" << std::endl;
    }

    // Mostrar todos los productos de la lista
    void ListaProducto::mostrar(){
        Nodo *tmp = this->primero;
        while(tmp){
            tmp->getProducto().toString();
            std::cout << "---------------------" << std::endl;
            tmp = tmp->getSiguiente();
        }
    }

    void sobreescribirArchivo(const std::string& nombreArchivo, ListaProducto& lista) {
        std::ofstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            Nodo* temp = lista.getPrimero();
            while (temp != nullptr) {
                archivo << temp->getProducto().getCodigo() << " " << temp->getProducto().getNombre() << " " << temp->getProducto().getPrecio() \
                << " " << temp->getProducto().getAnioElaboracion() << " " << temp->getProducto().getAnioCaducidad() << std::endl;
                temp = temp->getSiguiente();
            }

            archivo.close();
            std::cout << "Archivo sobrescrito exitosamente." << std::endl;
        } else {
            std::cout << "No se pudo abrir el archivo para sobrescribir." << std::endl;
        }
    }

    void cargarDatosDesdeArchivo(const std::string& nombreArchivo, ListaProducto& lista) {
        std::ifstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            int codigo, anioDeElaboracion, anioDeCaducidad;
            float precio;
            std::string nombre;
            while (archivo >> codigo >> nombre >> precio >> anioDeElaboracion >> anioDeCaducidad) {
                Producto producto(codigo, nombre, precio, anioDeElaboracion, anioDeCaducidad);
                lista.insertar(producto);
            }

            archivo.close();
        } else {
            std::cout << "No se pudo abrir el archivo." << std::endl;
        }
    }