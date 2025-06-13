#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/ControladorInmueble.h"
#include "../include/ManejadorInmueble.h"
#include "../include/Inmueble.h"
#include "../include/DTCasa.h"
#include "../include/DTApartamento.h"
#include "../include/ManejadorPublicacion.h"
#include "../include/Inmobiliaria.h"
#include "../include/ControladorFechaActual.h"

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

DTInmueble* ControladorInmueble::detalleInmueblePublicacion(int codigoPublicacion){
    if(ManejadorPublicacion::getInstancia()->existe(codigoPublicacion)){
        Publicacion* pub = ManejadorPublicacion::getInstancia()->find(codigoPublicacion);
        AdministraPropiedad* adminprop = pub->getAdminProp();
        Inmueble* inmu = adminprop->getInmueble();
        TipoInmueble tipo = inmu->consultarTipo();
        if(tipo == apartamento){
            Apartamento* apto = dynamic_cast<Apartamento*>(inmu);
            return new DTApartamento(apto->getCodigo(), apto->getDireccion(), apto->getNumeroPuerta(), apto->getSuperficie(), apto->getAnoConstruccion(), apto->getPiso(), apto->getTieneAscensor(), apto->getGastosComunes());
        } else if(tipo == casa){
            Casa* cas = dynamic_cast<Casa*>(inmu);
            return new DTCasa(cas->getCodigo(), cas->getDireccion(), cas->getNumeroPuerta(), cas->getSuperficie(), cas->getAnoConstruccion(), cas->getEsPH(), cas->getTecho());
        }
    }
    return NULL;
}

DTInmueble* ControladorInmueble::detalleInmueble(int codigoInmueble){
    if(ManejadorInmueble::getInstance()->existeInmueble(codigoInmueble)){
        Inmueble* inm = ManejadorInmueble::getInstance()->findInmueble(codigoInmueble);
        TipoInmueble tipo = inm->consultarTipo();
        if(tipo == apartamento){
            Apartamento* apto = dynamic_cast<Apartamento*>(inm);

            return new DTApartamento(apto->getCodigo(), apto->getDireccion(), apto->getNumeroPuerta(), apto->getSuperficie(), apto->getAnoConstruccion(), apto->getPiso(), apto->getTieneAscensor(), apto->getGastosComunes());
        } else if(tipo == casa){
            Casa* cas = dynamic_cast<Casa*>(inm);
            return new DTCasa(cas->getCodigo(), cas->getDireccion(), cas->getNumeroPuerta(), cas->getSuperficie(), cas->getAnoConstruccion(), cas->getEsPH(), cas->getTecho());
        }
    }
    return NULL;
}

std::set<DTInmuebleListado*> ControladorInmueble::listarInmuebles(){
    std::set<DTInmuebleListado*> inmueblesListados;
    std::map<int, Inmueble*>& inmuebles = ManejadorInmueble::getInstance()->getInmuebles();
    std::map<int, Inmueble*>::iterator it;
    for(it = inmuebles.begin(); it != inmuebles.end(); ++it) {
        Inmueble* inmueble = it->second;
        int codigo = inmueble->getCodigo();
        std::string direccion = inmueble->getDireccion();
        std::list<Propietario*> listapropietarios=ManejadorUsuario::getInstance()->getPropietarios();
        std::list<Propietario*>::iterator itprop = listapropietarios.begin();
        bool propietarioEncontrado = false;
        Propietario* propietario =NULL;
        while(itprop != listapropietarios.end() && !propietarioEncontrado){
            propietario = *itprop;
            propietarioEncontrado=propietario->esPropietario(codigo);
            ++itprop;
        }
        if(!propietarioEncontrado){
            throw std::runtime_error("Propietario no encontrado para el inmueble con codigo: " + std::to_string(codigo));
        }
        std::string propietarionick = propietario->getNickname(); 
        DTInmuebleListado* dtInmuebleListado = new DTInmuebleListado(codigo, direccion, propietarionick);
        inmueblesListados.insert(dtInmuebleListado);

    }
    
    return inmueblesListados;
}

std::set<DTInmuebleListado*> ControladorInmueble::listarInmueblesNoAdministradosInmobiliaria(std::string nicknameInmobiliaria){
    ManejadorUsuario* m = ManejadorUsuario::getInstance();
    Inmobiliaria* ci = m->findInmobiliaria(nicknameInmobiliaria);
    std::set<DTInmuebleListado*> listinmuebles=ci->getinmueblesNoAdminPropietario();
    return listinmuebles;
    
}

void ControladorInmueble::altaAdministraPropiedad(int codigoInmueble, std::string nicknameInmobiliaria) {
    ManejadorUsuario* m = ManejadorUsuario::getInstance();
    Inmobiliaria* ci = m->findInmobiliaria(nicknameInmobiliaria);
    ManejadorInmueble* mi = ManejadorInmueble::getInstance();
    Inmueble* cin = mi->findInmueble(codigoInmueble);
    if (ci == NULL || cin == NULL) {
        throw std::runtime_error("Inmobiliaria o inmueble no encontrado");
    }
    DTFecha* fechaAactual = ControladorFechaActual::getInstance()->getFechaActual();
    ci->altaAdministracionPropiedad(cin,fechaAactual);
}

ControladorInmueble::~ControladorInmueble() {}
