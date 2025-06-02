#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include <string>

class Cliente : public Usuario {
    private:
        std::string apellido;
        std::string documento;

    public:
        Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);
        ~Cliente();
};

#endif