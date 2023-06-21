/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Materia: Estructura de Datos
NRC: 9686
Integrantes:    Alejandro Andrade
                Allan Panchi
                Alex Trejo 
                Sebastian Verdugo
Fecha de inicio: 15/06/2023
Fecha de modificación: 15/06/2023

Ordenamiento de lista circular doblemente enlazadas
*/
#include "Lista.h"
#include "ValDatos.h"
#include <fstream>


    Nodo<Registro>* Lista::getPrimero(){
        return this->primero;
    }

    Nodo<Registro>* Lista::getActual(){
        return this->actual;
    }

    void Lista::setPrimero(Nodo<Registro> *primero){
        this->primero=primero;
    }

    void Lista::setActual(Nodo<Registro> *actual){
        this->actual=actual;
    }

    int Lista::size(){
        int cont=0;
        Nodo<Registro> *tmp=this->primero;
        while(tmp){
            cont++;
            tmp=tmp->getSiguiente();
        }
        return cont;
    }

    bool Lista::listaVacia(){
        return (this->actual==NULL);
    }

    Lista::Lista(){
        this->primero=NULL;
        this->actual=NULL;
    }

    void Lista::insertar(Registro registro){
        Nodo<Registro>* nuevo = new Nodo<Registro>(registro);
	if (this->primero == nullptr)
	{
		this->primero = nuevo;
		this->actual = nuevo;
		this->primero->setSiguiente(this->actual);
		this->primero->setAnterior(this->actual);
		this->actual->setSiguiente(this->primero);
		this->actual->setAnterior(this->primero);
	}
	else
	{
		this->actual->setSiguiente(nuevo);
		nuevo->setAnterior(this->actual);
		nuevo->setSiguiente(this->primero);
		this->primero->setAnterior(nuevo);
		this->actual = nuevo;
	}
    }
    
    void Lista::eliminar(std::string cedula){
        if (this->primero != nullptr)
	{
		if (this->primero->getValor().getPersona().getCedula() == cedula)
		{
			Nodo<Registro>* aux = this->primero;
			this->primero = this->primero->getSiguiente();
			this->primero->setAnterior(this->actual);
			this->actual->setSiguiente(this->primero);
			delete aux;
		}
		else
		{
			Nodo<Registro>* aux = this->primero;
			while (aux->getSiguiente() != this->primero)
			{
				if (aux->getSiguiente()->getValor().getPersona().getCedula() == cedula)
				{
					Nodo<Registro>* aux2 = aux->getSiguiente();
					aux->setSiguiente(aux2->getSiguiente());
					aux2->getSiguiente()->setAnterior(aux);
					delete aux2;
					break;
				}
				aux = aux->getSiguiente();
			}
		}
	}

    }


    // Buscar un producto en la lista por medio del atrubuto codigo que es int y retornarlo
    Nodo<Registro>* Lista::buscar(std::string cedula){
        Nodo<Registro> *tmp = this->primero;
        while(tmp){
            if(tmp->getValor().getPersona().getCedula() == cedula){
                return tmp;
            }
            tmp = tmp->getSiguiente();
        }
        return NULL;
    }

    // void Lista::actualizar(Nodo<Registro> *actual){
        
    //     int fecha = 1000;
    //     float precio = 0.0;

    //     actual->getProducto().toString();
    //     std::cout << "Ingrese el nuevo nombre de producto:\t";
       
    //     actual->producto.setNombre(ValidarDatos::validarString());

    //     std::cout <<"Ingrese el nuevo precio:\t";
    //     precio = ValidarDatos::validarFloat();
    //     precio = ValidarDatos::validarPrecio(precio);
    //     actual->producto.setPrecio(precio);

    //     std::cout <<"Ingrese el nuevo anio de elaboracion:\t";
    //     fecha = ValidarDatos::validarFecha(fecha);
    //     actual->producto.setAnioElaboracion(fecha);
        
    //     std::cout <<"Ingrese el nuevo anio de vencimiento:\t";
    //     fecha = ValidarDatos::validarFecha(fecha);
    //     actual->producto.setAnioCaducidad(fecha);
        

    //     actual->getProducto().toString();
        
    //     std::cout <<"El producto ha sido actualizado" << std::endl;
    // }

    //Mostrar todos los productos de la lista
    void Lista::mostrar(){
        if (this->primero != nullptr)
	{
		Nodo<Registro>* aux = this->primero;
		do
		{
			aux->getValor().toString();
			aux = aux->getSiguiente();
		} while (aux != this->primero);
		std::cout << std::endl;
	}
    }

    // void sobreescribirArchivo(const std::string& nombreArchivo, Lista& lista) {
    //     std::ofstream archivo(nombreArchivo);

    //     if (archivo.is_open()) {
    //         Nodo<Registro>* temp = lista.getPrimero();
    //         while (temp != nullptr) {
    //             archivo << temp->getProducto().getCodigo() << " " << temp->getProducto().getNombre() << " " << temp->getProducto().getPrecio()
    //             << " " << temp->getProducto().getAnioElaboracion() << " " << temp->getProducto().getAnioCaducidad() << std::endl;
    //             temp = temp->getSiguiente();
    //         }

    //         archivo.close();
    //         std::cout << "Archivo sobrescrito exitosamente." << std::endl;
    //     } else {
    //         std::cout << "No se pudo abrir el archivo para sobrescribir." << std::endl;
    //     }
    // }

    // void cargarDatosDesdeArchivo(const std::string& nombreArchivo, Lista& lista) {
    //     std::ifstream archivo(nombreArchivo);

    //     if (archivo.is_open()) {
    //         int codigo, anioDeElaboracion, anioDeCaducidad;
    //         float precio;
    //         std::string nombre;
    //         while (archivo >> codigo >> nombre >> precio >> anioDeElaboracion >> anioDeCaducidad) {
    //             Registro producto(codigo, nombre, precio, anioDeElaboracion, anioDeCaducidad);
    //             lista.insertar(producto);
    //         }

    //         archivo.close();
    //     } else {
    //         std::cout << "No se pudo abrir el archivo." << std::endl;
    //     }
    // }

    void Lista::vaciarLista() {
        Nodo<Registro>* nodoActual = this->primero;
        while (nodoActual != nullptr) {
            Nodo<Registro>* nodoSiguiente = nodoActual->getAnterior();
            delete nodoActual;
            nodoActual = nodoSiguiente;
        }
        this->primero = nullptr;
        this->actual = nullptr;
    }