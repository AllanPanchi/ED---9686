
class Nodo{
	private:
		int valor;
		Nodo *siguiente;
	public:
		Nodo(int val, Nodo *sig=NULL){
			this->valor=val;
			this->siguiente=sig;
		}

		int getValor(){
			return this->valor;
		}

		Nodo* getSiguiente(){
			return this->siguiente;
		}

		void setValor(int val){
			this->valor=val;
		}

		void setSiguiente(Nodo *sig){
			this->siguiente=sig;
		}
		
	friend class Lista;
};