#include "../include/Publicacion.h"
#include "../include/DTPublicacion.h"
#include "../include/DTFecha.h"
#include "../include/DTUsuario.h"
#include "../include/Inmobiliaria.h"
#include "../include/AdministraPropiedad.h"

#include <string>
#include <iostream>
using namespace std;

Publicacion::Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, const string& texto, float precio, bool activa){
    this->codigo = codigo;

    this->fecha = fecha;
    this->tipo = tipo;
    this->texto = texto;
    this->precio = precio;
    this->activa = activa;

    // Inicializar adminProp a NULL, se asignará más tarde
    this->adminProp = NULL;
}
Publicacion::~Publicacion() {}

bool Publicacion::cumple(TipoPublicacion tipoPub, float precioMinimo, float precioMaximo, TipoInmueble tipoInm)  {
    if(tipoInm==Todos){
        return (tipoPub == tipo && precio >= precioMinimo && precio <= precioMaximo);
    } else {
        return (tipoPub == tipo && precio >= precioMinimo && precio <= precioMaximo && adminProp->getInmueble()->consultarTipo() == tipoInm);
    }
}



DTPublicacion* Publicacion::crearDTPublicacion() const {
    DTUsuario* dtInmo = adminProp->getInmobiliaria()->getInmobiliariaData();

    std::string inmobiliaria = dtInmo->getNickname(); // o dtInmo.getNombre()
    delete dtInmo;
    DTPublicacion* DTP = new DTPublicacion( codigo, new DTFecha(fecha), texto, std::to_string(precio), inmobiliaria);
    return DTP;
}
//getters
int Publicacion::getCodigo() const {
    return codigo;
}

DTFecha* Publicacion::getFecha() const {
    return fecha;
}

TipoPublicacion Publicacion::getTipo() const {
    return tipo;
}

string Publicacion::getTexto() const {
    return texto;
}

float Publicacion::getPrecio() const {
    return precio;
}

AdministraPropiedad* Publicacion::getAdminProp() {
    return adminProp;
}

bool Publicacion::estaActiva() const {
    return activa;
}

void Publicacion::setAdminProp(AdministraPropiedad* adminProp) {
    this->adminProp = adminProp;
}
//setter
void Publicacion::setActiva(bool activa) {
    this->activa = activa;
}




