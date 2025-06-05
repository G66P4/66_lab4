#include "../include/ManejadorUsuario.h>"



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
    return usuarios.find(nickname) != NULL;
}

Usuario* ManejadorUsuario::findUsuario(const std::string& nickname){
    Usuario* usuario== usuarios.find(nickname);
    if (usuario != NULL) {
        return usuario->second;
    }
    return NULL;
}

ManejadorUsuario::~ManejadorUsuario() {
    for(Usuario* usuario : usuarios) {
        delete usuario.second;
    }
    usuarios.clear();
    instance = NULL;
}
