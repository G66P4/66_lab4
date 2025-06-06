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
        std::list<Usuario*> Inmobiliarias;
        std::list<Usuario*> Propietarios;
        std::list<Usuario*> Clientes;
        ManejadorUsuario();

    public:
        static ManejadorUsuario* getInstance();
        void agregarUsuario(Usuario* usuario);
        void eliminarUsuario(std::string nickname);
        bool existeUsuario(const std::string& nickname);
        Usuario* findUsuario(const std::string& nickname);
        Inmobiliaria* findInmobiliaria(const std::string& nickname);
        Propietario* findPropietario(const std::string& nickname);
        Cliente* findCliente(const std::string& nickname);
        bool esInmobiliaria(const std::string& nickname);
        bool esPropietario(const std::string& nickname);
        bool esCliente(const std::string& nickname);
        std::list<Usuario*> getInmobiliarias();
        std::list<Usuario*> getPropietarios();
        std::list<Usuario*> getClientes();
        ~ManejadorUsuario();
};
#endif
