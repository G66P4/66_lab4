#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include <map>
#include <string>
#include <list>
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "Propietario.h"
#include "Cliente.h"



class ManejadorUsuario {
    private:
        static ManejadorUsuario* instance;
        std::map <std::string, Usuario*> usuarios;
        std::list<Inmobiliaria*> Inmobiliarias;
        std::list<Propietario*> Propietarios;
        std::list<Cliente*> Clientes;
        ManejadorUsuario();

    public:
        static ManejadorUsuario* getInstance();
        void agregarCliente(Cliente* cliente);
        void agregarPropietario(Propietario* propietario);
        void agregarInmobiliaria(Inmobiliaria* inmobiliaria);
        void eliminarUsuario(std::string nickname);
        bool existeUsuario( std::string& nickname);
        Usuario* findUsuario( std::string& nickname);
        Inmobiliaria* findInmobiliaria( std::string& nickname);
        Propietario* findPropietario( std::string& nickname);
        Cliente* findCliente( std::string& nickname);
        bool esInmobiliaria( std::string& nickname);
        bool esPropietario( std::string& nickname);
        bool esCliente( std::string& nickname);
        std::list<Inmobiliaria*> getInmobiliarias();
        std::list<Propietario*> getPropietarios();
        std::list<Cliente*> getClientes();
        ~ManejadorUsuario();
};
#endif
