#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H
#include "IControladorUsuario.h"
#include "Usuario.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"



class ControladorUsuario : public IControladorUsuario {
private:
    static ControladorUsuario* instance;
    ControladorUsuario();
public:
    static ControladorUsuario* getInstance();
    void altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email) override;
    void altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email) override;
    void altaInnmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email) override;
    std::set<DTUsuario*> listarInmobiliarias() override;
    std::set<DTInmuebleAdministrado*> listarInmueblesAdministrados(std::string nickname) override;
    ~ControladorUsuario();
};

#endif