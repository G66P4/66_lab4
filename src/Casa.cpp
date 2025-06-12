#include "../include/Casa.h"
#include "../include/TipoTecho.h"

Casa::Casa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo) : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion) {
    this->esPH = esPH;
    this->techo = techo;
}
TipoInmueble Casa::consultarTipo() {
    return TipoInmueble::casa;
}

Casa::~Casa() {}