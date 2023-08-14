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

    template <typename T>
    void Lista<T>::bucketSortCedula(){
        int cedula;
        int j = 0;
        Nodo<T> *tmp = this->primero;
        int n = this->size();
        int b[n];

        while(tmp != this->actual){
            cedula = std::stoi(tmp->getValor().getCedula());
            b[j] = cedula;
            j++;
            tmp = tmp->getSiguiente();
            if (tmp == this->actual)
            {
                b[j] = std::stoi(tmp->getValor().getCedula());
            }
        }
        
        int size = sizeof(b) / sizeof(b[0]);
        int numBuckets = n - 1;

        int maxVal = b[0];
        int minVal = b[0];
        for (int i = 1; i < size; i++) {
            if (b[i] > maxVal) {
                maxVal = b[i];
            }
            if (b[i] < minVal) {
                minVal = b[i];
            }
        }

        // Calcular el tamaño de cada balde
        float range = (maxVal - minVal + 1) / static_cast<float>(numBuckets);

        // Crear los baldes (buckets)
        std::vector<std::vector<int>> buckets(numBuckets);

        // Colocar los elementos en los baldes correspondientes
        for (int i = 0; i < size; i++) {
            int bucketIndex = static_cast<int>((b[i] - minVal) / range);
            buckets[bucketIndex].push_back(b[i]);
        }

        // Ordenar cada balde utilizando Quicksort
        for (int i = 0; i < numBuckets; i++) {
            quicksort(buckets[i], 0, buckets[i].size() - 1);
        }

        // Concatenar los baldes ordenados en el arreglo original
        int index = 0;
        for (int i = 0; i < numBuckets; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                b[index++] = buckets[i][j];
            }
        }

        Lista<T> listaOrdenada;
        Nodo<T> *tmp2 = this->primero;
        for (int i = 0; i < n; i++)
        {
            tmp2 = this->buscar(std::to_string(b[i]));
            if ( tmp2->getValor().getCedula() == std::to_string(b[i]))
            {
                listaOrdenada.insertar(tmp2->getValor());
            }
            
        }

        listaOrdenada.mostrar();
        
    }
