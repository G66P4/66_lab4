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
        ManejadorPublicacion *manejadorPub = ManejadorPublicacion::getInstance();
        manejadorPub->altaPublicacion(codigoInmueble, fechaActual, tipoPublicacion, texto, precio);
        admiProp->agregarPub(manejadorPub->findPublicacion());
        return true;
    }
    else
    {
        delete fechaActual;
        return false;
    }
};