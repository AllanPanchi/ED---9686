#pragma once

#include "ListaCircularDoble.cpp"

class Singleton {

public:
    static Singleton* getInstance();
	/*
    ListaCircularDoble<RegistroEntradaSalida>& getRegistros();
    ListaCircularDoble<Empleado>& getEmpleados();*/
private:
    static Singleton* instance;
    /*ListaCircularDoble<RegistroEntradaSalida> registros;
    ListaCircularDoble<Empleado> empleados;*/
    Singleton();
};

