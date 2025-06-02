#include "../include/DTApartamento.h"

DTApartamento::DTApartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes)
    : DTInmueble(codigo, direccion, numeroPuerta, superficie, anioConstruccion) {
    this->piso = piso;
    this->tieneAscensor = tieneAscensor;
    this->gastosComunes = gastosComunes;
}

int DTApartamento::getPiso() {
    return piso;
}

bool DTApartamento::getTieneAscensor() {
    return tieneAscensor;
}

float DTApartamento::getGastosComunes() {
    return gastosComunes;
}

DTApartamento::~DTApartamento(){

}