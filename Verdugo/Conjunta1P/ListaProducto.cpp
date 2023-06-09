
#include "ListaProducto.h"
#include "Nodo.h"


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
    Nodo* ListaProducto::buscar(int codigo){
        Nodo *tmp = this->primero;
        while(tmp){
            if(tmp->getProducto().getCodigo() == codigo){
                return tmp;
            }
            tmp = tmp->getSiguiente();
        }
        return NULL;
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

// Función para determinar la cantidad de registros en un año específico
int ListaProducto::contarRegistrosEnAnio(int anio) {
    int contador = 0;
    Nodo* tmp = this->primero;
    while (tmp) {
        if (tmp->getProducto().getAnioElaboracion() == anio) {
            contador++;
        }
        tmp = tmp->getSiguiente();
    }
    return contador;
}
