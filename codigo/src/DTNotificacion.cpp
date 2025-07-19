#include "../include/DTNotificacion.h"

DTNotificacion::DTNotificacion(int codigo, DTFecha* fecha, std::string texto, std::string nickinmobiliaria, TipoPublicacion tipoPub, TipoInmueble tipoInm){
    this->codigoPublicacion = codigo;
    this->fechaPublicacion = new DTFecha(*fecha);  // copia la fecha;
    this->nickInmobiliaria = nickinmobiliaria;
    this->textoPublicacion = texto;
    this->tipoPublicacion = tipoPub;
    this->tipoInmuebl = tipoInm;
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
    return tipoPublicacion; 
}
TipoInmueble DTNotificacion::getTipoInmuebl() const
{
    return tipoInmuebl; 
}

// Destructor
DTNotificacion::~DTNotificacion() {
    delete fechaPublicacion;
}