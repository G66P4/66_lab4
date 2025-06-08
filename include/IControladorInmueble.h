#ifndef ICONTROLADORINMUEBLE_H
#define ICONTROLADORINMUEBLE_H
#include <string>
class IControladorInmueble
{
public:
    // aria falta esta funcion para cargar inmuebles en el sistema
    // virtual bool altaInmueble() = 0;
    virtual void eliminarInmueble(int codigoInmueble) = 0;
};

#endif