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
    if (usuario->esInmobiliaria()) {
        Inmobiliarias.push_back(usuario);
    } else if (usuario->esPropietario()) {
        Propietarios.push_back(usuario);
    } else if (usuario->esCliente()) {
        Clientes.push_back(usuario);
    }
}   

void ManejadorUsuario::eliminarUsuario(std::string nickname) {
    Usuario* usuario = findUsuario(nickname);
    if (usuario != NULL) {
        usuarios.erase(nickname);
        if( usuario->esInmobiliaria() ) {
            Inmobiliarias.remove(usuario);
        } else if (usuario->esPropietario()) {
            Propietarios.remove(usuario);
        } else if (usuario->esCliente()) {
            Clientes.remove(usuario);
        }
        delete usuario;
    }
}

bool ManejadorUsuario::existeUsuario(const std::string& nickname) {
    Usuario* usuario = findUsuario(nickname);
    return usuario != NULL;
}

Usuario* ManejadorUsuario::findUsuario(const std::string& nickname){
    std::map<std::string, Usuario*>::iterator it = usuarios.find(nickname);
    if (it != usuarios.end()) {
        return it->second; 
    }
    return NULL; 
   
}

Inmobiliaria* ManejadorUsuario::findInmobiliaria(const std::string& nickname) {
    Usuario* usuario = findUsuario(nickname);
    if (usuario != NULL && usuario->esInmobiliaria()) {
        return dynamic_cast<Inmobiliaria*>(usuario);
    }
    return NULL;
}

Propietario* ManejadorUsuario::findPropietario(const std::string& nickname) {
    Usuario* usuario = findUsuario(nickname);
    if (usuario != NULL && usuario->esPropietario()) {
        return dynamic_cast<Propietario*>(usuario);
    }
    return NULL;
}

Cliente* ManejadorUsuario::findCliente(const std::string& nickname) {
    Usuario* usuario = findUsuario(nickname);
    if (usuario != NULL && usuario->esCliente()) {
        return dynamic_cast<Cliente*>(usuario);
    }
    return NULL;
}

bool ManejadorUsuario::esInmobiliaria(const std::string& nickname) {
    Usuario* usuario = findUsuario(nickname);
    if (usuario == NULL) {
        return false; 
    }else{
        return usuario->esInmobiliaria();
    }
}

bool ManejadorUsuario::esPropietario(const std::string& nickname) {
    Usuario* usuario = findUsuario(nickname);
    if( usuario == NULL ) {
        return false; 
    }else{
        return usuario->esPropietario();
    }
}

bool ManejadorUsuario::esCliente(const std::string& nickname) {
    Usuario* usuario = findUsuario(nickname);
    if (usuario == NULL) {
        return false; 
    }else{
        return usuario->esCliente();
    }
}

ManejadorUsuario::~ManejadorUsuario() {
    std::map<std::string, Usuario*>::iterator it;   
    for(it=usuarios.begin(); it!=usuarios.end(); ++it) {
        delete it->second; // Liberar memoria de cada usuario
    }
    usuarios.clear();
    Inmobiliarias.clear();
    Propietarios.clear();
    Clientes.clear();
}

std::list<Usuario*> ManejadorUsuario::getInmobiliarias() {
    return Inmobiliarias;
}

std::list<Usuario*> ManejadorUsuario::getPropietarios() {
    return Propietarios;
}

std::list<Usuario*> ManejadorUsuario::getClientes() {
    return Clientes;
}

