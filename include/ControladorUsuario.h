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
    bool altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email) override;
    bool altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email) override;
    bool altaInnmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email) override;
    std::set<DTUsuario*> listarInmobiliarias() override;
    std::set<DTInmuebleAdministrado*> listarInmueblesAdministrados(std::string nickname) override;
    ~ControladorUsuario();
};

#endif