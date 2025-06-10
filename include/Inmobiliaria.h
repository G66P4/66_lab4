#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include "DTUsuario.h"
#include "Propietario.h"
#include "DTInmuebleAdministrado.h"

#include <string>
#include <map>
#include <set>
#include <list>

class AdministraPropiedad;

class Inmobiliaria : public Usuario {
private:
    std::string direccion;
    std::string url;
    std::string telefono;

    std::list<Propietario*> representa;
    std::set<Usuario*> suscriptores; 

    AdministraPropiedad* propiedad; 

public:
    Inmobiliaria(std::string nickname, std::string nombre, std::string email,
                 std::string direccion, std::string url, std::string telefono);

    // Getters
    std::string getDireccion() const;
    std::string getUrl() const;
    std::string getTelefono() const;

    DTInmuebleAdministrado* obtenerInmuebleData() const;
    AdministraPropiedad* adminPropFind(int codigoInmueble);
    void eliminarLinkAdmProp(int codigoInmueble);
    DTUsuario* getInmobiliariaData() const;

    void representarPropietario(std::string nicknamePropietario);
    void agregarSuscripcion();     
    void eliminarSuscripcion();    

    void modificar(); 
};

#endif