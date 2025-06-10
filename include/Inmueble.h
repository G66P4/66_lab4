#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include "DTFecha.h"
#include "DTInmuebleAdministrado.h"
#include "TipoInmueble.h"
#include "Inmobiliaria.h"
class AdministraPropiedad; //se usa class en lugar de #include para evitar dependencias circulares

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
        virtual ~Inmueble();

        int getCodigo();
        std::string getDireccion();
        int getNumeroPuerta();
        int getSuperficie();
        int getAnoConstruccion();
        void eliminarLinksInmueble(int codigoInmueble);//llamar a eliminar publicaciones de AdministraPropiedad
        DTInmuebleAdministrado getinfoInmueble(Inmobiliaria* inm);
        virtual TipoInmueble consultarTipo() const = 0;
        std::set<AdministraPropiedad*>& getAdministracion(); 
        bool esAdministrado(Inmobiliaria* inmobiliaria);
        void asociarAdministracion(AdministraPropiedad* adminProp);

};

#endif