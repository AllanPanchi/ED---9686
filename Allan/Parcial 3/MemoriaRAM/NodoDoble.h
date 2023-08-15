#ifndef NODODOBLE_H
#define NODODOBLE_H

template <typename T>
class NodoDoble
{
	private:
		T dato;
		NodoDoble<T>* siguiente;
		NodoDoble<T>* anterior;
		
	public:
		NodoDoble(T);
		~NodoDoble();
		
		void setDato(T);
		T getDato();
		void setSiguiente(NodoDoble<T>*);
		NodoDoble<T>* getSiguiente();
		void setAnterior(NodoDoble<T>*);
		NodoDoble<T>* getAnterior();
		
	protected:
};

#endif

//Aquí hay que tener cuidado ya que estoy mandando los Nodos como Template, tal vez cambie...