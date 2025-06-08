#include "../include/Inmueble.h"
#include <stdexcept> 
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

std::set<AdministraPropiedad*>& Inmueble::getAdministracion(){
    return administracion;
}

//tuve que agregar la inmobiliaria como parametro porque si no ni idea como hacia
DTInmuebleAdministrado Inmueble::getinfoInmueble(Inmobiliaria* inm){
    for (std::set<AdministraPropiedad*>::iterator it = administracion.begin(); it != administracion.end(); ++it) {
        AdministraPropiedad* administrador = *it;
        if(administrador->getInmobiliaria()==inm){
            return DTInmuebleAdministrado(codigo,direccion,administrador->getFecha());
        }
    }
    throw std::runtime_error("Inmobiliaria no encontrada en la administración del inmueble");
}

void Inmueble::eliminarLinksInmueble(int codigoInmueble){
    std::set<AdministraPropiedad*>& administrador = this->getAdministracion();
    std::set<AdministraPropiedad*>::iterator it = administrador.begin();
    while(it!=administrador.end()){
        AdministraPropiedad* adminProp = *it;
        Inmobiliaria* mob = adminProp->getInmobiliaria();

        //std::string nickMob=getter nickname inmobiliaria y creo que no es necesario
        //mob->eliminarLinkAdmProp(codigoInmueble);
        //removerLinkPropiedad(codigoInmueble);
        std::set<AdministraPropiedad*>::iterator eliminar = it;
        it++; 
        administrador.erase(eliminar); 
    }
 
}
