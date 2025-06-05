#ifndef ICONTROLADORUSUARIO_H
#define ICONTROLADORUSUARIO_H
#include <string>
#include <set>
#include "Usuario.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"

class IControladorUsuario {
    public:
        virtual bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email) = 0;
        virtual bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email) = 0;
        virtual bool altaInnmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email) = 0;
        virtual std::set<DTUsuario*> listarInmobiliarias() = 0;
        virtual std::set<DTInmuebleAdministrado*> listarInmueblesAdministrados(std::string nickname) = 0;
        virtual ~IControladorUsuario() {}
};

#endif