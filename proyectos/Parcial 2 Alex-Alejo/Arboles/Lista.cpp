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

    template <typename T>
    Nodo<T>* Lista<T>::getPrimero(){
        return this->primero;
    }

    template <typename T>
    Nodo<T>* Lista<T>::getActual(){
        return this->actual;
    }

    template <typename T>
    void Lista<T>::setPrimero(Nodo<T> *primero){
        this->primero=primero;
    }

    template <typename T>
    void Lista<T>::setActual(Nodo<T> *actual){
        this->actual=actual;
    }

    template <typename T>
    int Lista<T>::size(){
        int cont=1;
        Nodo<T> *tmp=this->primero;
        while(tmp != this->actual){
            cont++;
            tmp=tmp->getSiguiente();
        }
        return cont;
    }

    template <typename T>
    bool Lista<T>::listaVacia(){
        return (this->actual==NULL);
    }

    template <typename T>
    Lista<T>::Lista(){
        this->primero=NULL;
        this->actual=NULL;
    }

    template <typename T>
    void Lista<T>::insertar(T registro){
        Nodo<T>* nuevo = new Nodo(registro);
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

    template <typename T>    
    void Lista<T>::eliminar(std::string cedula){
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
			Nodo<T>* aux = this->primero;
			while (aux->getSiguiente() != this->primero)
			{
				if (aux->getSiguiente()->getValor().getCedula() == cedula)
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

    // Buscar un producto en la lista por medio del atributo codigo que es int y retornarlo
    template <typename T>
    Nodo<T>* Lista<T>::buscar(std::string cedula){
        Nodo<T> *tmp = this->primero;
        while(tmp){
            if(tmp->getValor().getCedula() == cedula){
                return tmp;
            }
            tmp = tmp->getSiguiente();
        }
        return NULL;
    }

    // Buscar un producto en la lista por medio del atrubuto codigo que es int y retornarlo
    template <typename T>
    Nodo<T>* Lista<T>::buscarPorSueldo(float sueldo){
        Nodo<T> *tmp = this->primero;
        while(tmp){
            if(tmp->getValor().getSueldo() == sueldo){
                return tmp;
            }
            tmp = tmp->getSiguiente();
        }
        return NULL;
    }

    // Buscar un producto en la lista por medio del atrubuto codigo que es int y retornarlo
    template <typename T>
    Nodo<T>* Lista<T>::buscarPorCedula(int cedula){
        Nodo<T> *tmp = this->primero;
        while(tmp){
            if(std::atoi(tmp->getValor().getCedula().c_str()) == cedula){
                return tmp;
            }
            tmp = tmp->getSiguiente();
        }
        return NULL;
    }

    template <typename T>
    Nodo<T>* Lista<T>::buscarUltimo(std::string cedula){
        Nodo<T> *tmp = this->primero->getAnterior();
        while(tmp != this->primero){
            if(tmp->getValor().getCedula() == cedula){
                return tmp;
            }
            tmp = tmp->getAnterior();
        }
        if (tmp->getValor().getCedula() == cedula)
        {
            return tmp;
        }
        return NULL;
    }

    // Actualizar el estado de un registro la lista
    template <typename T>
    void Lista<T>::actualizarEstado(Nodo<T> *actual, T valor){
        actual->setValor(valor);
        actual->getValor().toString();
    }

    //Mostrar todos los productos de la lista
    template <typename T>
    void Lista<T>::mostrar(){
        if (this->primero != nullptr)
	    {
            Nodo<T>* aux = this->primero;
            do
            {
                aux->getValor().toString();
                aux = aux->getSiguiente();
            } while (aux != this->primero);
            std::cout << std::endl;
	    }
    }

    template <typename T>
    void Lista<T>::vaciarLista() {
        Nodo<T>* nodoActual = this->primero;
        while (nodoActual != nullptr) {
            Nodo<T>* nodoSiguiente = nodoActual->getAnterior();
            delete nodoActual;
            nodoActual = nodoSiguiente;
        }
        this->primero = nullptr;
        this->actual = nullptr;
    }

    // Función de partición para el Quicksort
    int partition(std::vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    // Implementación del algoritmo Quicksort
    void quicksort(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quicksort(arr, low, pi - 1);
            quicksort(arr, pi + 1, high);
        }
    }

 
    

    