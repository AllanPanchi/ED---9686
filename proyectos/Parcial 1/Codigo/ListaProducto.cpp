#include "ListaProducto.h"

    Producto* ListaProducto::getPrimero(){
        return this->primero;
    }

    Producto* ListaProducto::getActual(){
        return this->actual;
    }

    void ListaProducto::setPrimero(Producto *primero){
        this->primero=primero;
    }

    void ListaProducto::setActual(Producto *actual){
        this->actual=actual;
    }

    int ListaProducto::size(){
        int cont=0;
        Producto *tmp=this->primero;
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
        Producto *nuevo = new Producto(producto);
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
        Producto *tmp = this->primero;
        Producto *tmp2 = this->primero;
        while(tmp){
            if(tmp->getId() == codigo){
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
    Producto* ListaProducto::buscar(int codigo){
        Producto *tmp = this->primero;
        while(tmp){
            if(tmp->getId() == codigo){
                return tmp;
            }
            tmp = tmp->siguiente;
        }
        return NULL;
    }

    // Mostrar todos los productos de la lista
    void ListaProducto::mostrar(){
        Producto *tmp = this->primero;
        while(tmp){
            cout << tmp->toString() << endl;
            tmp = tmp->siguiente;
        }
    }

    // actualizar el atributo nombre que es de tipo string de un producto de la lista en el que se busca por codigo
    void ListaProducto::actualizarNombre(int codigo, std::string nombre){
        Producto *tmp = this->primero;
        while(tmp){
            if(tmp->getId() == codigo){
                tmp->setNombre(nombre);
                break;
            }
            tmp = tmp->siguiente;
        }
    }

    // actualizar el atributo precio que es de tipo double de un producto de la lista en el que se busca por codigo
    void ListaProducto::actualizarPrecio(int codigo, float precio){
        Producto *tmp = this->primero;
        while(tmp){
            if(tmp->getId() == codigo){
                tmp->setPrecio(precio);
                break;
            }
            tmp = tmp->siguiente;
        }
    }

    // actualizar el atributo fechaElaboracion que es de tipo Fecha de un producto de la lista en el que se busca por codigo
    void ListaProducto::actualizarFechaElaboracion(int codigo, Fecha fechaElaboracion){
        Producto *tmp = this->primero;
        while(tmp){
            if(tmp->getId() == codigo){
                tmp->setFechaElaboracion(fechaElaboracion);
                break;
            }
            tmp = tmp->siguiente;
        }
    }

    // actualizar el atributo fechaCaducidad que es de tipo Fecha de un producto de la lista en el que se busca por codigo
    void ListaProducto::actualizarFechaCaducidad(int codigo, Fecha fechaCaducidad){
        Producto *tmp = this->primero;
        while(tmp){
            if(tmp->getId() == codigo){
                tmp->setFechaCaducidad(fechaCaducidad);
                break;
            }
            tmp = tmp->siguiente;
        }
    }