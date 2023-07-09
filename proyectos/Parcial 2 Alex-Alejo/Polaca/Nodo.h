
template <typename T>
class Nodo
{
private:
    T dato;
    Nodo<T>* siguiente;
public:
    Nodo(T dato);
    Nodo(T dato, Nodo<T>* siguiente);
    T getDato();
    Nodo<T>* getSiguiente();
    void setDato(T dato);
    void setSiguiente(Nodo<T>* siguiente);
};