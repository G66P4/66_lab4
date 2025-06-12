#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include "DTUsuario.h"
#include "DTNotificacion.h"
#include "DTInmuebleListado.h"
#include "ManejadorInmueble.h"

#include <string>
#include <set>
#include <list>
#include <map>

class Inmueble;
class Inmobiliaria;

class Propietario : public Usuario {
    private:
        std::string cuentaBancaria;
        std::string telefono;
        std::list<DTNotificacion*> notificaciones;
        std::list<Inmueble*> inmueblesDueno;
        std::list<Inmobiliaria*> inmobiliariasSuscritas;

    public:
        //falta Notificar a las inmobiliarias suscritas consultar suscripciones y que propietario es hoijo de iovserver(es copiar y pegar lo de Cliente)
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
        DTUsuario* getPropietarioData();
        ~Propietario();
        //Getters
        std::string getCuentaBancaria();
        std::string getTelefono();
        
        void Notificar(DTNotificacion notificacion);
        void removerLinkPropiedad(int codigoInmueble);
        void asociarInmueble(Inmueble* inmueble);
        std::set<DTInmuebleListado*> listarInmueblesNoAdministrados(std::string nicknameInmobiliaria);
};

#endif