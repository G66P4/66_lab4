#include "../include/DTInmuebleListado.h"

DTInmuebleListado::DTInmuebleListado(int codigo, std::string direccion, std::string propietario) {
    this->codigo = codigo;
    this->direccion = direccion;
    this->propietario = propietario;
}

int DTInmuebleListado::getCodigo() {
    return codigo;
}

std::string DTInmuebleListado::getDireccion() {
    return direccion;
}

std::string DTInmuebleListado::getPropietario() {
    return propietario;
}