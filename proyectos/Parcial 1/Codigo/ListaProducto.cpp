#include "ListaProducto.h"

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
            tmp=tmp->siguiente;
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
            this->actual->siguiente=nuevo;
        }
        this->actual=nuevo;
    }

    // Eliminar un producto de la lista
    void ListaProducto::eliminar(int codigo){
        Nodo *tmp = this->primero;
        Nodo *tmp2 = this->primero;
        while(tmp){
            if(tmp->getSiguiente()->getProducto().getCodigo() == codigo){
                if(tmp == this->primero){
                    this->primero = tmp->siguiente;
                    delete tmp;
                    break;
                }
                else{
                    tmp2->siguiente = tmp->siguiente;
                    delete tmp;
                    break;
                }
            }
            tmp2 = tmp;
            tmp = tmp->siguiente;
        }
    }

    // Buscar un producto en la lista por medio del atrubuto codigo que es int y retornarlo
    Nodo* ListaProducto::buscar(int codigo){
        Nodo *tmp = this->primero;
        while(tmp){
            if(tmp->getSiguiente()->getProducto().getCodigo() == codigo){
                return tmp;
            }
            tmp = tmp->siguiente;
        }
        return NULL;
    }

    // Mostrar todos los productos de la lista
    void ListaProducto::mostrar(){
        Nodo *tmp = this->primero;
        while(tmp){
            tmp->getSiguiente()->getProducto().toString();
            tmp = tmp->siguiente;
        }
    }

    // actualizar el atributo nombre que es de tipo string de un producto de la lista en el que se busca por codigo
    
    void ListaProducto::actualizarNombre(int codigo, std::string nombre){
        Nodo *tmp = this->primero;
        while(tmp){
            if(tmp->getSiguiente()->getProducto().getCodigo() == codigo){
                tmp->getSiguiente()->getProducto().setNombre(nombre);
                break;
            }
            tmp = tmp->siguiente;
        }
    }

    // actualizar el atributo precio que es de tipo double de un producto de la lista en el que se busca por codigo
    void ListaProducto::actualizarPrecio(int codigo, float precio){
        Nodo *tmp = this->primero;
        while(tmp){
            if(tmp->getSiguiente()->getProducto().getCodigo() == codigo){
                tmp->getSiguiente()->getProducto().setPrecio(precio);
                break;
            }
            tmp = tmp->siguiente;
        }
    }

    // actualizar el atributo fechaElaboracion que es de tipo Fecha de un producto de la lista en el que se busca por codigo
    void ListaProducto::actualizarFechaElaboracion(int codigo, FechaConcreta fechaElaboracion){
        Nodo *tmp = this->primero;
        while(tmp){
            if(tmp->getSiguiente()->getProducto().getCodigo() == codigo){
                tmp->getSiguiente()->getProducto().setFechaElaboracion(fechaElaboracion);
                break;
            }
            tmp = tmp->siguiente;
        }
    }

    // actualizar el atributo fechaCaducidad que es de tipo Fecha de un producto de la lista en el que se busca por codigo
    void ListaProducto::actualizarFechaCaducidad(int codigo, FechaConcreta fechaCaducidad){
        Nodo *tmp = this->primero;
        while(tmp){
            if(tmp->getSiguiente()->getProducto().getCodigo() == codigo){
                tmp->getSiguiente()->getProducto().setFechaCaducidad(fechaCaducidad);
                break;
            }
            tmp = tmp->siguiente;
        }
    }