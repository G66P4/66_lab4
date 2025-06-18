#include "../include/DTPublicacion.h"

    #
DTPublicacion::DTPublicacion(int codigo, int codigoinm, DTFecha* fecha, std::string texto, std::string precio, std::string inmobiliaria) {
    this->codigo = codigo;
    this->codigoinmueble = codigoinm;
    this->fecha = fecha;
    this->texto = texto;
    this->precio = precio;
    this->inmobiliaria = inmobiliaria;
}


bool DTPublicacion::operator<(DTPublicacion* publicacion) const {
    return this->fecha < publicacion->getFecha(); 
}

int DTPublicacion::getCodigo() {
    return codigo;
}

int DTPublicacion::getCodigoinmueble() {
    return codigoinmueble;
}

DTFecha* DTPublicacion::getFecha() {
    return fecha;
}

std::string DTPublicacion::getTexto() {
    return texto;
}

std::string DTPublicacion::getPrecio() {
    return precio;
}

std::string DTPublicacion::get_Inmobiliaria() {
    return inmobiliaria;
}

DTPublicacion::~DTPublicacion(){
    delete fecha;
}