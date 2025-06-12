#include "../include/Inmueble.h"
#include "../include/ControladorUsuario.h"
#include "../include/ControladorInmueble.h"
#include "../include/AdministraPropiedad.h"
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


DTInmuebleAdministrado* Inmueble::getinfoInmueble(Inmobiliaria* inm){
    for (std::set<AdministraPropiedad*>::iterator it = administracion.begin(); it != administracion.end(); ++it) {
        AdministraPropiedad* administrador = *it;
        if(administrador->getInmobiliaria()==inm){
            DTInmuebleAdministrado* dtInmueble = new DTInmuebleAdministrado(codigo,direccion, administrador->getFecha());
            return dtInmueble;
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

Inmueble::~Inmueble(){
    // Eliminar los enlaces de administración del inmueble
    eliminarLinksInmueble(codigo);
    
    // Limpiar el set de administraciones
    administracion.clear();
}