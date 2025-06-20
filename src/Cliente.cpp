#include "../include/Cliente.h"

Cliente::Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email,
                 std::string apellido, std::string documento) : Usuario(nickname, contrasena, nombre, email)
{
    this->apellido = apellido;
    this->documento = documento;
};

std::list<DTNotificacion*> Cliente::consultarNotificaciones()
{
    std::list<DTNotificacion*> ultimasNotificaciones = this->notificaciones;
    notificaciones.clear();
    return ultimasNotificaciones;
};

void Cliente::Notificar(DTNotificacion *notificacion)
{
    this->notificaciones.push_back(notificacion);
};
// Getters
std::string Cliente::getApellido()
{
    return apellido;
};
std::string Cliente::getDocumento()
{
    return documento;
};
// Setters
void Cliente::setApellido( std::string nuevoApellido)
{
    apellido = nuevoApellido;
};

void Cliente::setDocumento( std::string nuevoDocumento)
{
    documento = nuevoDocumento;
};

std::list<Inmobiliaria*> Cliente::getInmobiliariasSuscritas() const{
    return inmobiliariasSuscritas;
}

DTUsuario* Cliente::getClienteData() {
    return new DTUsuario(getNickname(), getNombre());
}

std::string Cliente::getNicknameO() {
    std::string nickname = getNickname();
    return nickname;
}

void Cliente::agregarSuscripcion(Inmobiliaria* inmobiliaria) {
    if (inmobiliaria != NULL) {
        inmobiliariasSuscritas.push_back(inmobiliaria);
    }
}

void Cliente::eliminarSuscripcion(Inmobiliaria* inmobiliaria) {
    if(inmobiliaria != NULL) {
        inmobiliariasSuscritas.remove(inmobiliaria);
    }
}

Cliente::~Cliente()
{
    notificaciones.clear();
}