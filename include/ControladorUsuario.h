#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H
#include <string>
#include <set>
#include "IControladorUsuario.h"
#include "Usuario.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "ManejadorUsuario.h"
#include "DTInmuebleListado.h"
#include "Inmueble.h"
#include "ManejadorInmueble.h"



class ControladorUsuario : public IControladorUsuario {
private:
    static ControladorUsuario* instance;
    ControladorUsuario();
public:
    static ControladorUsuario* getInstance();
    bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);
    bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
    bool altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email,std::string direccion, std::string url, std::string telefono);
    std::set<DTUsuario*> listarInmobiliarias();
    std::set<DTInmuebleAdministrado*> listarInmueblesAdministrados(std::string nickname);
    std::set<DTUsuario*> listarPropietarios();
    std::set<DTUsuario*> listarClientes();
    std::set<DTInmuebleListado*> listarInmueblesNoAdministrados(std::string nicknameInmobiliaria);
    bool altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble);
    void representarPropietario(std::string nickname, std::string nicknamePropietario);
    std::set<Inmobiliaria*> listarInmobiliariasNoSuscrito(std::string nickname);
    std::list<DTNotificacion*> listarNotificaciones(std::string nickname);
    std::set<Inmobiliaria*> listarInmobiliariasSuscrito(std::string nickname);
    void suscribirNotificaciones(std::string nicknameUsuario, std::string nicknameInmobiliaria);     
    void eliminarSuscripcion(std::string nicknameUsuario, std::string nicknameInmobiliaria);   

    ~ControladorUsuario();
};

#endif