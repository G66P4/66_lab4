#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include "DTUsuario.h"
#include <string>

class Propietario : public Usuario {
    private:
        std::string cuentaBancaria;
        std::string telefono;
        std::list<DTNotificacion> notificaciones;
        std::list<Inmueble*> inmueblesDueno;
        std::list<Inmobiliaria*> inmobiliariasSuscritas;

    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
        DTUsuario* getPropietarioData();
        ~Propietario();
        //Getters
        std::string getCuentaBancaria();
        std::string getTelefono();
        void Notificar(DTNotificacion notificacion);
        void removerLinkPropiedad(int codigoInmueble);
};

#endif