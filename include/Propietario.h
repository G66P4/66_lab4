#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include <string>

class Propietario : public Usuario {
    private:
        std::string cuentaBancaria;
        std::string telefono;

    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
};

#endif