#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IControladorUsuario.h"
#include "IControladorInmueble.h"
#include "IControladorPublicacion.h"
#include "ControladorFechaActual.h"
#include "ControladorUsuario.h"
#include "ControladorInmueble.h"
#include "ControladorPublicacion.h"

class Factory {
    private:
        static Factory* instance;
        IControladorUsuario* controladorUsuario;
        IControladorInmueble* controladorInmueble;
        IControladorPublicacion* controladorPublicacion;
        Factory();

    public:
        static Factory* getInstance();
        static void liberarInstancia();
        IControladorFechaActual* getIControladorFechaActual();
        //TODO: Get interfaces de controladores
        IControladorUsuario* getIControladorUsuario();
        IControladorInmueble* getIControladorInmueble();
        IControladorPublicacion* getIControladorPublicacion();
        ~Factory();
};

#endif