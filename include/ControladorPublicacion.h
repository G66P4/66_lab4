#ifndef CONTROLADORPUBLICACION_H
#define CONTROLADORPUBLICACION_H
#include <set>
#include <string>
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "IControladorPublicacion.h"

class ControladorPublicacion: public IControladorPublicacion {
private:    
    static ControladorPublicacion* instance;
    ControladorPublicacion();
public:
    static ControladorPublicacion* getInstance();
    void borrarInstance();
    ~ControladorPublicacion();
    std::set<DTPublicacion*> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble);
    bool altaPublicacion(std::string nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, std::string texto, float precio);
};
#endif