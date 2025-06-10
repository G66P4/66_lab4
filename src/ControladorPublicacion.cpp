#include "../include/ControladorPublicacion.h"

std::set<DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble)
{
    ManejadorPublicacion *manejadorPub = ManejadorPublicacion::getInstance();
    std::set<DTPublicacion> listaDePublicacionesFiltrada;
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
bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio)
{
    ManejadorUsuario *manejadorInmo = ManejadorUsuario::getInstance();
    Inmobiliaria *inmo = manejadorInmo->findUsuario(nicknameInmobiliaria);  
    AdministrarPropiedad *admiProp = inmo->adminPropFind(codigoInmueble);
    ManejadorFechaActual *manejadorFecha = ManejadorFechaActual::getInstance();
    DTFecha *fechaActual = manejadorFecha->getFechaActual();
    if (!(admiProp->tienePub(fechaActual, tipoPublicacion)))
    {
        //Creo una nueva publicacion
        Publicacion *publicacion = new Publicacion(codigoInmueble, fechaActual, tipoPublicacion, texto, precio, true);
        //Agrego la publicacion al administr propiedad
        admiProp->agregarPub(publicacion);
        //Agrego la publicacion al manejador de publicaciones
        manejadorInmo->agregarPublicacion(publicacion);
        return true; 
    }
    else
    {
        delete fechaActual;
        return false;
    }
};
