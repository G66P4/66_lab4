#ifndef ICONTROLADORINMUEBLE_H
#define ICONTROLADORINMUEBLE_H
#include <string>
#include <set>
#include "DTInmueble.h"
#include "DTInmuebleListado.h"
class IControladorInmueble
{
public:
 
    virtual bool altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo) = 0;
    virtual bool altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes) = 0;
    virtual DTInmueble* detalleInmueblePublicacion(int codigoInmueble) = 0;
    // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
    // Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
    virtual std::set<DTInmuebleListado*> listarInmuebles() = 0;
    virtual DTInmueble* detalleInmueble(int codigoInmueble) = 0;
    // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
    // Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
    virtual std::set<DTInmuebleListado*> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria) = 0;
    virtual void altaAdministraPropiedad(int codigoInmueble, std::string nicknameInmobiliaria) = 0;
    virtual void eliminarInmueble(int codigoInmueble) = 0;
};

#endif