#ifndef ICONTROLADORPUBLICACION_H
#define ICONTROLADORPUBLICACION_H
#include <string>
#include <set>
#include "Publicacion.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"

class IControladorPublicacion {
    public:
        virtual std::set<DTPublicacion*> listarPublicacion(TipoPublicacion tipoP,float precioMinimo,float precioMaximo,TipoInmueble tipoI) = 0;
        virtual bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoP, std::string texto, float precio) = 0;
        virtual ~IControladorPublicacion() {}
};      

#endif