#include "../include/Cliente.h"

Cliente::Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email,
                 std::string apellido, std::string documento) : Usuario(nickname, contrasena, nombre, email)
{
    this->apellido = apellido;
    this->documento = documento;
};

std::list<DTNotificacion> Cliente::consultarNotificaciones()
{
    std::list<DTNotificacion> ultimasNotificaciones = this->notificaciones;
    notificaciones.clear();
    return ultimasNotificaciones;
};

void Cliente::notificar(DTNotificacion notificacion)
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
void Cliente::setApellido(const std::string &nuevoApellido)
{
    apellido = nuevoApellido;
};
void Cliente::setDocumento(const std::string &nuevoDocumento)
{
    documento = nuevoDocumento;
};