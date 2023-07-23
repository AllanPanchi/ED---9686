#pragma once
#include "ManejoArchivos.cpp"

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
	void salir();

};

