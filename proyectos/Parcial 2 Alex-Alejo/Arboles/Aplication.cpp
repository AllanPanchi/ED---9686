#include "Aplication.h"
#include <iostream>
#include "Menu.h"
#include "ValDatos.h"
#include "ArbolBinario.cpp"
#include <fstream>
#include <filesystem>

/**
*@brief Función de ejecución del programa principal 
*/
  
void Aplication::run()
{
	Menu menu("Menu Principal");
	menu.add(MenuItem("Registro de Nuevo Empleado.",std::bind(&Aplication::registroNuevoEmpleado,this)));
	menu.add(MenuItem("Registro Entrada / Salida.",std::bind(&Aplication::registrarEntrada,this)));
	menu.add(MenuItem("Mostrar personas registradas", std::bind(&Aplication::mostrarPersonasRegistradas,this)));
	menu.add(MenuItem("Mostrar todos los registros", std::bind(&Aplication::mostrarRegistros,this)));
	menu.add(MenuItem("Mostrar registros ordenados por cedula", std::bind(&Aplication::mostrarRegistrosPorCedula, this)));
	menu.add(MenuItem("Mostrar personas ordenadas por sueldo", std::bind(&Aplication::mostrarEmpleadosPorSueldo, this)));
	menu.add(MenuItem("Buscar registros por fecha", std::bind(&Aplication::buscarRegistroPorFecha, this)));
	menu.add(MenuItem("Buscar registros por cedula", std::bind(&Aplication::buscarRegistrosPorCedula, this)));
	menu.add(MenuItem("Extras", std::bind(&Aplication::extras, this)));
	menu.add(MenuItem("Salir", std::bind(&Aplication::salir,this)));
	menu.run();

}

/**
*@brief Función de registro de nuevo empleado
*/
void Aplication::registroNuevoEmpleado()
{
	
	Empleado persona;
	ValidarDatos validar;
	Lista<Empleado> lista;
	float sueldo;
	std::string cedula, nombre, apellido;
	Fecha fechaNacimiento;
	ArbolBinario<float> arbol;

	ManejoArchivos::cargarPersonas("personas.txt", lista);

	system("cls");

	std::cout << "Registro de nuevo empleado." << std::endl;

	std::cout << "\nIngrese la cedula: ";
	cedula = validar.ingresarCedulaValida();

	if(!lista.cedulaEnLista(cedula)){
		
		std::cout << "Ingrese el nombre: ";
		nombre= validar.validarNombreYApellido(nombre);
		
		std::cout << "Ingrese el apellido: ";
		apellido= validar.validarNombreYApellido(apellido);
		
		std::cout << "Ingrese el sueldo: ";
		sueldo=validar.validarFloat();
		arbol.insertarNodo(sueldo);
		
		std::cout << "__Fecha de nacimiento__"<< std::endl;
		fechaNacimiento.validarFechaNacimiento(fechaNacimiento);
		
		persona.setSueldo(sueldo);
		persona.setCedula(cedula);
		persona.setNombre(nombre);
		persona.setApellido(apellido);
		persona.setFechaNacimiento(fechaNacimiento);

		lista.insertar(persona);

		ManejoArchivos::guardarPersonas("personas.txt", lista);


		std::cout << "Persona guardada con exito." << std::endl;

	}else{
		std::cout << " Ya se  encuentra registrado!!" << std::endl;
	}
	system("python ./graficos/0_O(n).py");
	
}

/**
*@brief Función de registro de entrada y salida de un empleado
*/
void Aplication::registrarEntrada(){

	Registro registro;
	Lista<Registro> listaRegistro;

	Empleado persona;
	Lista<Empleado> listaPersonas;

	ValidarDatos validar;
	std::string cedula, estado;
	Fecha entrada, salida, eTmp, sTmp;

	estado = "Entrada";

	ManejoArchivos::cargarRegistros("registros.txt", listaRegistro);
	ManejoArchivos::cargarPersonas("personas.txt", listaPersonas);

	system("cls");

	std::cout << "\nIngrese la cedula: ";
	
	cedula = validar.ingresarCedulaValida();

	if(listaPersonas.buscar(cedula) == nullptr){
		std::cout << "El empleado no existe." << std::endl;
		return;
	}

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

	system("python ./graficos/0_O(n).py");

}

