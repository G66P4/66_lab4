#ifndef ICONTROLADORINMUEBLE_H
#define ICONTROLADORINMUEBLE_H
#include <string>
#include <set>
#include "DTInmueble.h"
#include "DTInmuebleListado.h"
#include "TipoTecho.h"
class IControladorInmueble
{
public:
 
    virtual bool altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo,std::string nicknamePropietario) = 0;
    virtual bool altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes,std::string nicknamePropietario) = 0;
    virtual DTInmueble* detalleInmueblePublicacion(int codigoInmueble) = 0;
    virtual std::set<DTInmuebleListado*> listarInmuebles() = 0;
    virtual DTInmueble* detalleInmueble(int codigoInmueble) = 0;
    virtual void altaAdministraPropiedad(int codigoInmueble, std::string nicknameInmobiliaria) = 0;
    virtual void eliminarInmueble(int codigoInmueble) = 0;
};

#endif