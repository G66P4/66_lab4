#ifndef CONTROLADORINMUEBLE_H
#define CONTROLADORINMUEBLE_H
#include "Casa.h"
#include "IControladorInmueble.h"
#include "Inmueble.h"
#include "ManejadorInmueble.h"
#include "TipoTecho.h"
#include "DTInmueble.h"
#include "DTInmuebleListado.h"
#include "ManejadorUsuario.h"

class ControladorInmueble : public IControladorInmueble{
    private:
        static ControladorInmueble* instance;
        ControladorInmueble();
    public:
        static ControladorInmueble* getInstance();
        void eliminarInmueble(int codigoInmueble);
        bool altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo, std::string nicknamePropietario);
        bool altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes, std::string nicknamePropietario);
        DTInmueble* detalleInmueblePublicacion(int codigoPublicacion);
        DTInmueble* detalleInmueble(int codigoInmueble);
        std::set<DTInmuebleListado*> listarInmuebles();
        std::set<DTInmuebleListado*> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria) ;
        void altaAdministraPropiedad(int codigoInmueble, std::string nicknameInmobiliaria);
        ~ControladorInmueble();
};
#endif