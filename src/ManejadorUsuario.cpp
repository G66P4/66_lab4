#include "../include/ManejadorUsuario.h"



ManejadorUsuario* ManejadorUsuario::instance = NULL;

ManejadorUsuario::ManejadorUsuario() {}

ManejadorUsuario* ManejadorUsuario::getInstance() {
    if (instance == NULL) {
        instance = new ManejadorUsuario();
    }
    return instance;
}

void ManejadorUsuario::agregarUsuario(Usuario* usuario) {
    usuarios[usuario->getNickname()] = usuario;
}   

void ManejadorUsuario::eliminarUsuario(std::string nickname) {
    Usuario* usuario = findUsuario(nickname);
    if (usuario != NULL) {
        usuarios.erase(nickname);
        delete usuario;
    }
}

bool ManejadorUsuario::existeUsuario(const std::string& nickname) {
    Usuario* usuario = findUsuario(nickname);
    return usuario != NULL;
}

Usuario* ManejadorUsuario::findUsuario(const std::string& nickname){
    Usuario* usuario = findUsuario(nickname);
    if (usuario != NULL) {
        return usuario;
    }
    return NULL;
}

ManejadorUsuario::~ManejadorUsuario() {
    std::map<std::string, Usuario*>::iterator it;   
    for(it=usuarios.begin(); it!=usuarios.end(); ++it) {
        delete it->second;
    }
    usuarios.clear();
    if (instance != NULL) {
        delete instance;
        instance = NULL;
    }
}
