#include "../include/DTInmuebleAdministrado.h"

DTInmuebleAdministrado::DTInmuebleAdministrado(int codigo, std::string direccion, DTFecha* fechaComienzo) {
    this->codigo = codigo;
    this->direccion = direccion;
    this->fechaComienzo = new DTFecha(fechaComienzo);
}

int DTInmuebleAdministrado::getCodigo() {
    return codigo;
}

std::string DTInmuebleAdministrado::getDireccion() {
    return direccion;
}

DTFecha* DTInmuebleAdministrado::getFechaComienzo() {
    return fechaComienzo;
}

DTInmuebleAdministrado::~DTInmuebleAdministrado(){
    delete fechaComienzo;
}