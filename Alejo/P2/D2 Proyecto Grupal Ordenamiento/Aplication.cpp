#include "Aplication.h"
#include <iostream>
#include "Menu.h"

void Aplication::run()
{
	Menu menu("Menu Principal");
	menu.add(MenuItem("Registro de Nuevo Empleado.",std::bind(&Aplication::registroNuevoEmpleado,this)));
	menu.add(MenuItem("Registro Entrada / Salida.",std::bind(&Aplication::registrarEntrada,this)));
	menu.add(MenuItem("Mostrar personas registradas", std::bind(&Aplication::mostrarPersonasRegistradas,this)));
	menu.add(MenuItem("Mostrar todos los registros", std::bind(&Aplication::mostrarRegistros,this)));
	menu.run();

}

void Aplication::registroNuevoEmpleado()
{
	Persona persona;
	Lista<Persona> lista;

	std::string cedula, nombre, apellido;
	Fecha fechaNacimiento;

	ManejoArchivos::cargarPersonas("personas.txt", lista);

	system("cls");

	std::cout << "\nIngrese la cedula: ";
	std::cin >> cedula;
	std::cout << "Ingrese el nombre: ";
	std::cin >> nombre;
	std::cout << "Ingrese el apellido: ";
	std::cin >> apellido;
	std::cout << "Ingrese la fecha de nacimiento: ";
	std::cin >> fechaNacimiento;
	persona.setCedula(cedula);
	persona.setNombre(nombre);
	persona.setApellido(apellido);
	persona.setFechaNacimiento(fechaNacimiento);

	lista.insertar(persona);

	ManejoArchivos::guardarPersonas("personas.txt", lista);

	std::cout << "Persona guardada con exito." << std::endl;

}


void Aplication::registrarEntrada(){
	
	Registro registro;
	Lista<Registro> listaRegistro;

	std::string cedula, estado;
	Fecha entrada, salida, eTmp, sTmp;

	estado = "Entrada";

	ManejoArchivos::cargarRegistros("registros.txt", listaRegistro);

	system("cls");

	std::cout << "\nIngrese la cedula: ";
	std::cin >> cedula;

	Nodo<Registro> *tmp = listaRegistro.buscarUltimo(cedula);
	if(tmp){
		if(tmp->getValor().getEstado() == "Entrada"){
			estado = "Salida";
		}
	}

	eTmp = tmp->getValor().getEntrada();
	sTmp = tmp->getValor().getSalida();

	if(estado == "Entrada"){
		registro.setCedula(cedula);
		entrada = Fecha::getFechaActual(entrada);
		registro.setEntrada(entrada);
		registro.setSalida(sTmp);
		registro.setEstado(estado);
		tmp->setValor(registro);
		listaRegistro.mostrar();
		ManejoArchivos::guardarRegistros("registros.txt", listaRegistro);
		return;
	}

	if(estado == "Salida"){
		registro.setCedula(cedula);
		salida = Fecha::getFechaActual(salida);
		registro.setSalida(salida);
		registro.setEntrada(eTmp);
		registro.setEstado(estado);
		tmp->setValor(registro);
		listaRegistro.mostrar();
		ManejoArchivos::guardarRegistros("registros.txt", listaRegistro);
		return;
	}

}

void Aplication::mostrarPersonasRegistradas()
{
	//operacionesPersona.mostrarPersonasRegistradas();
	system("pause");
}

void Aplication::mostrarRegistros()
{
	//registro.mostrarRegistros();
	system("pause");
}