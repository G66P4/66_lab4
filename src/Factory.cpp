#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include <cstddef>

Factory* Factory::instance = NULL;

Factory::Factory() {
    controladorUsuario = NULL;
    controladorInmueble = NULL;
    controladorPublicacion = NULL;
}

Factory* Factory::getInstance() {
    if (instance == NULL) {
        instance = new Factory();
    }
    return instance;
}

void Factory::liberarInstancia() {
    if (instance != NULL) {
        delete instance;
        instance = NULL;
    }
}

IControladorFechaActual* Factory::getIControladorFechaActual(){
    return ControladorFechaActual::getInstance();
}

IControladorUsuario* Factory::getIControladorUsuario(){
    return ControladorUsuario::getInstance();
}

IControladorInmueble* Factory::getIControladorInmueble(){
    return ControladorInmueble::getInstance();
}

IControladorPublicacion* Factory::getIControladorPublicacion(){
    return ControladorPublicacion::getInstance();
}

Factory::~Factory() {}