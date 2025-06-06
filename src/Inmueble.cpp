#include "../include/Inmueble.h"

Inmueble::Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion){
    this->codigo=codigo;
    this->direccion=direccion;
    this->numeroPuerta=numeroPuerta;
    this->superficie=superficie;
    this->anoConstruccion=anoConstruccion;
}

int Inmueble::getCodigo(){
    return codigo;
}

std::string Inmueble::getDireccion(){
    return direccion;
}

int Inmueble::getNumeroPuerta(){
    return numeroPuerta;
}

int Inmueble::getSuperficie(){
    return superficie;
}

int Inmueble::getAnoConstruccion(){
    return anoConstruccion;
}