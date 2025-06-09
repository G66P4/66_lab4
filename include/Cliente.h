#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include "IObserver.h"
#include <string>
#include <list>
#include "../include/DTNotificacion.h"
class Cliente : public Usuario, public IObserver
{
private:
    std::string apellido;
    std::string documento;
    std::list<DTNotificacion> notificaciones;

public:
    std::list<DTNotificacion> consultarNotificaciones();
    void notificar(DTNotificacion notificacion);
    Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);
    ~Cliente();
    // Getters
    std::string getApellido();
    std::string getDocumento();
    // Setters
    void setApellido(const std::string &nuevoApellido);
    void setDocumento(const std::string &nuevoDocumento);
    void Notificar(DTNotificacion notificacion);
};

#endif
