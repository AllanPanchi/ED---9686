#include "Singleton.h"

Singleton* Singleton::instance = nullptr;

////////////////////////////////////////////////////////////////////////
// Name:       Singleton::Singleton()
// Purpose:    Implementation of Singleton::Singleton()
// Return:     
////////////////////////////////////////////////////////////////////////

Singleton::Singleton() {}

////////////////////////////////////////////////////////////////////////
// Name:       Singleton::getInstance()
// Purpose:    Implementation of Singleton::getInstance()
// Return:     Singleton*
////////////////////////////////////////////////////////////////////////

Singleton* Singleton::getInstance() {
    if (instance == nullptr) {
        instance = new Singleton();
    }
    return instance;
}

////////////////////////////////////////////////////////////////////////
// Name:       Singleton::getRegistros()
// Purpose:    Implementation of Singleton::getRegistros()
// Return:     ListaCircularDoble<RegistroEntradaSalida>&
////////////////////////////////////////////////////////////////////////

ListaSimple<Pieza>& Singleton::getPiezas() {
    return piezas;
}

