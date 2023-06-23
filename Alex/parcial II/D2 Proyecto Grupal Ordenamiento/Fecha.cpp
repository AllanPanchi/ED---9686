#include "Fecha.h"
#include <ctime>
#include <locale>
#include "ValDatos.h"

Fecha::Fecha()
{
   	// Establece la configuración regional en español
    setlocale(LC_ALL, "es_ES.UTF-8");

    // Obtiene el tiempo actual del sistema
    std::time_t tiempoActual = std::time(nullptr);

    // Convierte el tiempo en una estructura tm
    std::tm* tiempoLocal = std::localtime(&tiempoActual);

    // Obtiene los componentes de fecha y hora
	this->dia = tiempoLocal->tm_mday;
	this->mes = tiempoLocal->tm_mon+1;
    this->anio = tiempoLocal->tm_year + 1900;
    this->hora = tiempoLocal->tm_hour;
    this->minuto = tiempoLocal->tm_min;
    this->segundo = tiempoLocal->tm_sec;
}

Fecha::~Fecha()
{
}

Fecha::Fecha(int dia, int mes, int anio, int hora, int minuto, int segundo)
{
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
}

int Fecha::getDia()
{
    return this->dia;
}

void Fecha::setDia(int dia)
{
    this->dia = dia;
}

int Fecha::getMes()
{
    return this->mes;
}

void Fecha::setMes(int mes)
{
    this->mes = mes;
}

int Fecha::getAnio()
{
    return this->anio;
}

void Fecha::setAnio(int anio)
{
    this->anio = anio;
}

int Fecha::getHora()
{
    return this->hora;
}

void Fecha::setHora(int hora)
{
    this->hora = hora;
}

int Fecha::getMinuto()
{
    return this->minuto;
}

void Fecha::setMinuto(int minuto)
{
    this->minuto = minuto;
}

int Fecha::getSegundo()
{
    return this->segundo;
}

void Fecha::setSegundo(int segundo)
{
    this->segundo = segundo;
}

Fecha Fecha::getFechaActual(Fecha fecha){
    time_t tiempoActual = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoActual);

        // Asignar los componentes de la fecha y hora actual a los miembros de la clase
    fecha.setDia(tiempoLocal->tm_mday);
    fecha.setMes(tiempoLocal->tm_mon + 1);
    fecha.setAnio(tiempoLocal->tm_year + 1900);
    fecha.setHora(tiempoLocal->tm_hour);
    fecha.setMinuto(tiempoLocal->tm_min);
    fecha.setSegundo(tiempoLocal->tm_sec);
    
    return fecha;
}

