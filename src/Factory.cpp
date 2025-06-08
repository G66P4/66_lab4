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

IControladorFechaActual* Factory::getControladorFechaActual(){
    return ControladorFechaActual::getInstance();
}

IControladorUsuario* Factory::getIControladorUsuario(){
    if (this->controladorUsuario == NULL)
        this->controladorUsuario = new controladorUsuario();
    return this->controladorUsuario;
}

IControladorInmueble* Factory::getControladorInmueble(){
    if (this->controladorInmueble == NULL)
        this->controladorInmueble = new controladorInmueble();
    return this->controladorInmueble;
}

IControladorPublicacion* Factory::getControladorPublicacion(){
    if (this->controladorPublicacion == NULL)
        this->controladorPublicaion = new controladorPublicacion();
    return this->cotroladorPublicacion;
}