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

void Propietario::asociarInmueble(Inmueble* inmueble){
    inmueblesDueno.push_back(inmueble);
};

std::set<DTInmuebleListado*> Propietario::listarInmueblesNoAdministrados(std::string nicknameInmobiliaria){
    std::set<DTInmuebleListado*> inmueblesNoAdminSet;
    std::map<int,Inmueble*> inmuebles = ManejadorInmueble::getInstance()->getInmuebles();

    for(std::map<int, Inmueble*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it) {
        Inmueble* inmueble = it->second;
        std::set<AdministraPropiedad*>& administracion = inmueble->getAdministracion();
        for(std::set<AdministraPropiedad*>::iterator itAdmin = administracion.begin(); itAdmin != administracion.end(); ++itAdmin) {
            AdministraPropiedad* adminProp = *itAdmin;
            if(adminProp->getInmobiliaria()->getNickname() == nicknameInmobiliaria) {
                // Si el inmueble ya está administrado por la inmobiliaria, no lo agregamos
                break;
            } else {
                // Si no está administrado, lo agregamos al set
                DTInmuebleListado* dtInmueble = new DTInmuebleListado(inmueble->getCodigo(), inmueble->getDireccion(), this->getNickname());
                inmueblesNoAdminSet.insert(dtInmueble);
            }
        }
    }
    return inmueblesNoAdminSet;
        
};

Propietario::~Propietario(){};