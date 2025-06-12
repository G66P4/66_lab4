#include "../include/ControladorUsuario.h"


ControladorUsuario* ControladorUsuario::instance = NULL;

ControladorUsuario::ControladorUsuario() {}

ControladorUsuario* ControladorUsuario::getInstance() {
    if (instance == NULL) {
        instance = new ControladorUsuario();
    }
    return instance;
}

bool ControladorUsuario::altaCliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento) {
    if( ManejadorUsuario::getInstance()->existeUsuario(nickname) ) {
        return false; // El usuario ya existe
    }else {
        Cliente* cliente = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
        ManejadorUsuario::getInstance()->agregarUsuario(cliente);
        return true; // Usuario creado exitosamente
    }
}

bool ControladorUsuario::altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email,std::string cuentaBancaria,std::string telefono) {
    if( ManejadorUsuario::getInstance()->existeUsuario(nickname) ) {
        return false; // El usuario ya existe
    }else {
        Propietario* propietario = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        ManejadorUsuario::getInstance()->agregarUsuario(propietario);
        return true; // Usuario creado exitosamente
    }
}

bool ControladorUsuario::altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono) {
    if( ManejadorUsuario::getInstance()->existeUsuario(nickname) ) {
        return false; // El usuario ya existe
    }else{
    Inmobiliaria* inmobiliaria = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
    ManejadorUsuario::getInstance()->agregarUsuario(inmobiliaria);
        return true; // Usuario creado exitosamente
    }
}

std::set<DTUsuario*> ControladorUsuario::listarInmobiliarias(){
    std::set<DTUsuario*> inmobiliariasSet;

    std::list<Inmobiliaria*> inmobiliarias = ManejadorUsuario::getInstance()->getInmobiliarias();
    
    for (std::list<Inmobiliaria*>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        Inmobiliaria* inmobiliaria = *it;
        DTUsuario* dtu = inmobiliaria->getInmobiliariaData();
        inmobiliariasSet.insert(dtu);
    }
    return inmobiliariasSet;
}

std::set<DTInmuebleAdministrado*> ControladorUsuario::listarInmueblesAdministrados(std::string nickname) {
    std::set<DTInmuebleAdministrado*> inmueblesAdminSet;
    Inmobiliaria* inmo = ManejadorUsuario::getInstance()->findInmobiliaria(nickname);
    inmueblesAdminSet = inmo->obtenerInmuebleData();
}


std::set<DTUsuario*> ControladorUsuario::listarPropietarios() {
    std::set<DTUsuario*> propietariosSet;

    std::list<Propietario*> propietarios = ManejadorUsuario::getInstance()->getPropietarios();
    
    for (std::list<Propietario*>::iterator it = propietarios.begin(); it != propietarios.end(); ++it) {
        Propietario* propietario = *it;
        DTUsuario* dtu = propietario->getPropietarioData();
        propietariosSet.insert(dtu);
    }
    return propietariosSet;
}

std::set<DTInmuebleListado*> ControladorUsuario::listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria) {
    Inmobiliaria* inmobiliaria = ManejadorUsuario::getInstance()->findInmobiliaria(nicknameInmobiliaria);
    return inmobiliaria->listarInmueblesNoAdministrados();
}

bool ControladorUsuario::altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble) {
    Inmobiliaria* inmobiliaria = ManejadorUsuario::getInstance()->findInmobiliaria(nicknameInmobiliaria);
    if (inmobiliaria == NULL) {
        return false; // Inmobiliaria no encontrada
    }
    
    Inmueble* inmueble = ManejadorInmueble::getInstance()->findInmueble(codigoInmueble);
    if (inmueble == NULL) {
        return false; // Inmueble no encontrado
    }
    
    return inmobiliaria->agregarInmuebleAdministrado(inmueble);
}
ControladorUsuario::~ControladorUsuario() {
    instance = NULL; 
}
void ControladorUsuario::representarPropietario(std::string nickname, std::string nicknamePropietario) {
    Inmobiliaria* inmobiliaria = ManejadorUsuario::getInstance()->findInmobiliaria(nickname);
    if (inmobiliaria != NULL) {
        inmobiliaria->representarPropietario(nicknamePropietario);
    }
}

std::set<DTInmuebleListado*> ControladorUsuario::listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria) {
    Inmobiliaria* inmobiliaria = ManejadorUsuario::getInstance()->findInmobiliaria(nicknameInmobiliaria);
    if (inmobiliaria != NULL) {
        return inmobiliaria->listarInmueblesNoAdministrados();
    }
    std::list<Propietario*> propietarios = ManejadorUsuario::getInstance()->getPropietarios();
    for (std::list<Propietario*>::iterator it = propietarios.begin(); it != propietarios.end(); ++it) {
        Propietario* propietario = *it;
        return propietario->listarInmueblesNoAdministrados(nicknameInmobiliaria);
        }
    }
    