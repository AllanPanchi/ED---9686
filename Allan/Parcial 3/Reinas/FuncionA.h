#include "Alfil.cpp"
#include "Tablero.h"

using namespace std;
class FuncionA:public Tablero{
	
	public:
	FuncionA(Alfil *alf){
		cout<<"Constructor"<<endl;
		this->alfil=alf;
		this->encerarTablero();
		this->crearArchivo();
	}
	fstream archivo;
	Alfil *alfil;
	void encerarTablero(void);
   	void crearArchivo(void);
   	void bloquear(int x, int y);
   	void mostrar(void);
   	void quitarRelleno(int x, int y);
    void solucion(int x, int y, int n1);
    void solucionReinas(void);
	void bloquearAlfiles(int, int);
	void solucionAlfilA(int i, int j);
	void solucionAlfiles(int, int, int);
	void cuadrado();
	void mostrarAlfil(void);
	void circulo(int fila, int columna);
};