/**
*@brief Función de mostrar personas registradas
*/
void Aplication::mostrarPersonasRegistradas()
{
	Lista<Empleado> lista;
	ManejoArchivos::cargarPersonas("personas.txt", lista);
	ArbolBinario<float> arbol;
	
	if (lista.listaVacia()){
		std::cout << "No hay personas registradas." << std::endl;
		return;
	}

	Nodo<Empleado> *tmp = lista.getPrimero();
	for(int i = 0; i < lista.size(); i++){
		arbol.insertarNodo(tmp->getValor().getSueldo());
		tmp = tmp->getSiguiente();
	}

	lista.mostrar();
	system("python ./graficos/0_O(n).py");
}

/**
*@brief Función de mostrar todos los registros
*/
void Aplication::mostrarRegistros()
{
	Lista<Registro> lista;
	ManejoArchivos::cargarRegistros("registros.txt", lista);
	if (lista.listaVacia()){
		std::cout << "No hay registros." << std::endl;
	}
	lista.mostrar();
	system("python ./graficos/0_O(n).py");
}

/**
* @brief Función de partición para el Quicksort
* @param arr Vector de flotantes
* @param low Valor entero
* @param high Valor entero
* @return Valor entero
*/
// Función de partición para el Quicksort
int partition(std::vector<float>& arr, int low, int high) {
    float pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

/**
*@brief Función de ordenamiento Quicksort
*@param arr Vector de flotantes
*@param low Valor entero
*@param high Valor entero
*/
// Implementación del algoritmo Quicksort
void quicksort(std::vector<float>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}


/**
*@brief Función de mostrar registros ordenados por cedula
*/
void Aplication::mostrarRegistrosPorCedula()
{
	const auto ordenarPorCedula = [](Lista<Registro>& lista) -> Lista<Registro> {
		int cedula;
		Nodo<Registro>* tmp = lista.getPrimero();
		int size = lista.size();
		std::vector<int> arr(size);
		int cont = 0;
		while (cont <= size) {
			arr[cont] = std::atoi( tmp->getValor().getCedula().c_str());
			cont++;
			tmp = tmp->getSiguiente();
		}

		std::vector<int> arr2(size);
		quicksort(arr, 0, size - 1);
		arr2 = arr;

		Lista<Registro> listaOrdenada;
		Nodo<Registro>* tmp2 = lista.getPrimero();
		for (int i = 0; i < size; i++)
        {
            tmp2 = lista.buscarPorCedula(arr2[i]);
            if ( std::atoi (tmp2->getValor().getCedula().c_str()) == arr2[i])
            {
                listaOrdenada.insertar(tmp2->getValor());
            }
            
        }
		
		listaOrdenada.mostrar();

		return listaOrdenada;

	};

	Lista<Registro> lista;
	ManejoArchivos::cargarRegistros("registros.txt", lista);
	if (lista.listaVacia()){
		std::cout << "No hay personas registradas." << std::endl;
	}

	Lista<Registro> listaOrdenada = ordenarPorCedula(lista);
		
	system("python ./graficos/0_O(logn).py");
}


/**
*@brief Función de mostrar personas ordenadas por sueldo
*/
void Aplication::mostrarEmpleadosPorSueldo()
{
	
	const auto ordenarPorSueldo = [](Lista<Empleado>& lista) -> Lista<Empleado> {
		float sueldo;
		Nodo<Empleado>* tmp = lista.getPrimero();
		int size = lista.size();
		std::vector<float> arr(size);
		int cont = 0;
		while (cont <= size) {
			arr[cont] = tmp->getValor().getSueldo();
			cont++;
			tmp = tmp->getSiguiente();
		}

		std::vector<float> arr2(size);
		quicksort(arr, 0, size - 1);
		arr2 = arr;

		Lista<Empleado> listaOrdenada;
		Nodo<Empleado>* tmp2 = lista.getPrimero();
		for (int i = 0; i < size; i++)
        {
            tmp2 = lista.buscarPorSueldo(arr2[i]);
            if ( tmp2->getValor().getSueldo() == arr2[i])
            {
                listaOrdenada.insertar(tmp2->getValor());
            }
            
        }
	
		return listaOrdenada;

	};

	Lista<Empleado> lista;
	ManejoArchivos::cargarPersonas("personas.txt", lista);
	if (lista.listaVacia()){
		std::cout << "No hay personas registradas." << std::endl;
	}

	Lista<Empleado> listaOrdenada = ordenarPorSueldo(lista);
	listaOrdenada.mostrar();

	system("python .graficos//0_O(logn).py");
}

/**
*@brief Función de buscar registros por fecha
*/
void Aplication::buscarRegistroPorFecha()
{
<<<<<<< HEAD
	system("python ./graficos/0_O(n).py");
=======
	
>>>>>>> cb933f12fa8212f6342f295743ff5a298523a44d
	Lista<Registro> lista;
	ValidarDatos validar;
	ArbolBinario<Fecha> arbol;
	Fecha fecha;

	ManejoArchivos::cargarRegistros("registros.txt", lista);
	system("cls");

	Nodo<Registro> *tmp = lista.getPrimero();
	for(int i = 0; i < lista.size(); i++){
		if (tmp->getValor().getEstado() == "Salida")
		{
			arbol.insertarNodo(tmp->getValor().getSalida());
		}
		
		tmp = tmp->getSiguiente();
	}

	std::cout << "Ingrese una fecha: " << std::endl;
	fecha.validarFecha(fecha);

	system("cls");

	NodoArbol<Fecha> *fechaA = arbol.buscarNodo(fecha);

	if (fechaA)
	{
		Nodo<Registro> *tmp = lista.getPrimero();
		std::cout << "Los registros del " << fecha.getDia() << 
					"/" << fecha.getMes() <<
					"/" << fecha.getAnio() << " son: " << std::endl;
		for(int i = 0; i < lista.size(); i++){
			if (fechaA->getDato() == tmp->getValor().getSalida())
			{
				tmp->getValor().toString();
			}
			tmp = tmp->getSiguiente();
		}
		
	} else {
		std::cout << "No se encontro registro para " << fecha.getDia() << 
					"/" << fecha.getMes() <<
					"/" << fecha.getAnio() << std::endl;
	}

	system("python ./0_O(n).py");

}

/**
*@brief Función de buscar registros por cedula
*/
void Aplication::buscarRegistrosPorCedula(){
	
<<<<<<< HEAD
	system("python ./graficos/0_O(n).py");
=======
	
>>>>>>> cb933f12fa8212f6342f295743ff5a298523a44d
	Lista<Registro> lista;
	ValidarDatos validar;
	std::string cedula;
	ArbolBinario<int> arbol;

	ManejoArchivos::cargarRegistros("registros.txt", lista);
	system("cls");

	Nodo<Registro> *tmp = lista.getPrimero();
	for(int i = 0; i < lista.size(); i++){
		arbol.insertarNodo(std::atoi(tmp->getValor().getCedula().c_str()));
		tmp = tmp->getSiguiente();
	}

	std::cout << "Ingrese una cedula: " << std::endl;
	cedula = validar.ingresarCedulaValida();

	system("cls");

	NodoArbol<int> *cedA = arbol.buscarNodo(std::atoi(cedula.c_str()));

	if (cedA)
	{
		Nodo<Registro> *tmp = lista.getPrimero();
		std::cout << "Los registros de " << tmp->getValor().getCedula() << " son:" << std::endl;
		for(int i = 0; i < lista.size(); i++){
			if (cedA->getDato() == std::atoi(tmp->getValor().getCedula().c_str()))
			{
				tmp->getValor().toString();
			}
			tmp = tmp->getSiguiente();
		}
		
	} else {
		std::cout << "No se encontro registro para " << cedula << std::endl;
	}
	system("python ./0_O(n).py");
}

/**
*@brief Función de menú de extras 
*/
void Aplication::extras(){
	Menu menu("Extras");
	menu.add(MenuItem("Regresar",std::bind(&Aplication::mainMenu,this)));
	menu.add(MenuItem("BACKUP", std::bind(&Aplication::backup,this)));
	menu.add(MenuItem("Imprimir imagen en consola",std::bind(&Aplication::imprimirEnConsola,this)));
	menu.add(MenuItem("Guardar en pdf", std::bind(&Aplication::guardarEnPdf,this)));
	menu.add(MenuItem("Ayuda", std::bind(&Aplication::ayuda,this)));
	menu.add(MenuItem("Salir", std::bind(&Aplication::salir,this)));
	menu.run();
}

void generarPdf(std::string nombreArchivoTxt){
	system("cls");
	
    std::fstream reporte;
	std::ostringstream out;
	PDF archivoPdf;
	std::string titulo;
	std::string palabraActual;
	std::string nombreArchivoPdf;
	std::string nombreArchivo;
	string mensajeDeError;
	int maxLineasPorPagina = 40;  // Número máximo de líneas por página
	int lineas = 0;  // Contador de líneas en la página actual
	int contador = 1;
	nombreArchivo = (nombreArchivoTxt == "personas.txt") ? "PERSONAS" : "REGISTROS";
	out << nombreArchivo<<".pdf";
	nombreArchivoPdf = out.str();

	archivoPdf.setFont(PDF::COURIER_BOLD, 12);
	
	titulo = (nombreArchivoTxt == "personas.txt") ? "Reporte de Empleados" : "Reporte de Registros";
	
	archivoPdf.showTextXY(titulo,50,762);
	archivoPdf.setFont(PDF::COURIER, 10);
	reporte.open(nombreArchivoTxt, std::ios::in);

    Empleado persona;
	Lista<Empleado> listaPersonas;
	ManejoArchivos::cargarPersonas("personas.txt", listaPersonas);
	Nodo<Empleado> *tmpPersona = listaPersonas.getPrimero();

	Registro registro;
	Lista<Registro> listaRegistros;
	ManejoArchivos::cargarRegistros("registros.txt", listaRegistros);
	Nodo<Registro> *tmpRegistro = listaRegistros.getPrimero();

	if(nombreArchivoTxt == "personas.txt"){
		lineas++;
		for(int i = 0; i < listaPersonas.size(); i++){
			
			archivoPdf.showTextXY("----------------- EMPLEADO -----------------", 50, 747 - 14 * lineas);
			lineas++;
			std::string fechaTemp = std::to_string(tmpPersona->getValor().getFechaNacimiento().getDia()) + "/" + 
									std::to_string(tmpPersona->getValor().getFechaNacimiento().getMes()) + "/" +
									std::to_string(tmpPersona->getValor().getFechaNacimiento().getAnio());
			archivoPdf.showTextXY("CEDULA: " + tmpPersona->getValor().getCedula(), 50, 747 - 14 * lineas);
			lineas++;
			archivoPdf.showTextXY("NOMBRE: " + tmpPersona->getValor().getNombre(), 50, 747 - 14 * lineas);
			lineas++;
			archivoPdf.showTextXY("APELLIDO: " + tmpPersona->getValor().getApellido(), 50, 747 - 14 * lineas);
			lineas++;
			archivoPdf.showTextXY("FECHA DE NACIMIENTO: " + fechaTemp, 50, 747 - 14 * lineas);
			lineas++;
			archivoPdf.showTextXY("SUELDO $: " + std::to_string(tmpPersona->getValor().getSueldo()), 50, 747 - 14 * lineas);
			lineas++;
			tmpPersona = tmpPersona->getSiguiente();
		}
		lineas++;
	} else {
		lineas++;
		for(int i = 0; i < listaRegistros.size(); i++){
			std::string fechaEntrada = std::to_string(tmpRegistro->getValor().getEntrada().getDia()) + "/" + 
									std::to_string(tmpRegistro->getValor().getEntrada().getMes()) + "/" +
									std::to_string(tmpRegistro->getValor().getEntrada().getAnio()) + " - " +
									std::to_string(tmpRegistro->getValor().getEntrada().getHora()) + ":" +
									std::to_string(tmpRegistro->getValor().getEntrada().getMinuto()) + ":" +
									std::to_string(tmpRegistro->getValor().getEntrada().getSegundo());
			std::string fechaSalida = std::to_string(tmpRegistro->getValor().getSalida().getDia()) + "/" +
									std::to_string(tmpRegistro->getValor().getSalida().getMes()) + "/" +
									std::to_string(tmpRegistro->getValor().getSalida().getAnio()) + " - " +
									std::to_string(tmpRegistro->getValor().getSalida().getHora()) + ":" +
									std::to_string(tmpRegistro->getValor().getSalida().getMinuto()) + ":" +
									std::to_string(tmpRegistro->getValor().getSalida().getSegundo());
			archivoPdf.showTextXY("----------------- REGISTRO -----------------", 50, 747 - 14 * lineas);
			lineas++;
			archivoPdf.showTextXY("CEDULA: " + tmpRegistro->getValor().getCedula(), 50, 747 - 14 * lineas);
			lineas++;
			archivoPdf.showTextXY("ENTRADA: " + fechaEntrada, 50, 747 - 14 * lineas);
			lineas++;
			if(tmpRegistro->getValor().getEstado() == "Entrada"){
				archivoPdf.showTextXY("SALIDA: NO SE REGISTRO SALIDA", 50, 747 - 14 * lineas);
			} else {
				archivoPdf.showTextXY("SALIDA: " + fechaSalida, 50, 747 - 14 * lineas);
			}
			lineas++;
			tmpRegistro = tmpRegistro->getSiguiente();

		}
		lineas++;
	}

	std::cout<<"Numero de paginas de " << nombreArchivoPdf << " : " << archivoPdf.getCurrentPage() + 1 <<std::endl;
	reporte.close();
	
	mensajeDeError = "Lo sentimos ha ocurrido un error...";
	if(!archivoPdf.writeToFile(nombreArchivoPdf, mensajeDeError))
	{
		std::cout << mensajeDeError << std::endl;
	}
	else
	{
		std::cout << "(Se ha creado el PDF)" << std::endl;
	}
	system("python ./0_O(n).py");
}

void Aplication::guardarEnPdf(){
	system("cls");
	generarPdf("personas.txt");
	generarPdf("registros.txt");
	system("python ./0_O(1).py");	
}
void Aplication::ayuda(){
	system("cls");
	Menu menu("Extras");
	menu.add(MenuItem("Regresar",std::bind(&Aplication::mainMenu,this)));
	menu.add(MenuItem("BACKUP", std::bind(&Aplication::backup,this)));
	menu.add(MenuItem("Imprimir imagen en consola",std::bind(&Aplication::imprimirEnConsola,this)));
	menu.add(MenuItem("Guardar en pdf", std::bind(&Aplication::guardarEnPdf,this)));
	menu.add(MenuItem("Ayuda", std::bind(&Aplication::ayuda,this)));
	menu.add(MenuItem("Salir", std::bind(&Aplication::salir,this)));
	
	system(".\\helper.chm");
	system("python ./0_O(1).py");
	menu.run();	
}

/**
*@brief Función de menú principal
*/
void Aplication::mainMenu(){
	system("cls");
	run();
}

/**
*@brief Función de menú de backup
*/
void Aplication::backup(){
	Menu menu("Backup");
	menu.add(MenuItem("Regresar",std::bind(&Aplication::extras,this)));
	menu.add(MenuItem("Generar Backup", std::bind(&Aplication::generarBackup,this)));
	menu.add(MenuItem("Restaurar Backup",std::bind(&Aplication::restaurarBackup,this)));
	menu.add(MenuItem("Salir", std::bind(&Aplication::salir,this)));
	menu.run();
}

/**
*@brief Función de restaurar backup
*/
void Aplication::restaurarBackup(){
	system("cls");
	
	std::string directorio = ".\\backups\\";

	// Retorna void si el directorio no existe
	if (!std::filesystem::exists(directorio)) {
		std::cerr << "El directorio no existe: " << directorio << std::endl;
		return;
	}

	// Mostrar todos los archivos en el directorio
	std::cout << "Archivos en el directorio: " << std::endl;


	for (const auto& entry : std::filesystem::directory_iterator(directorio))
		std::cout << entry.path() << std::endl;

	std::cout << "Ingrese el nombre de la carpeta a restaurar: " << std::endl;
	std::string fecha;
	std::cin >> fecha;

	std::string directorioP = directorio + fecha + "\\personas.txt";
	std::string directorioR = directorio + fecha + "\\registros.txt";

	Backup::copiarArchivo(directorioP, "personas.txt");
	Backup::copiarArchivo(directorioR, "registros.txt");
	system("python ./0_O(1).py");

}

/**
*@brief Función de generar backup
*/
void Aplication::generarBackup(){
	system("cls");

	Fecha fechaActual = Fecha::getFechaActual(fechaActual);
	std::string fa = std::to_string(fechaActual.getAnio())
					.append(std::to_string(fechaActual.getMes()))
					.append(std::to_string(fechaActual.getDia()))
					.append(std::to_string(fechaActual.getHora()))
					.append(std::to_string(fechaActual.getMinuto()))
					.append(std::to_string(fechaActual.getSegundo()));

	std::string carpeta = ".\\backups\\";
	std::string directorioP = carpeta + fa;
	std::string directorioR = carpeta + fa;

    if (!std::filesystem::exists(directorioP)) {
        if (!std::filesystem::create_directories(directorioP)) {
            std::cerr << "Error al crear la carpeta de destino: " << directorioP << std::endl;
            return;
        }
    }

	Backup::copiarArchivo("personas.txt", directorioP + "\\personas.txt");
	Backup::copiarArchivo("registros.txt", directorioR + "\\registros.txt");
	system("python ./0_O(1).py");

}

/**
*@brief Función de imprimir imagen en consola
*/
void Aplication::imprimirEnConsola(){
	system("cls");
	Imagen imagen("image.bmp");
	imagen.imprimirImagenEnConsola();
	system("python ./0_O(1).py");
}

/**
*@brief  Función de salir del programa
*/
void Aplication::salir()
{
	system("cls");
	exit(0);
}
