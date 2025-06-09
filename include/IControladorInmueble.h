#ifndef ICONTROLADORINMUEBLE_H
#define ICONTROLADORINMUEBLE_H
#include <string>
class IControladorInmueble
{
public:
    // harian falta estas funciones para cargar inmuebles en el sistema
    // virtual bool altaCasa() = 0;
    // virtual bool altaApartamento() = 0;
    // virtual DTInmueble* detalleInmueblePublicacion(int codigoPublicacion) = 0;
    // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
    // Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
    virtual void eliminarInmueble(int codigoInmueble) = 0;
};

#endif