#include "../include/ControladorPublicacion.h"

std::set<DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble)
{
    ManejadorPublicacion *manejadorPub = ManejadorPublicacion::getInstance();
    std::set<DTPublicacion> listaDePublicaciones;
    for (int i = 0; i < manejadorPub->getTope(); i++)
    {
        Publicacion *publicacion = manejadorPub->getPublicacion(i);
        if (publicacion->cumple(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble))
        {
            listaDePublicaciones.insert(publicacion->crearDTPublicacion());
        }
    }
    return listaDePublicaciones;
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
