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
    std::set<AdministraPropiedad*>& administradores = this->getAdministracion();
    std::set<AdministraPropiedad*>::iterator it = administradores.begin();
    while(it!=administradores.end()){
        AdministraPropiedad* adminProp = *it;
        Inmobiliaria* mob = adminProp->getInmobiliaria();
        adminProp->eliminarPublicaciones(); 
        mob->eliminarLinkAdmProp(codigoInmueble);

        std::list<Propietario*> listapropietarios=ManejadorUsuario::getInstance()->getPropietarios();
        std::list<Propietario*>::iterator itprop = listapropietarios.begin();
        bool propietarioEncontrado = false;
        Propietario* propietario =NULL;
        while(itprop != listapropietarios.end() && !propietarioEncontrado){
            propietario = *itprop;
            propietarioEncontrado=propietario->esPropietario(codigo);
            ++itprop;
        }
        propietario->removerLinkPropiedad(codigoInmueble);
        std::set<AdministraPropiedad*>::iterator eliminar = it;
        it++; 
        administradores.erase(eliminar); 
    }
 
}

bool Inmueble::esAdministrado(Inmobiliaria* inmobiliaria) {
    std::set<AdministraPropiedad*>& ap = this->getAdministracion();
    std::set<AdministraPropiedad*>::iterator it;
    for (it = ap.begin(); it != ap.end(); ++it) {
        if ((*it)->inmobiliariaAsociada(inmobiliaria)) {
            return true;
        }
    }
    return false;
}

void Inmueble::asociarAdministracion(AdministraPropiedad* adminProp) {
    administracion.insert(adminProp);
}