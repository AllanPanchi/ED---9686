/**
 * @file Aplication.h
 * @author Alejandro Andrade - Alex Trejo
 * @brief 
 * @version 1.0
 * @date 2023-07-23
 * @copyright Copyright (c) 2023
 * 
 */

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
	void ayuda();

	void salir();

};

