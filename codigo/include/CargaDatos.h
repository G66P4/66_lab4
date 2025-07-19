#ifndef CARGADATOS_H
#define CARGADATOS_H

#include "IControladorFechaActual.h"
#include "IControladorUsuario.h"
#include "IControladorInmueble.h"
#include "IControladorPublicacion.h"
#include "Factory.h"
class CargaDatos {
    private:
        static CargaDatos* instance;
        CargaDatos();

    public:
        static CargaDatos* getInstance();
        ~CargaDatos();
        static void liberarInstancia();
};

#endif