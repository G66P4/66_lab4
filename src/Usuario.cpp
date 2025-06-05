#include "../include/Usuario.h"
#include <typeinfo>
#include "../include/Inmobiliaria.h"
#include "../include/Propietario.h"
#include "../include/Cliente.h"


Usuario::Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email) {
    this->nickname = nickname;
    this->contrasena = contrasena;
    this->nombre = nombre;
    this->email = email;
}

Usuario::~Usuario() {
    // Destructor vacio, no hay recursos que liberar
}

std::string Usuario::getNickname(){
    return nickname;
}

std::string Usuario::getNombre(){
    return nombre;
}

bool Usuario::esInmobiliaria() {
    if (typeid(this).name() == typeid(Inmobiliaria).name()) {
        return true;
    }else {
        return false;
    }
}

bool Usuario::esPropietario() {
    if (typeid(this).name() == typeid(Propietario).name()) {
        return true;
    }else {
        return false;
    }
}

bool Usuario::esCliente() {
    if (typeid(this).name() == typeid(Cliente).name()) {
        return true;
    }else {
        return false;
    }
}