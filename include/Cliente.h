#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include "IObserver.h"
#include <string>
#include <list>
#include "DTNotificacion.h"
#include "Inmobiliaria.h"
class Cliente : public Usuario, public IObserver
{
private:
    std::string apellido;
    std::string documento;
    std::list<DTNotificacion*> notificaciones;
    std::list<Inmobiliaria*> inmobiliariasSuscritas;

public:
    std::list<DTNotificacion*> consultarNotificaciones();
    void Notificar(DTNotificacion *notificacion);
    std::list<Inmobiliaria*> getInmobiliariasSuscritas() const;
    DTUsuario* getClienteData();
    std::string getNicknameO(); // Implementación del método de IObserver
    Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);
    ~Cliente();
    // Getters
    std::string getApellido();
    std::string getDocumento();
    // Setters
    void setApellido( std::string nuevoApellido);
    void setDocumento( std::string nuevoDocumento);
    void agregarSuscripcion(Inmobiliaria* inmobiliaria);
    void eliminarSuscripcion(Inmobiliaria* inmobiliaria);
};

#endif
