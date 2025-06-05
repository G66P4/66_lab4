#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H
#include "IControladorUsuario.h"
#include "Usuario.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "ManejadorUsuario.h"
#include "Inmueble.h"
#include "Inmobiliaria.h" 



class ControladorUsuario : public IControladorUsuario {
private:
    static ControladorUsuario* instance;
    ControladorUsuario();
public:
    static ControladorUsuario* getInstance();
    bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email);
    bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email);
    bool altaInnmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email);
    std::set<DTUsuario*> listarInmobiliarias();
    std::set<DTInmuebleAdministrado*> listarInmueblesAdministrados(std::string nickname);
    ~ControladorUsuario();
};

#endif