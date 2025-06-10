#include "../include/Publicacion.h"
#include "../include/DTPublicacion.h"
#include "../include/DTFecha.h"
#include "../include/DTUsuario.h"
#include "../include/Inmobiliaria.h"
#include "../include/AdministraPropiedad.h"

#include <string>
using namespace std;

Publicacion::Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, const string& texto, float precio, bool activa){
    this->codigo = codigo;
    this->fecha = fecha;
    this->tipo = tipo;
    this->texto = texto;
    this->precio = precio;
    this->activa = activa;

    // Inicializar adminProp a NULL, se asignará más tarde
    this->adminProp = nullptr;
}

Publicacion::~Publicacion() {}

bool Publicacion::cumple(TipoPublicacion tipoPub, float precioMinimo, float precioMaximo, TipoInmueble tipoInm)  {
    return tipo == tipoPub &&
           precio >= precioMinimo &&
           precio <= precioMaximo &&
           adminProp->getInmueble()->consultarTipo() == tipoInm;
}



DTPublicacion* Publicacion::crearDTPublicacion() const {
    DTUsuario* dtInmo = adminProp->getInmobiliaria()->getInmobiliariaData();

    std::string inmobiliaria = dtInmo->getNickname(); // o dtInmo.getNombre()
    DTPublicacion* DTP = new DTPublicacion( codigo, new DTFecha(fecha), texto, std::to_string(precio), inmobiliaria);
    return DTP;
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

//setter
void Publicacion::setActiva(bool activa) {
    this->activa = activa;
}




