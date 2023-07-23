#ifndef IMAGEN_H
#define IMAGEN_H
#include <string>
#include <windows.h>
#include "EasyBMP.cpp"
class Imagen{
	public:
		Imagen(std::string);
		void setArchivo (std::string);
		std::string getArchivo();
		int imprimirImagenEnConsola();
	private:
		void dibujarImagen(std::string, HDC*);
		std::string archivo;
};
#endif