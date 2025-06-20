#include "../include/ManejadorInmueble.h"
ManejadorInmueble* ManejadorInmueble::instance = NULL;

ManejadorInmueble::ManejadorInmueble() {}

int ManejadorInmueble::ultimoCodigo = 0;

ManejadorInmueble* ManejadorInmueble::getInstance() {
    if (instance == NULL) {
        instance = new ManejadorInmueble();
    }
    return instance;
}

void ManejadorInmueble::liberarInstancia(){
    if (instance != NULL) {
           
        instance = NULL;     
    }
}

int ManejadorInmueble::generarNuevoCodigo() {
    return ++ultimoCodigo;
}

void ManejadorInmueble::agregarInmueble(Inmueble* inmueble) {
    if(inmueble != NULL) {
        int codigo = inmueble->getCodigo();
        inmuebles[codigo] = inmueble;
    }
}

void ManejadorInmueble::eliminarInmueble(int codigo) {
    Inmueble* inmueble =findInmueble(codigo);
    if(inmueble!=NULL){
        delete inmueble;
        inmuebles.erase(codigo);
    }
    
}

bool ManejadorInmueble::existeInmueble(const int codigo){
    return findInmueble(codigo) != NULL;
}

Inmueble* ManejadorInmueble::findInmueble(const int codigo){
    std::map<int, Inmueble*>::iterator it = inmuebles.find(codigo);
    if(it != inmuebles.end()){
        return it->second;
    }

    return NULL;
}

std::map<int, Inmueble*>& ManejadorInmueble::getInmuebles() {
    return inmuebles;
}

ManejadorInmueble::~ManejadorInmueble(){
    std::map<int, Inmueble*>::iterator it = inmuebles.begin();
    while (it != inmuebles.end()) {
        it->second->~Inmueble();
        it++;
    }
    inmuebles.clear();
    delete instance;
}