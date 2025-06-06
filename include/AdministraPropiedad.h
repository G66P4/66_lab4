#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include <set>
#include "../include/TipoInmueble.h"
#include "../include/TipoPublicacion.h"

class DTFecha;
class Inmobiliaria;
class Inmueble;
class Publicacion;

class AdministraPropiedad
{
private:
    DTFecha *fecha;
    Inmobiliaria *inmobiliaria;
    Inmueble *inmueble;
    std::set<Publicacion *> publicaciones;

public:
    // listarPublicacion dc
    TipoInmueble consultarTipoInmueble();
    // dc de altaPublicacion
    bool tienePub(DTFecha fechaActual, TipoPublicacion tipoPublicacion);
    void agregarPub(Publicacion *publicacion);

    AdministraPropiedad(DTFecha *fecha);
    ~AdministraPropiedad();
    // Getters
    DTFecha *getFecha() const;
    Inmobiliaria *getInmobiliaria() const;
    Inmueble *getInmueble() const;
    std::set<Publicacion *> getPublicaciones() const;
    // Setters
    void setInmobiliaria(Inmobiliaria *inmobiliaria);
    void setInmueble(Inmueble *inmueble);
};

#endif