#ifndef ICONTROLADORUSUARIO_H
#define ICONTROLADORUSUARIO_H
#include <string>
#include <set>
#include "Usuario.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTInmuebleListado.h"
#include "Inmobiliaria.h"

class IControladorUsuario {
    public:
        virtual bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento) = 0;
        virtual bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria,std::string telefono) = 0;
        virtual bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono) = 0;
        virtual std::set<DTUsuario*> listarInmobiliarias() = 0;
        virtual std::set<DTInmuebleAdministrado*> listarInmueblesAdministrados(std::string nickname) = 0;
        virtual std::set<DTUsuario*> listarPropietarios() = 0;
        virtual std::set<DTUsuario*> listarClientes() = 0;
        virtual bool altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble) = 0;
        virtual std::set<DTInmuebleListado*> listarInmueblesNoAdministrados(std::string nicknameInmobiliaria)=0;
        virtual void representarPropietario(std::string nickname, std::string nicknamePropietario) = 0;
        virtual std::set<Inmobiliaria*> listarInmobiliariasNoSuscrito(std::string nickname) = 0;
        virtual std::list<DTNotificacion*> listarNotificaciones(std::string nickname) = 0;

        virtual ~IControladorUsuario();
};

#endif
