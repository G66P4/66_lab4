#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include "DTUsuario.h"
#include "AdministraPropiedad.h"

#include <string>
#include <map>
#include <set>

class Inmobiliaria : public Usuario {
private:
    std::string direccion;
    std::string url;
    std::string telefono;

    std::map<int, AdministraPropiedad*> propiedades;

public:
    Inmobiliaria(std::string nickname, std::string nombre, std::string email,
                 std::string direccion, std::string url, std::string telefono);

    // Getters
    std::string getDireccion() const;
    std::string getUrl() const;
    std::string getTelefono() const;

    DTUsuario obtenerInmuebleData() const;
    AdministraPropiedad* adminPropFind(int codigoInmueble);
    void eliminarLinkAdmProp(int codigoInmueble);
    DTUsuario getInmobiliariaData() const;

    void agregarSuscripcion();     
    void eliminarSuscripcion();    

    void modificar(); 
};

#endif