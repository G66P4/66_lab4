#include "../include/Inmobiliaria.h"
#include "../include/AdministraPropiedad.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/DTInmuebleListado.h"
#include "../include/Inmueble.h"
#include "../include/Usuario.h"
#include "../include/Propietario.h"
#include "../include/ManejadorUsuario.h"
#include "../include/Publicacion.h"


Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email,
                           std::string direccion, std::string url, std::string telefono)
    : Usuario(nickname, contrasena, nombre, email) 
{
    this->direccion = direccion;
    this->url = url;
    this->telefono = telefono;
    this->propiedades = {};
}
// Getters
std::string Inmobiliaria::getDireccion() const {
    return direccion;
}

std::string Inmobiliaria::getUrl() const {
    return url;
}

std::string Inmobiliaria::getTelefono() const {
    return telefono;
}

std::set<DTInmuebleAdministrado*> Inmobiliaria::obtenerInmuebleData() {
    std::set<DTInmuebleAdministrado*> res;
   for (std::map<int, AdministraPropiedad*>::iterator it = propiedades.begin(); it != propiedades.end(); ++it) {
    Inmueble* inmueble = it->second->getInmueble();
    res.insert(inmueble->getinfoInmueble(this));
}

    return res;
}

std::set<DTInmuebleListado*> Inmobiliaria::listarInmueblesNoAdministrados() {
    std::set<DTInmuebleListado*> vacio;
    return vacio;
}

bool Inmobiliaria::agregarInmuebleAdministrado(Inmueble* inmueble) {
    int codigo = inmueble->getCodigo();
    if (propiedades.find(codigo) == propiedades.end()) {
        DTFecha* fecha = DTFecha::obtenerFechaActual();
        AdministraPropiedad* nueva = new AdministraPropiedad(fecha);
        propiedades[codigo] = nueva;
        nueva->setInmueble(inmueble);
        return true;
    }
    return false;
}
AdministraPropiedad* Inmobiliaria::adminPropFind(int codigoInmueble) {
    std::map<int, AdministraPropiedad*>::iterator it = propiedades.find(codigoInmueble);
    if (it != propiedades.end())
        return it->second;
    return NULL;
}

void Inmobiliaria::eliminarLinkAdmProp(int codigoInmueble) {
    std::map<int, AdministraPropiedad*>::iterator it = propiedades.find(codigoInmueble);
    if (it != propiedades.end()) {
        delete it->second;
        propiedades.erase(it);
    }
}

DTUsuario* Inmobiliaria::getInmobiliariaData() {
    return new DTUsuario(getNickname(), getNombre());
}

void Inmobiliaria::representarPropietario(std::string nicknamePropietario) {
    Usuario* usuario = ManejadorUsuario::getInstance()->findUsuario(nicknamePropietario);
    
    if (usuario == NULL || !usuario->esPropietario())
        return; 

    Propietario* propietario = dynamic_cast<Propietario*>(usuario);
    if (propietario == NULL)
        return; 

    for (Propietario* p : representa) {
        if (p == propietario)
            return; // ya está en la lista
    }

    representa.push_back(propietario);
}

void Inmobiliaria::agregarSuscripcion(Usuario* usuario) {
    suscriptores.insert(usuario);
}

void Inmobiliaria::eliminarSuscripcion(Usuario* usuario) {
    suscriptores.erase(usuario);
}

void Inmobiliaria::modificar(Publicacion* pub) {
    DTFecha* fechaActual = DTFecha::obtenerFechaActual();

    DTNotificacion* noti = new DTNotificacion(
        pub->getCodigo(),
        fechaActual,
        pub->getTexto(),
        getNickname(),
        pub->getTipo(),
        pub->getAdminProp()->getInmueble()->consultarTipo()
    );

    for (Usuario* usuario : suscriptores) {
        IObserver* obs = dynamic_cast<IObserver*>(usuario);
        if (obs != nullptr) {
            obs->Notificar(noti);
        }
    }

    delete noti;
}

Inmobiliaria::~Inmobiliaria() {
    std::map<int, AdministraPropiedad*>::iterator it;
    for (it = propiedades.begin(); it != propiedades.end(); ++it) {
        delete it->second;
    }
    propiedades.clear();
}
