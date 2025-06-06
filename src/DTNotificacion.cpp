#include "../include/DTNotificacion.h"

DTNotificacion(int codigo, DTFecha *fecha, std::string texto, std::string nickinmobiliaria, TipoPublicacion tipoPub, TipoInmueble tipoInm){
    this->codigoPublicacion = codigo;
    this->fechaPublicacion = fecha;
    this->nickInmobiliaria = nickinmobiliaria;
    this->textoPublicacion = texto;
    this->tipoPublicacion = tipoPub;
    this->tipoInmuebl = tipoInmueble;
}

// Getters
DTFecha *DTNotificacion::getFechaPublicacion() const
{
    return fechaPublicacion;
}
std::string DTNotificacion::getNickInmobiliaria() const
{
    return nickInmobiliaria;
}
int DTNotificacion::getCodigoPublicacion() const
{
    return codigoPublicacion;
}
std::string DTNotificacion::getTextoPublicacion() const
{
    return textoPublicacion;
}
TipoPublicacion DTNotificacion::getTipoPublicacion() const
{
    return tipoPublicacion; // Assuming TipoPublicacion is a pointer type
}
TipoInmueble DTNotificacion::getTipoInmuebl() const
{
    return tipoInmuebl; // Assuming TipoInmueble is a pointer type
}
