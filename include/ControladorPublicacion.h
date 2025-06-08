#ifndef CONTROLADORPUBLICACION_H
#define CONTROLADORPUBLICACION_H
#include <set>
#include <string>
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"

class ControladorPublicacion
{
private:
public:
    std::set<DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble);
    bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);
};
