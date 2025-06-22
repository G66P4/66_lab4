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
        ManejadorUsuario::getInstance()->agregarCliente(cliente);
        return true; // Usuario creado exitosamente
    }
}

bool ControladorUsuario::altaPropietario(std::string nickname, std::string contrasena, std::string nombre, std::string email,std::string cuentaBancaria,std::string telefono) {
    if( ManejadorUsuario::getInstance()->existeUsuario(nickname) ) {
        return false; // El usuario ya existe
    }else {
        Propietario* propietario = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
        ManejadorUsuario::getInstance()->agregarPropietario(propietario);
        return true; // Usuario creado exitosamente
    }
}

bool ControladorUsuario::altaInmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono) {
    if( ManejadorUsuario::getInstance()->existeUsuario(nickname) ) {
        return false; // El usuario ya existe
    }else{
    Inmobiliaria* inmobiliaria = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
    ManejadorUsuario::getInstance()->agregarInmobiliaria(inmobiliaria);
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
    return inmueblesAdminSet;
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

std::set<DTUsuario*> ControladorUsuario::listarClientes() {
    std::set<DTUsuario*> clientesSet;

    std::list<Cliente*> clientes = ManejadorUsuario::getInstance()->getClientes();
    
    for (std::list<Cliente*>::iterator it = clientes.begin(); it != clientes.end(); ++it) {
        Cliente* cliente = *it;
        DTUsuario* dtu = cliente->getClienteData();
        clientesSet.insert(dtu);
    }
    return clientesSet;
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

std::set<DTInmuebleListado*> ControladorUsuario::listarInmueblesNoAdministrados(std::string nicknameInmobiliaria) {
    std::set<DTInmuebleListado*> inmueblesNoAdminSet;
    Inmobiliaria* inmobiliaria = ManejadorUsuario::getInstance()->findInmobiliaria(nicknameInmobiliaria);
    if (inmobiliaria == NULL) {
        return inmueblesNoAdminSet; // Inmobiliaria no encontrada
    }else {
        inmueblesNoAdminSet = inmobiliaria->listarInmueblesNoAdministrados();
    }
    return inmueblesNoAdminSet; 
}

std::set<Inmobiliaria*> ControladorUsuario::listarInmobiliariasNoSuscrito(std::string nickname) {
    std::set<Inmobiliaria*> inmobiliariasNoSuscrito;
    std::list<Inmobiliaria*> inmobiliarias = ManejadorUsuario::getInstance()->getInmobiliarias();
    
    for (std::list<Inmobiliaria*>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        Inmobiliaria* inmobiliaria = *it;
        if (!inmobiliaria->esSuscriptor(nickname)) {
            inmobiliariasNoSuscrito.insert(inmobiliaria);
        }
    }
    return inmobiliariasNoSuscrito;
}

std::list<DTNotificacion*> ControladorUsuario::listarNotificaciones(std::string nickname) {
    std::list<DTNotificacion*> notificacionesSet;
    Propietario* propietario = ManejadorUsuario::getInstance()->findPropietario(nickname);
    if (propietario != NULL) {
        notificacionesSet = propietario->consultarNotificaciones();
    } else {
        Cliente* cliente = ManejadorUsuario::getInstance()->findCliente(nickname);
        if (cliente != NULL) {
            notificacionesSet = cliente->consultarNotificaciones();
        }
    }
    return notificacionesSet;
}  

std::set<Inmobiliaria*> ControladorUsuario::listarInmobiliariasSuscrito(std::string nickname) {
    std::set<Inmobiliaria*> inmobiliariasSuscrito;
    std::list<Inmobiliaria*> inmobiliarias = ManejadorUsuario::getInstance()->getInmobiliarias();
    
    for (std::list<Inmobiliaria*>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        Inmobiliaria* inmobiliaria = *it;
        if (inmobiliaria->esSuscriptor(nickname)) {
            inmobiliariasSuscrito.insert(inmobiliaria);
        }
    }
    return inmobiliariasSuscrito;
}


void ControladorUsuario::suscribirNotificaciones(std::string nicknameUsuario, std::string nicknameInmobiliaria) {
    Inmobiliaria* inmobiliaria = ManejadorUsuario::getInstance()->findInmobiliaria(nicknameInmobiliaria);
    IObserver* propietario = ManejadorUsuario::getInstance()->findPropietario(nicknameUsuario);
    if( propietario != NULL && inmobiliaria != NULL) {
        propietario->agregarSuscripcion(inmobiliaria);
        inmobiliaria->agregarSuscripcion(propietario);
    } else {
        Cliente* cliente = ManejadorUsuario::getInstance()->findCliente(nicknameUsuario);
        if (cliente != NULL && inmobiliaria != NULL) {
            cliente->agregarSuscripcion(inmobiliaria);
            inmobiliaria->agregarSuscripcion(cliente);
        }
    }
    
}

void ControladorUsuario::eliminarSuscripcion(std::string nicknameUsuario, std::string nicknameInmobiliaria) {
    Inmobiliaria* inmobiliaria = ManejadorUsuario::getInstance()->findInmobiliaria(nicknameInmobiliaria);
    IObserver* propietario = ManejadorUsuario::getInstance()->findPropietario(nicknameUsuario);
    if( propietario != NULL && inmobiliaria != NULL) {
        propietario->eliminarSuscripcion(inmobiliaria);
        inmobiliaria->eliminarSuscripcion(propietario);
    } else {
        IObserver* cliente = ManejadorUsuario::getInstance()->findCliente(nicknameUsuario);
        if (cliente != NULL && inmobiliaria != NULL) {
            cliente->eliminarSuscripcion(inmobiliaria);
            inmobiliaria->eliminarSuscripcion(cliente);
        }
    }
}

void ControladorUsuario::eliminarNotificaciones(std::string nicknameUsuario, std::string nicknameInmobiliaria){
    Inmobiliaria* inmo = ManejadorUsuario::getInstance()->findInmobiliaria(nicknameInmobiliaria);
    IObserver* suscrito = ManejadorUsuario::getInstance()->findPropietario(nicknameUsuario);
    if(suscrito != NULL && inmo != NULL){
        suscrito->eliminarNotificaciones(nicknameInmobiliaria);
    }else{
        IObserver* suscrito = ManejadorUsuario::getInstance()->findCliente(nicknameUsuario);
        if (suscrito!= NULL && inmo != NULL){
            suscrito->eliminarNotificaciones(nicknameInmobiliaria);
        }
        
    }
}
    