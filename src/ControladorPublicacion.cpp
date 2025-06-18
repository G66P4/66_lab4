#include "../include/ControladorPublicacion.h"
#include "../include/ControladorPublicacion.h"
#include "../include/ManejadorPublicacion.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ControladorFechaActual.h"
#include "../include/Publicacion.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Inmobiliaria.h"
#include <map>
#include <set>
#include <iostream>

ControladorPublicacion* ControladorPublicacion::instance = NULL;

ControladorPublicacion::ControladorPublicacion() {}

ControladorPublicacion* ControladorPublicacion::getInstance()
{
    if (instance == NULL) {
        instance = new ControladorPublicacion();
    }
    return instance;
}
void ControladorPublicacion::borrarInstance(){
    if (instance != NULL) {
        instance = NULL;
    }
}
std::set<DTPublicacion*> ControladorPublicacion::listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble){
    ManejadorPublicacion *manejadorPub = ManejadorPublicacion::getInstancia();
    std::set<DTPublicacion*> listaDePublicacionesFiltrada;
    std::map<int, Publicacion *> listaDePublicacionesActivas = manejadorPub->getPublicacionesActivas();
    std::map<int, Publicacion *>::iterator it;
    for (it = listaDePublicacionesActivas.begin(); it != listaDePublicacionesActivas.end(); ++it)
    {
        Publicacion *publicacion = it->second;
        if (publicacion->cumple(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble))
        {
            
            listaDePublicacionesFiltrada.insert(publicacion->crearDTPublicacion());
        }
    }
    return listaDePublicacionesFiltrada;
};
bool ControladorPublicacion::altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio)
{
    ManejadorUsuario *manejadorInmo = ManejadorUsuario::getInstance();
    Inmobiliaria *inmo = manejadorInmo->findInmobiliaria(nicknameInmobiliaria);  
    AdministraPropiedad *admiProp = inmo->adminPropFind(codigoInmueble);
    ControladorFechaActual *manejadorFecha = ControladorFechaActual::getInstance();
    DTFecha *fechaActual = manejadorFecha->getFechaActual();
    int codigo = ManejadorPublicacion::getInstancia()->generarNuevoCodigo();
    if (!(admiProp->tienePub(fechaActual, tipoPublicacion)))
    {     
        Publicacion *publicacion = new Publicacion(codigoInmueble, fechaActual, tipoPublicacion, texto, precio, true);
        publicacion->setAdminProp(admiProp);
        //Agrego la publicacion al administr propiedad
        admiProp->agregarPub(publicacion);
        //Agrego la publicacion al manejador de publicaciones
        ManejadorPublicacion *manejadorPub = ManejadorPublicacion::getInstancia(); 
        manejadorPub->agregarPublicacion(publicacion);
        inmo->modificar(publicacion); // Notifico a la inmobiliaria que se ha creado una nueva publicacion
        return true; 
    }
    else
    {
        delete fechaActual;
        return false;
    }
};

ControladorPublicacion::~ControladorPublicacion() {
    if (instance != NULL) {
        instance = NULL;
    }
}
