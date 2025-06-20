#include "../include/Propietario.h"
#include "../include/AdministraPropiedad.h"


Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono):Usuario(nickname, contrasena, nombre, email){
    this->cuentaBancaria = cuentaBancaria;
    this->telefono = telefono;
};

std::string Propietario::getCuentaBancaria(){
    return cuentaBancaria;
};

std::string Propietario::getTelefono(){
    return telefono;
};

std::list<Inmueble*> Propietario::getInmueblesDueno(){
    return inmueblesDueno;
};

void Propietario::asociarInmueble(Inmueble* inmueble){
    inmueblesDueno.push_back(inmueble);
};

std::set<DTInmuebleListado*> Propietario::getInmueblesNoAdmin(Inmobiliaria* inm){
    std::string nicknameInmobiliaria=inm->getNickname();
    std::set<DTInmuebleListado*> inmueblesNoAdminSet;
    std::map<int,Inmueble*> inmuebles = ManejadorInmueble::getInstance()->getInmuebles();

    for(std::map<int, Inmueble*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it) {
        Inmueble* inmueble = it->second;
            // Verificamos si el inmueble es propiedad del propietario actual
            if(!esPropietario(inmueble->getCodigo())) {
                continue; // Si no es propiedad, saltamos al siguiente inmueble
            }
        bool administrado=inmueble->esAdministrado(inm); 
            if(!administrado) {
                // Si no está administrado, lo agregamos al set
                DTInmuebleListado* dtInmueble = new DTInmuebleListado(inmueble->getCodigo(), inmueble->getDireccion(), this->getNickname());
                inmueblesNoAdminSet.insert(dtInmueble);
            }
        }
    
    return inmueblesNoAdminSet;
        
};

bool Propietario::esPropietario(int codigoInmueble){
    for(Inmueble* inmueble : inmueblesDueno){
        if(inmueble->getCodigo() == codigoInmueble){
            return true;
        }
    }
    return false;
};

void Propietario::removerLinkPropiedad(int codigoInmueble){
    for(auto it = inmueblesDueno.begin(); it != inmueblesDueno.end(); ++it){
        if((*it)->getCodigo() == codigoInmueble){
            inmueblesDueno.erase(it);
            break;
        }
    }
};

void Propietario::Notificar(DTNotificacion* notificacion){
    notificaciones.push_back(notificacion);
    
};

DTUsuario* Propietario::getPropietarioData(){
    return new DTUsuario(this->getNickname(), this->getNombre());
};

std::list<DTNotificacion*> Propietario::consultarNotificaciones()
{
    std::list<DTNotificacion*> ultimasNotificaciones = this->notificaciones;
    notificaciones.clear();
    return ultimasNotificaciones;
};

std::string Propietario::getNicknameO() {
    return getNickname();
};

void Propietario::agregarSuscripcion(Inmobiliaria* inmobiliaria) {
    if (inmobiliaria != NULL) {
        inmobiliariasSuscritas.push_back(inmobiliaria);
    }
};

void Propietario::eliminarSuscripcion(Inmobiliaria* inmobiliaria) {
    if(inmobiliaria != NULL) {
        inmobiliariasSuscritas.remove(inmobiliaria);
    }
};

Propietario::~Propietario(){ 

    notificaciones.clear();
}; 