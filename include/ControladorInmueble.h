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
        ~ControladorInmueble();
        
        bool altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo, std::string nicknamePropietario);
        bool altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes, std::string nicknamePropietario);
        DTInmueble* detalleInmueblePublicacion(int codigoInmueble);
        // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
        //Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
        std::set<DTInmuebleListado*> listarInmuebles();
        DTInmueble* detalleInmueble(int codigoInmueble);
        // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
        // Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
        std::set<DTInmuebleListado*> listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria) ;
        void altaAdministraPropiedad(int codigoInmueble, std::string nicknameInmobiliaria);
    
};
#endif