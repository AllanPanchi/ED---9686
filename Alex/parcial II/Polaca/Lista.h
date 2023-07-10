
#include "Nodo.cpp"

template <typename T>
class Lista
{
private:
    Nodo<T>* primero;
    Nodo<T>* ultimo;
public:
    void setPrimero(Nodo<T>* primero);
    void setUltimo(Nodo<T>* ultimo);
    Nodo<T>* getPrimero();
    Nodo<T>* getUltimo();
    int size();
    void insertar(T dato);
    void eliminar(T dato);
    Nodo<T>* buscar(T dato);
    bool estaVacia();

};
