#ifndef CONTROLADORINMUEBLE_H
#define CONTROLADORINMUEBLE_H
#include "IControladorInmueble.h"
#include "Inmueble.h"
#include "ManejadorInmueble.h"
#include "TipoTecho.h"

class ControladorInmueble : public IControladorInmueble{
    private:
        static ControladorInmueble* instance;
        ControladorInmueble();
    public:
        bool altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo);
        bool altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes);
        static ControladorInmueble* getInstance();
        void eliminarInmueble(int codigoInmueble);
        ~ControladorInmueble();
};
#endif