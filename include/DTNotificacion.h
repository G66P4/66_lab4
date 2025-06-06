#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <string>
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"


class DTNotificacion
{
private:
    DTFecha* fechaPublicacion;
    std::string nickInmobiliaria;
    int codigoPublicacion;
    std::string textoPublicacion;
    TipoPublicacion tipoPublicacion;
    TipoInmueble tipoInmuebl;

public:
    DTNotificacion(int codigo, DTFecha* fecha, std::string texto, std::string nickinmobiliaria, TipoPublicacion tipoPub, TipoInmueble tipoInm);
    // Getters
    DTFecha* getFechaPublicacion() const;
    std::string getNickInmobiliaria() const;
    int getCodigoPublicacion() const;
    std::string getTextoPublicacion() const;
    TipoPublicacion getTipoPublicacion() const;
    TipoInmueble getTipoInmuebl() const;
};

#endif