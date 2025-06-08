#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include <string>
#include <set>

class Inmobiliaria : public Usuario {
    private:
        std::string direccion;
        std::string url;
        std::string telefono;

    public:
        Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);
        std::set<DTInmuebleAdministrado*> obtenerInmuebleData();
        DTUsuario* getInmobiliariaData();
        void representarPropietario(std::string nicknamePropietario);//agrega el propietario a la lista de propietarios representados
        ~Inmobiliaria();
};

#endif