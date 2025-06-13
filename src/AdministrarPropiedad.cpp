#include "../include/AdministraPropiedad.h"
#include "../include/Inmueble.h"
#include "../include/Casa.h" 
#include "../include/Apartamento.h"
#include "../include/Inmobiliaria.h"
#include "../include/Publicacion.h"
#include "../include/DTFecha.h"
#include "../include/TipoInmueble.h"
#include "../include/TipoPublicacion.h"
// Constructor
AdministraPropiedad::AdministraPropiedad(DTFecha *fecha)
{
    this->fecha = fecha;
    this->inmobiliaria = NULL;
    this->inmueble = NULL;
}

// Destructor
AdministraPropiedad::~AdministraPropiedad()
{
    delete fecha;
    publicaciones.clear(); // no elimina las publiones
}

TipoInmueble AdministraPropiedad::consultarTipoInmueble()
{
    return this->inmueble->consultarTipo();
}

bool AdministraPropiedad::tienePub(DTFecha* fechaActual, TipoPublicacion tipoPublicacion)
{
    std::set<Publicacion*>::iterator it;
    for (it = publicaciones.begin(); it != publicaciones.end(); ++it)
    {
        Publicacion *pub = *it;
        if ( ( (pub->getFecha()) == fechaActual ) && ((pub->getTipo()) == tipoPublicacion) ) 
        {
            return true;    
        }
    }
    return false;
}

void AdministraPropiedad::agregarPub(Publicacion *publicacion)
{
    std::set<Publicacion *>::iterator it;
    for (it = publicaciones.begin(); it != publicaciones.end(); ++it)
    {
        Publicacion *pub = *it;
        if ((pub->getTipo() == publicacion->getTipo()) && (pub->getFecha() < publicacion->getFecha()))
        {
            pub->setActiva(false);
        }
    }
    publicaciones.insert(publicacion);
}

// Getters

DTFecha *AdministraPropiedad::getFecha() const
{
    return fecha;
}

Inmobiliaria *AdministraPropiedad::getInmobiliaria() const
{
    return inmobiliaria;
}

Inmueble *AdministraPropiedad::getInmueble() const
{
    return inmueble;
}

std::set<Publicacion *> AdministraPropiedad::getPublicaciones() const
{
    return publicaciones;
}

// Setters

void AdministraPropiedad::setInmueble(Inmueble *inmueble)
{
    this->inmueble = inmueble;
}

void AdministraPropiedad::setInmobiliaria(Inmobiliaria *inmobiliaria)
{
    this->inmobiliaria = inmobiliaria;
}
void AdministraPropiedad::eliminarPublicaciones(){
    std::set<Publicacion*>::iterator it;
    for (it = publicaciones.begin(); it != publicaciones.end(); ++it)
    {
        Publicacion *pub = *it;
        delete pub; // Elimina la publicación
    }
    publicaciones.clear(); // Limpia el conjunto de publicaciones
}
    
bool AdministraPropiedad::inmobiliariaAsociada(Inmobiliaria* inmobiliaria){
    return this->inmobiliaria == inmobiliaria;
}