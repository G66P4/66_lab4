#include "../include/ManejadorPublicacion.h"

ManejadorPublicacion* ManejadorPublicacion::instancia = NULL;

ManejadorPublicacion::ManejadorPublicacion() {}

ManejadorPublicacion* ManejadorPublicacion::getInstancia() {
    if (instancia == NULL)
        instancia = new ManejadorPublicacion();
    return instancia;
}

void ManejadorPublicacion::agregarPublicacion(Publicacion* pub) {
    int codigo = pub->getCodigo();
    publicaciones[codigo] = pub;
}

Publicacion* ManejadorPublicacion::find(int codigo) {
    std::map<int, Publicacion*>::iterator it = publicaciones.find(codigo);
    if (it != publicaciones.end())
        return it->second;
    return NULL;
}

bool ManejadorPublicacion::existe(int codigo) const {
    std::map<int, Publicacion*>::const_iterator it = publicaciones.find(codigo);
    return it != publicaciones.end();
}

std::map<int, Publicacion*> ManejadorPublicacion::getPublicaciones() const {
    return publicaciones;
}

void ManejadorPublicacion::eliminarPublicacion(int codigo) {
    std::map<int, Publicacion*>::iterator it = publicaciones.find(codigo);
    if (it != publicaciones.end()) {
        delete it->second;
        publicaciones.erase(it);
    }
}

ManejadorPublicacion::~ManejadorPublicacion() {
    std::map<int, Publicacion*>::iterator it;
    for (it = publicaciones.begin(); it != publicaciones.end(); ++it) {
        delete it->second;
    }
    publicaciones.clear();
}