bool Fecha::esAnioBisiesto(int anio) {
        return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

Fecha Fecha::validarFecha(Fecha fecha) {
        // Validar año
        
        while (fecha.getAnio()<1956 || fecha.getAnio() > 2006) {
            std::cout << "Anio invalido." << std::endl;
            fecha.setAnio(ValidarDatos::validarEntero());
        }

        // Validar mes
        while (fecha.getMes() < 0  || fecha.getMes() > 13) {
            std::cout << "Mes invalido." << std::endl;
            fecha.setMes(ValidarDatos::validarEntero());
        }

        // Validar día
        int diasEnMes = 0;
        if (fecha.getMes() == 2) {
            diasEnMes = esAnioBisiesto(fecha.getAnio()) ? 29 : 28;
        } else if (fecha.getMes() == 4 || fecha.getMes() == 6 || fecha.getMes() == 9 || fecha.getMes() == 11) {
            diasEnMes = 30;
        } else {
            diasEnMes = 31;
        }

        while (fecha.getDia() < 1 || fecha.getDia() > diasEnMes) {
            std::cout << "Dia inva  lido." << std::endl;
            fecha.setDia(ValidarDatos::validarEntero());
        }

        return fecha;
}

   

bool Fecha::operator<(Fecha fecha)
{
    if (this->anio < fecha.anio)
    {
        return true;
    }
    else if (this->anio == fecha.anio)
    {
        if (this->mes < fecha.mes)
        {
            return true;
        }
        else if (this->mes == fecha.mes)
        {
            if (this->dia < fecha.dia)
            {
                return true;
            }
            else if (this->dia == fecha.dia)
            {
                if (this->hora < fecha.hora)
                {
                    return true;
                }
                else if (this->hora == fecha.hora)
                {
                    if (this->minuto < fecha.minuto)
                    {
                        return true;
                    }
                    else if (this->minuto == fecha.minuto)
                    {
                        if (this->segundo < fecha.segundo)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Fecha::operator>(Fecha fecha)
{
    if (this->anio > fecha.anio)
    {
        return true;
    }
    else if (this->anio == fecha.anio)
    {
        if (this->mes > fecha.mes)
        {
            return true;
        }
        else if (this->mes == fecha.mes)
        {
            if (this->dia > fecha.dia)
            {
                return true;
            }
            else if (this->dia == fecha.dia)
            {
                if (this->hora > fecha.hora)
                {
                    return true;
                }
                else if (this->hora == fecha.hora)
                {
                    if (this->minuto > fecha.minuto)
                    {
                        return true;
                    }
                    else if (this->minuto == fecha.minuto)
                    {
                        if (this->segundo > fecha.segundo)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Fecha::operator==(Fecha fecha)
{
    if (this->anio == fecha.anio && this->mes == fecha.mes && this->dia == fecha.dia && this->hora == fecha.hora && this->minuto == fecha.minuto && this->segundo == fecha.segundo)
    {
        return true;
    }
    return false;
}

bool Fecha::operator!=(Fecha fecha)
{
    if (this->anio != fecha.anio || this->mes != fecha.mes || this->dia != fecha.dia || this->hora != fecha.hora || this->minuto != fecha.minuto || this->segundo != fecha.segundo)
    {
        return true;
    }
    return false;
}

bool Fecha::operator<=(Fecha fecha)
{
    if (this->anio < fecha.anio)
    {
        return true;
    }
    else if (this->anio == fecha.anio)
    {
        if (this->mes < fecha.mes)
        {
            return true;
        }
        else if (this->mes == fecha.mes)
        {
            if (this->dia < fecha.dia)
            {
                return true;
            }
            else if (this->dia == fecha.dia)
            {
                if (this->hora < fecha.hora)
                {
                    return true;
                }
                else if (this->hora == fecha.hora)
                {
                    if (this->minuto < fecha.minuto)
                    {
                        return true;
                    }
                    else if (this->minuto == fecha.minuto)
                    {
                        if (this->segundo <= fecha.segundo)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Fecha::operator>=(Fecha fecha)
{
    if (this->anio > fecha.anio)
    {
        return true;
    }
    else if (this->anio == fecha.anio)
    {
        if (this->mes > fecha.mes)
        {
            return true;
        }
        else if (this->mes == fecha.mes)
        {
            if (this->dia > fecha.dia)
            {
                return true;
            }
            else if (this->dia == fecha.dia)
            {
                if (this->hora > fecha.hora)
                {
                    return true;
                }
                else if (this->hora == fecha.hora)
                {
                    if (this->minuto > fecha.minuto)
                    {
                        return true;
                    }
                    else if (this->minuto == fecha.minuto)
                    {
                        if (this->segundo >= fecha.segundo)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Fecha& fecha)
{
    os << fecha.dia << " " << fecha.mes << " " << fecha.anio << " " << fecha.hora << " " << fecha.minuto << " " << fecha.segundo;
    return os;
}

std::istream& operator>>(std::istream& is, Fecha& fecha)
{
   
      
    std::cout << "Ingrese el anio: ";
    is >> fecha.anio;
    std::cout << "Ingrese el mes: ";
    is >> fecha.mes;
    std::cout << "Ingrese el dia: ";
    is >> fecha.dia;
   
    
    return is;
}




// Path: ED---9686\Alejo\P2\D2 Proyecto Grupal Ordenamiento\main.cpp