#include "../include/DTUsuario.h"
#include <iostream>

DTUsuario::DTUsuario(std::string nickname, std::string nombre) {
    this->nickname = nickname;
    this->nombre = nombre;
}

std::string DTUsuario::getNickname() {
    return nickname;
}

std::string DTUsuario::getNombre() {
    return nombre;
}

bool DTUsuario::operator<(DTUsuario& other) {
    return nickname < other.nickname; // Comparar directamente los campo
}
