#include "../include/propietario.h

Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono):Usuario(nickname, contrasena, nombre, email){
    this->cuentaBancaria = cuentaBancaria;
    this->telefono = telefono;
};

std::string Propietario::getCuentaBancaria(){
    return cuentaBancaria;
};

std::string Propietario::getTelefono(){
    return telefono;
};

Propietario::~Propietario(){};