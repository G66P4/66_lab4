#include "../include/Usuario.h"

Usuario::Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email) {
    this->nickname = nickname;
    this->contrasena = contrasena;
    this->nombre = nombre;
    this->email = email;
}

Usuario::~Usuario() {
    // Destructor vacio, no hay recursos que liberar
}

std::string Usuario::getNickname() const {
    return nickname;
}

std::string Usuario::getNombre() const {
    return nombre;
}
