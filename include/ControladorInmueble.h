#ifndef CONTROLADORINMUEBLE_H
#define CONTROLADORINMUEBLE_H
#include "IControladorInmueble.h"
#include "Inmueble.h"
#include "ManejadorInmueble.h"

class ControladorInmueble : public IControladorInmueble{
    private:
        static ControladorInmueble* instance;
        ControladorInmueble();
    public:
        static ControladorInmueble* getInstance();
        void eliminarInmueble(int codigoInmueble);
        ~ControladorInmueble();
};
#endif