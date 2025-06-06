#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include "DTFecha.h"
#include "DTInmuebleAdministrado.h"
#include "TipoInmueble.h"

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;

    public:
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        ~Inmueble();

        int getCodigo();
        std::string getDireccion();
        int getNumeroPuerta();
        int getSuperficie();
        int getAnoConstruccion();
        void eliminarLinksINmueble(int codigoInmueble);
        DTInmuebleAdministrado getinfoInmueble();
        TipoInmueble consultarTipo();
};

#endif