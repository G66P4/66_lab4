#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include "Inmueble.h"
#include "TipoInmueble.h"
#include "DTPublicacion.h"
#include "AdministraPropiedad.h"
class Publicacion {
private:
    int codigo;
    DTFecha* fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;
    AdministraPropiedad* adminProp;

public:
    // Constructor
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, const std::string& texto, float precio, bool activa);

    // Destructor
    ~Publicacion();

    bool cumple(TipoPublicacion tipo, float precioMin, float precioMax, TipoInmueble tipoInmueble);  // el tipoInmueble se compara afuera
    DTPublicacion* crearDTPublicacion() const;

    // Getters
    int getCodigo() const;
    DTFecha* getFecha() const;
    TipoPublicacion getTipo() const;
    std::string getTexto() const;
    float getPrecio() const;
    bool estaActiva() const;
    std::string getInmobiliaria() const;
    AdministraPropiedad* getAdminProp();

    //setter
    void setAdminProp(AdministraPropiedad* adminProp);
    void setActiva(bool activa);
};

#endif