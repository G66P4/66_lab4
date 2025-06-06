#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include "DTInmuebleAdministrado.h"
#include <string>
#include <list>

class Inmobiliaria : public Usuario {
    private:
        std::string direccion;
        std::string url;
        std::string telefono;

    public:
        Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);
        std::list<DTInmuebleAdministrado*> obtenerInmuebleData();
        ~Inmobiliaria();
};

#endif