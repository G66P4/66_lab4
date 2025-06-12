#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/ControladorInmueble.h"
#include "../include/ManejadorInmueble.h"

ControladorInmueble* ControladorInmueble::instance = NULL;

ControladorInmueble::ControladorInmueble() {}

ControladorInmueble* ControladorInmueble::getInstance() {
    if (instance == NULL) {
        instance = new ControladorInmueble();
    }
    return instance;
}

bool ControladorInmueble::altaCasa(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo, std::string nicknamePropietario) {
        int codigo = ManejadorInmueble::getInstance()->generarNuevoCodigo();
        Casa* cas = new Casa(codigo, direccion, numeroPuerta, superficie, anoConstruccion, esPH,techo);
        ManejadorInmueble::getInstance()->agregarInmueble(cas);
        ManejadorUsuario::getInstance()->findPropietario(nicknamePropietario)->asociarInmueble(cas);
        return true; 
    
}

bool ControladorInmueble::altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes, std::string nicknamePropietario) {
    int codigo = ManejadorInmueble::getInstance()->generarNuevoCodigo();
    Apartamento* apto = new Apartamento(codigo, direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
    ManejadorInmueble::getInstance()->agregarInmueble(apto);
    ManejadorUsuario::getInstance()->findPropietario(nicknamePropietario)->asociarInmueble(apto);
    return true;
}

void ControladorInmueble::eliminarInmueble(int codigoInmueble){
    if(ManejadorInmueble::getInstance()->existeInmueble(codigoInmueble)){
        Inmueble* inm = ManejadorInmueble::getInstance()->findInmueble(codigoInmueble);
        inm->eliminarLinksInmueble(codigoInmueble);
        ManejadorInmueble::getInstance()->eliminarInmueble(codigoInmueble);
        inm->~Inmueble();
    }
}