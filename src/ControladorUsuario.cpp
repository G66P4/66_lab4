#include "../include/ControladorUsuario.h"


ControladorUsuario* ControladorUsuario::instance = NULL;

ControladorUsuario::ControladorUsuario() {}

ControladorUsuario* ControladorUsuario::getInstance() {
    if (instance == NULL) {
        instance = new ControladorUsuario();
    }
    return instance;
}

bool ControladorUsuario::altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email) {
    if( ManejadorUsuario::getInstance()->existeUsuario(nickname) ) {
        return false; // El usuario ya existe
    }else {
        Usuario* cliente = new Usuario(nickname, contrasena, nombre, email);
        ManejadorUsuario::getInstance()->agregarUsuario(cliente);
        return true; // Usuario creado exitosamente
    }
}

bool ControladorUsuario::altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email) {
    if( ManejadorUsuario::getInstance()->existeUsuario(nickname) ) {
        return false; // El usuario ya existe
    }else {
        Usuario* propietario = new Usuario(nickname, contrasena, nombre, email);
        ManejadorUsuario::getInstance()->agregarUsuario(propietario);
        return true; // Usuario creado exitosamente
    }
}

bool ControladorUsuario::altaInnmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email) {
    if( ManejadorUsuario::getInstance()->existeUsuario(nickname) ) {
        return false; // El usuario ya existe
    }else{
    Usuario* inmobiliaria = new Usuario(nickname, contrasena, nombre, email);
    ManejadorUsuario::getInstance()->agregarUsuario(inmobiliaria);
        return true; // Usuario creado exitosamente
    }
}

std::set<DTUsuario*> ControladorUsuario::listarInmobiliarias(){
    std::set<DTUsuario*> inmobiliariasSet;

    std::list<Usuario*> inmobiliarias = ManejadorUsuario::getInstance()->getInmobiliarias();
    
    for (std::list<Usuario*>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        Usuario* inmobiliaria = *it;
        DTUsuario* dtInmobiliaria = new DTUsuario(inmobiliaria->getNickname(), inmobiliaria->getNombre());
        inmobiliariasSet.insert(dtInmobiliaria);
    }
    return inmobiliariasSet;
}

std::set<DTInmuebleAdministrado*> ControladorUsuario::listarInmueblesAdministrados(std::string nickname) {
    std::set<DTInmuebleAdministrado*> inmueblesAdminSet;
    Usuario* usuario = ManejadorUsuario::getInstance()->findUsuario(nickname);

    if(usuario == NULL || !usuario->esInmobiliaria()) {
        return inmueblesAdminSet; // Usuario no encontrado o no es una inmobiliaria
    }else{
        std::list<Inmueble*> inmueblesAdministrados = static_cast<Inmobiliaria*>(usuario)->getInmueblesAdministrados();
        for (std::list<Inmueble*>::iterator it = inmueblesAdministrados.begin(); it != inmueblesAdministrados.end(); ++it) {
            Inmueble* inmueble = *it;
            DTInmuebleAdministrado* dtInmueble = new DTInmuebleAdministrado(inmueble->getCodigo(), inmueble->getDireccion(), inmueble->getFechaComienzo());
            inmueblesAdminSet.insert(dtInmueble);
        }
        return inmueblesAdminSet; 
    }
}
