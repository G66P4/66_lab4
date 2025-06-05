#include "../include/ManejadorInmueble.h"

ManejadorInmueble* ManejadorInmueble::instance = NULL;

ManejadorInmueble::ManejadorInmueble() {}

ManejadorInmueble* ManejadorInmueble::getInstance() {
    if (instance == NULL) {
        instance = new ManejadorInmueble();
    }
    return instance;
}

void ManejadorInmueble::liberarInstancia(){
    if (instance != NULL) {
        delete instance;     
        instance = NULL;     
    }
}

void ManejadorInmueble::agregarInmueble(Inmueble* inmueble) {
    inmuebles[inmueble->getCodigo()] = inmueble;
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

ManejadorInmueble::~ManejadorInmueble(){
    std::map<int, Inmueble*>::iterator it = inmuebles.begin();
    while (it != inmuebles.end()) {
        delete it->second;
        it=inmuebles.erase(it);
    }
}