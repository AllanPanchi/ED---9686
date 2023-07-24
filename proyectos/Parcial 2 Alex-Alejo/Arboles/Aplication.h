#pragma once
#include "ManejoArchivos.cpp"
#include ".\Ext\Backup.cpp"
#include ".\Ext\Imagen.cpp"

class Aplication
{
public:
	Aplication() {};
	void run();
	void registroNuevoEmpleado();
	void registrarEntrada();
	void mostrarPersonasRegistradas();
	void mostrarRegistros();
	void mostrarRegistrosPorCedula();
	void mostrarEmpleadosPorSueldo();
	void buscarRegistroPorFecha();
	void buscarRegistrosPorCedula();
	void extras();

	void mainMenu();
	void backup();
	void restaurarBackup();
	void generarBackup();
	void imprimirEnConsola();

	void salir();

};

