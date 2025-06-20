#include "../include/ManejadorUsuario.h"



ManejadorUsuario* ManejadorUsuario::instance = NULL;

ManejadorUsuario::ManejadorUsuario() {}

ManejadorUsuario* ManejadorUsuario::getInstance() {
    if (instance == NULL) {
        instance = new ManejadorUsuario();
    }
    return instance;
}

void ManejadorUsuario::liberarInstancia() {
    if (instance != NULL) {
        delete instance;
        instance = NULL;     
    }
}

void ManejadorUsuario::agregarCliente(Cliente* cliente) {
    usuarios[cliente->getNickname()] = cliente;
    Clientes.push_back(cliente);
}

void ManejadorUsuario::agregarPropietario(Propietario* propietario) {
    usuarios[propietario->getNickname()] = propietario;
    Propietarios.push_back(propietario);
}

void ManejadorUsuario::agregarInmobiliaria(Inmobiliaria* inmobiliaria) {
    usuarios[inmobiliaria->getNickname()] = inmobiliaria;
    Inmobiliarias.push_back(inmobiliaria);
}

void ManejadorUsuario::eliminarUsuario(std::string nickname) {
    Inmobiliaria* usuario = findInmobiliaria(nickname);
    if (usuario != NULL) {
        usuarios.erase(nickname);
        if( usuario->esInmobiliaria() ) {
            Inmobiliarias.remove(usuario);
        delete usuario;
        }
    } else {
        Propietario* propietario = findPropietario(nickname);
        if (propietario != NULL) {
            usuarios.erase(nickname);
            Propietarios.remove(propietario);
            delete propietario;
        } else {
            Cliente* cliente = findCliente(nickname);
            if (cliente != NULL) {
                usuarios.erase(nickname);
                Clientes.remove(cliente);
                delete cliente;
            }
        }
    }
}

bool ManejadorUsuario::existeUsuario( std::string& nickname) {
    Usuario* usuario = findUsuario(nickname);
    return usuario != NULL;
}

Usuario* ManejadorUsuario::findUsuario( std::string& nickname){
    std::map<std::string, Usuario*>::iterator it = usuarios.find(nickname);
    if (it != usuarios.end()) {
        return it->second; 
    }
    return NULL; 
   
}

Inmobiliaria* ManejadorUsuario::findInmobiliaria( std::string& nickname) {
   std::list<Inmobiliaria*> inmobiliarias= getInmobiliarias();
    for (Inmobiliaria* inmobiliaria : inmobiliarias) {
        if (inmobiliaria->getNickname() == nickname) {
            return inmobiliaria;
        }
    }
    return NULL;
}

Propietario* ManejadorUsuario::findPropietario( std::string& nickname) {
    std::list<Propietario*> propietarios= getPropietarios();
    for (Propietario* propietario : propietarios) {
        if (propietario->getNickname() == nickname) {
            return propietario;
        }
    }
    return NULL;
}

Cliente* ManejadorUsuario::findCliente( std::string& nickname) {
    std::list<Cliente*> clientes = getClientes();
    for (Cliente* cliente : clientes) {
        if (cliente->getNickname() == nickname) {
            return cliente;
        }
    }
    return NULL;
}

bool ManejadorUsuario::esInmobiliaria( std::string& nickname) {
    Usuario* usuario = findUsuario(nickname);
    if (usuario == NULL) {
        return false; 
    }else{
        return usuario->esInmobiliaria();
    }
}

bool ManejadorUsuario::esPropietario( std::string& nickname) {
    Usuario* usuario = findUsuario(nickname);
    if( usuario == NULL ) {
        return false; 
    }else{
        return usuario->esPropietario();
    }
}

bool ManejadorUsuario::esCliente( std::string& nickname) {
    Usuario* usuario = findUsuario(nickname);
    if (usuario == NULL) {
        return false; 
    } else {
        return usuario->esCliente();
    }
    
}

ManejadorUsuario::~ManejadorUsuario() {
    std::map<std::string, Usuario*>::iterator it;   
    for(it=usuarios.begin(); it!=usuarios.end(); ++it) {
        it->second->~Usuario(); // Liberar memoria de cada usuario
    }
    usuarios.clear();
    Inmobiliarias.clear();
    Propietarios.clear();
    Clientes.clear();
    delete instance; 
}

std::list<Inmobiliaria*> ManejadorUsuario::getInmobiliarias() {
    return Inmobiliarias;
}

std::list<Propietario*> ManejadorUsuario::getPropietarios() {
    return Propietarios;
}

std::list<Cliente*> ManejadorUsuario::getClientes() {
    return Clientes;
}

