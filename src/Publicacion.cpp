#include "../include/Publicacion.h"
#include "../include/DTPublicacion.h"
#include "../include/DTFecha.h"
#include "../include/DTUsuario.h"
#include "../include/Inmobiliaria.h"
#include "../include/AdministraPropiedad.h"

#include <string>
using namespace std;

Publicacion::Publicacion(int codigo, const DTFecha& fecha, TipoPublicacion tipo,
                         const string& texto, float precio, bool activa)
    : codigo(codigo), fecha(fecha), tipo(tipo),
      texto(texto), precio(precio), activa(activa) {}

Publicacion::~Publicacion() {}

bool Publicacion::cumple(TipoPublicacion tipoPub, float precioMinimo, float precioMaximo, TipoInmueble tipoInm)  {
    return tipo == tipoPub &&
           precio >= precioMinimo &&
           precio <= precioMaximo &&
           adminProp->getInmueble()->consultarTipo() == tipoInm;
}



DTPublicacion Publicacion::crearDTPublicacion() const {
    // Obtener el DTUsuario desde la inmobiliaria asociada
    DTUsuario* dtInmo = adminProp->getInmobiliaria()->getInmobiliariaData();

    // Extraer el nickname o nombre según lo que necesites
    std::string inmobiliaria = dtInmo->getNickname(); // o dtInmo.getNombre()

    return DTPublicacion(
        codigo,
        new DTFecha(fecha),
        texto,
        std::to_string(precio),
        inmobiliaria
    );
}
//getters
int Publicacion::getCodigo() const {
    return codigo;
}

DTFecha Publicacion::getFecha() const {
    return fecha;
}

TipoPublicacion Publicacion::getTipo() const {
    return tipo;
}

string Publicacion::getTexto() const {
    return texto;
}

float Publicacion::getPrecio() const {
    return precio;
}

bool Publicacion::estaActiva() const {
    return activa;
}