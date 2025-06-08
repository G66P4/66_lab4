#include "../include/ControladorInmueble.h"

ControladorInmueble* ControladorInmueble::instance = NULL;

ControladorInmueble::ControladorInmueble() {}

ControladorInmueble* ControladorInmueble::getInstance() {
    if (instance == NULL) {
        instance = new ControladorInmueble();
    }
    return instance;
}

void ControladorInmueble::eliminarInmueble(int codigoInmueble){
    if(ManejadorInmueble::getInstance()->existeInmueble(codigoInmueble)){
        Inmueble* inm = ManejadorInmueble::getInstance()->findInmueble(codigoInmueble);
        inm->eliminarLinksINmueble(codigoInmueble);
        ManejadorInmueble::getInstance()->eliminarInmueble(codigoInmueble);
        delete inm;
    }
}