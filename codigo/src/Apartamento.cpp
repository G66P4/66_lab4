#include "../include/Apartamento.h"
#include <iostream>

using namespace std;

Apartamento::Apartamento(int codigo, std::string direccion, int numeroPuerta, int superficie,
                         int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes)
    : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion),
      piso(piso), tieneAscensor(tieneAscensor), gastosComunes(gastosComunes) {}

// Destructor
Apartamento::~Apartamento() {}

TipoInmueble Apartamento::consultarTipo() {
    return TipoInmueble::apartamento;
}

// Getters
int Apartamento::getPiso() const {
    return piso;
}

bool Apartamento::getTieneAscensor() const {
    return tieneAscensor;
}

float Apartamento::getGastosComunes() const {
    return gastosComunes;
}
