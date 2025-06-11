#ifndef MANEJADORINMUEBLE_H
#define MANEJADORINMUEBLE_H

#include <map>
#include <string>
#include "Inmueble.h"

class ManejadorInmueble {
    private:
        static ManejadorInmueble* instance;
        std::map <int, Inmueble*> inmuebles;
        ManejadorInmueble();
        static int ultimoCodigo;

    public:
        static ManejadorInmueble* getInstance();
        static void liberarInstancia();
        void agregarInmueble(Inmueble* inmueble);
        void eliminarInmueble(int codigo);
        bool existeInmueble(const int codigo);
        Inmueble* findInmueble(const int codigo);
        int generarNuevoCodigo();
        ~ManejadorInmueble();
};
#endif