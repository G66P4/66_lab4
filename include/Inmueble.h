#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include <set>
#include "DTFecha.h"
#include "DTInmuebleAdministrado.h"
#include "DTInmuebleListado.h"
#include "TipoInmueble.h"

class Propietario;

class Inmobiliaria;

class AdministraPropiedad; 

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;
        std::set<AdministraPropiedad*> administracion; 

    public:
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        ~Inmueble();

        int getCodigo();
        std::string getDireccion();
        int getNumeroPuerta();
        int getSuperficie();
        int getAnoConstruccion();
        void eliminarLinksInmueble(int codigoInmueble);//llamar a eliminar publicaciones de AdministraPropiedad
        DTInmuebleAdministrado* getinfoInmueble(Inmobiliaria* inm);
        virtual TipoInmueble consultarTipo()  = 0;
        std::set<AdministraPropiedad*>& getAdministracion(); 
        bool esAdministrado(Inmobiliaria* inmobiliaria);
        void asociarAdministracion(AdministraPropiedad* adminProp);
        DTInmuebleListado* convertirADListado(DTInmuebleAdministrado* adminDto, Propietario* propietario);

};

#endif