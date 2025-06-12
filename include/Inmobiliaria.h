#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include "DTUsuario.h"
#include "Propietario.h"
#include "DTInmuebleAdministrado.h"
#include "DTInmuebleListado.h"

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

    std::map<int, AdministraPropiedad*> propiedades; // clave = código del inmueble 

public:
    Inmobiliaria(std::string nickname,std::string contasena , std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);

    // Getters
    std::string getDireccion() const;
    std::string getUrl() const;
    std::string getTelefono() const;

    std::set<DTInmuebleListado*> Inmobiliaria::listarInmueblesNoAdministrados();
    std::set<DTInmuebleAdministrado*> obtenerInmuebleData();//devuelve todos los inmuebles administrados por la inmobiliaria
    bool agregarInmuebleAdministrado(Inmueble* inmueble);
    AdministraPropiedad* adminPropFind(int codigoInmueble);
    void eliminarLinkAdmProp(int codigoInmueble);
    DTUsuario* getInmobiliariaData();


    void representarPropietario(std::string nicknamePropietario);
    void agregarSuscripcion();     
    void eliminarSuscripcion();    

    void modificar(); 
};

#endif