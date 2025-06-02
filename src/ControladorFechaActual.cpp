#include "../include/ControladorFechaActual.h"
#include <cstddef>

ControladorFechaActual* ControladorFechaActual::instance = NULL;

ControladorFechaActual::ControladorFechaActual() {
    fechaActual = new DTFecha(1,1,1900);
}

ControladorFechaActual* ControladorFechaActual::getInstance() {
    if (instance == NULL) {
        instance = new ControladorFechaActual();
    }
    return instance;
}

DTFecha* ControladorFechaActual::getFechaActual(){
    return new DTFecha(fechaActual);
}
void ControladorFechaActual::setNewFechaActual(int dia, int mes, int anio){
    delete fechaActual;
    fechaActual = new DTFecha(dia, mes, anio);
}

ControladorFechaActual::~ControladorFechaActual(){
    delete fechaActual;
    instance = NULL;
}