#include "Aplication.h"
#include <iostream>
#include "Menu.h"
#include "ValDatos.h"


void Aplication::run()
{
	Menu menu("Menu Principal");
	menu.add(MenuItem("Registro de Nuevo Empleado.",std::bind(&Aplication::registroNuevoEmpleado,this)));
	menu.add(MenuItem("Registro Entrada / Salida.",std::bind(&Aplication::registrarEntrada,this)));
	menu.add(MenuItem("Mostrar personas registradas", std::bind(&Aplication::mostrarPersonasRegistradas,this)));
	menu.add(MenuItem("Mostrar todos los registros", std::bind(&Aplication::mostrarRegistros,this)));
	menu.add(MenuItem("Mostrar registros ordenados por cedula", std::bind(&Aplication::mostrarRegistrosPorCedula, this)));
	menu.run();

}

void Aplication::registroNuevoEmpleado()
{
	Persona persona;
	ValidarDatos validar;
	Lista<Persona> lista;

	std::string cedula, nombre, apellido;
	Fecha fechaNacimiento;

	ManejoArchivos::cargarPersonas("personas.txt", lista);

	system("cls");

	std::cout << "\nIngrese la cedula: ";
	//std::cin >> cedula;
	cedula = validar.ingresarCedulaValida();
	std::cout << "Ingrese el nombre: ";
	//std::cin >> nombre ;
	nombre= validar.validarNombreYApellido(nombre);
	std::cout << "Ingrese el apellido: ";
	//std::cin >> apellido;
	apellido= validar.validarNombreYApellido(apellido);
	std::cout << "__Fecha de nacimiento__"<< std::endl;
	std::cin >> fechaNacimiento;
	fechaNacimiento.validarFecha(fechaNacimiento);
	std::cout << "Fechga:" << fechaNacimiento.getAnio()<<std::endl;
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

	ValidarDatos validar;
	std::string cedula, estado;
	Fecha entrada, salida, eTmp, sTmp;

	estado = "Entrada";

	ManejoArchivos::cargarRegistros("registros.txt", listaRegistro);

	system("cls");

	std::cout << "\nIngrese la cedula: ";
	
	cedula = validar.ingresarCedulaValida();

	if (listaRegistro.listaVacia()) {
		estado = "Entrada";
		entrada = Fecha::getFechaActual(entrada);
		salida = Fecha::getFechaActual(salida);
		registro.setCedula(cedula);
		registro.setEntrada(entrada);
		registro.setSalida(salida);
		registro.setEstado(estado);
		listaRegistro.insertar(registro);
		ManejoArchivos::guardarRegistros("registros.txt", listaRegistro);
		return;
	}

	if (listaRegistro.buscarUltimo(cedula) == nullptr) {
		estado = "Entrada";
		entrada = Fecha::getFechaActual(entrada);
		salida = Fecha::getFechaActual(salida);
		registro.setCedula(cedula);
		registro.setEntrada(entrada);
		registro.setSalida(salida);
		registro.setEstado(estado);
		listaRegistro.insertar(registro);
		ManejoArchivos::guardarRegistros("registros.txt", listaRegistro);
		return;
	}

	Nodo<Registro> *tmp = listaRegistro.buscarUltimo(cedula);	

	if(tmp){
		if(tmp->getValor().getEstado() == "Entrada"){
			estado = "Salida";
		}
	}

	eTmp = tmp->getValor().getEntrada();
	sTmp = tmp->getValor().getSalida();

	if(estado == "Salida"){
		registro.setCedula(cedula);
		salida = Fecha::getFechaActual(salida);
		registro.setSalida(salida);
		registro.setEntrada(eTmp);
		registro.setEstado(estado);
		tmp->setValor(registro);
		ManejoArchivos::guardarRegistros("registros.txt", listaRegistro);
		return;
	}

	if(estado == "Entrada"){
		registro.setCedula(cedula);
		entrada = Fecha::getFechaActual(entrada);
		salida = Fecha::getFechaActual(salida);
		registro.setEntrada(entrada);
		registro.setSalida(salida);
		registro.setEstado(estado);
		listaRegistro.insertar(registro);
		ManejoArchivos::guardarRegistros("registros.txt", listaRegistro);
		return;
	}

}

void Aplication::mostrarPersonasRegistradas()
{
	Lista<Persona> lista;
	ManejoArchivos::cargarPersonas("personas.txt", lista);
	if (lista.listaVacia()){
		std::cout << "No hay personas registradas." << std::endl;
	}
	lista.mostrar();
}

void Aplication::mostrarRegistros()
{
	Lista<Registro> lista;
	ManejoArchivos::cargarRegistros("registros.txt", lista);
	if (lista.listaVacia()){
		std::cout << "No hay registros." << std::endl;
	}
	lista.mostrar();
}

void Aplication::mostrarRegistrosPorCedula()
{
	Lista<Registro> lista;
	Lista<Registro> listaOrdenada;
	ManejoArchivos::cargarRegistros("registros.txt", lista);
	if (lista.listaVacia()){
		std::cout << "No hay registros." << std::endl;
	}
	
	lista.bucketSortCedula();
}