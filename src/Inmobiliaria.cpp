#include "../include/Inmobiliaria.h"
#include "../include/AdministraPropiedad.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/DTInmuebleListado.h"
#include "../include/Usuario.h"
#include "../include/Propietario.h"
#include "../include/ManejadorUsuario.h"
#include "../include/Publicacion.h"
#include "../include/Inmueble.h"

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
    DTInmuebleAdministrado* dt = inmueble->getinfoInmueble(this);
    if(dt !=NULL){
        res.insert(dt);
    }
    
}

    return res;
}

std::set<DTInmuebleListado*> Inmobiliaria::listarInmueblesNoAdministrados() {
    std::set<DTInmuebleListado*> resultado;

    ManejadorUsuario* mu = ManejadorUsuario::getInstance();
    std::list<Propietario*> propietarios = mu->getPropietarios();

    for (Propietario* propietario : propietarios) {
        std::list<Inmueble*> inmuebles = propietario->getInmueblesDueno();

        for (Inmueble* inmueble : inmuebles) {
            int codigo = inmueble->getCodigo();

            if (propiedades.find(codigo) == propiedades.end()) {
                std::string direccion = inmueble->getDireccion();
                std::string nombrePropietario = propietario->getPropietarioData()->getNombre();

                DTInmuebleListado* listadoDto = new DTInmuebleListado(codigo, direccion, nombrePropietario);
                resultado.insert(listadoDto);
            }
        }
    }

    return resultado;
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
    return NULL;//esta funcion nunca debería retornar NULL, ya que se supone que el inmueble está administrado por la inmobiliaria
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

bool Inmobiliaria::esSuscriptor(std::string nickname){
    for (IObserver* usuario : suscriptores) {
        if (usuario->getNicknameO() == nickname) {
            return true; // El usuario es un suscriptor
        }
    }
    return false; // El usuario no es un suscriptor
}

void Inmobiliaria::agregarSuscripcion(IObserver* usuario) {
    suscriptores.insert(usuario);
}

void Inmobiliaria::eliminarSuscripcion(IObserver* usuario) {
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

    for (IObserver* usuario : suscriptores) {
        if (usuario != nullptr) {
            usuario->Notificar(noti);
        }
    }

}

Inmobiliaria::~Inmobiliaria() {
    std::map<int, AdministraPropiedad*>::iterator it;
    for (it = propiedades.begin(); it != propiedades.end(); ++it) {
        AdministraPropiedad* admin = it->second;

        
        admin->setInmueble(NULL);
        admin->setInmobiliaria(NULL);

        delete admin;
    }

    propiedades.clear();
    representa.clear();     
    suscriptores.clear();   
}

void Inmobiliaria::altaAdministracionPropiedad(Inmueble* inmueble, DTFecha* fechaComienzo) {
    int codigo = inmueble->getCodigo();

    if (propiedades.find(codigo) != propiedades.end()) {
        throw std::runtime_error("El inmueble ya está siendo administrado por esta inmobiliaria");
    }

    AdministraPropiedad* nuevaAdmin = new AdministraPropiedad(fechaComienzo);

    // setear la inmobiliaria y el inmueble porque el constructor no lo hace
    nuevaAdmin->setInmobiliaria(this);
    nuevaAdmin->setInmueble(inmueble);
    inmueble->asociarAdministracion(nuevaAdmin);
    propiedades[codigo] = nuevaAdmin;

    inmueble->asociarAdministracion(nuevaAdmin);
}