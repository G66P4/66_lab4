#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include <map>
#include <string>
#include "Usuario.h"



class ManejadorUsuario {
    private:
        static ManejadorUsuario* instance;
        std::map <std::string, Usuario*> usuarios;
        ManejadorUsuario();

    public:
        static ManejadorUsuario* getInstance();
        void agregarUsuario(Usuario* usuario);
        void eliminarUsuario(std::string nickname);
        bool existeUsuario(const std::string& nickname);
        Usuario* findUsuario(const std::string& nickname);
        ~ManejadorUsuario();
};
#endif
