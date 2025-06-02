#include "../include/DTCasa.h"

DTCasa::DTCasa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, bool esPH, TipoTecho techo)
    : DTInmueble(codigo, direccion, numeroPuerta, superficie, anioConstruccion) {
    this->esPH = esPH;
    this->techo = techo;
}

bool DTCasa::getEsPH() {
    return esPH;
}

TipoTecho DTCasa::getTecho() {
    return techo;
}

DTCasa::~DTCasa(){
    
}