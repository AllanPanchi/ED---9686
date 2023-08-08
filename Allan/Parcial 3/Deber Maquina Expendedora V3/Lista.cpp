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
    void Lista<T>::insertar(T dato){
        Nodo<T> *nuevo = new Nodo(dato);
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
			Nodo<T>* aux = this->primero;
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
					Nodo<T>* aux2 = aux->getSiguiente();
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
    template <typename T>
    Nodo<T>* Lista<T>::buscar(std::string nombre){
        Nodo<T> *tmp = this->primero;
        for(int i = 0; i < this->size(); i++){
            if(tmp->getValor().getNombre() == nombre){
                return tmp;
            }
            tmp = tmp->getSiguiente();
        }
        return NULL;
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
        for (int i = 0; i < this->size(); i++) {
            Nodo<T>* nodoSiguiente = nodoActual->getSiguiente();
            delete nodoActual;
            nodoActual = nodoSiguiente;
        }

        this->primero = nullptr;
        this->actual = nullptr;
    }

