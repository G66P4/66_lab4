#include "../include/ManejadorPublicacion.h"
#include "../include/TipoPublicacion.h"
ManejadorPublicacion* ManejadorPublicacion::instancia = NULL;

ManejadorPublicacion::ManejadorPublicacion() {}
int ManejadorPublicacion::ultimoCodigoPub = 0;
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

std::map<int, Publicacion*> ManejadorPublicacion::getPublicacionesActivas() const {
    std::map<int, Publicacion*> activas;
    std::map<int, Publicacion*>::const_iterator it;

    for (it = publicaciones.begin(); it != publicaciones.end(); ++it) {
        if (it->second->estaActiva()) {
            activas[it->first] = it->second;
        }
    }

    return activas;
}

std::map<int, Publicacion*> ManejadorPublicacion::getPublicacionesVenta() const {
    std::map<int, Publicacion*> ventas;
    std::map<int, Publicacion*>::const_iterator it;

    for (it = publicaciones.begin(); it != publicaciones.end(); ++it) {
        if (it->second->getTipo() == TipoPublicacion::Venta) {
            ventas[it->first] = it->second;
        }
    }

    return ventas;
}

std::map<int, Publicacion*> ManejadorPublicacion::getPublicacionesAlquiler() const {
    std::map<int, Publicacion*> alquileres;
    std::map<int, Publicacion*>::const_iterator it;

    for (it = publicaciones.begin(); it != publicaciones.end(); ++it) {
        if (it->second->getTipo() == TipoPublicacion::Alquiler) {
            alquileres[it->first] = it->second;
        }
    }

    return alquileres;
}

ManejadorPublicacion::~ManejadorPublicacion() {
    std::map<int, Publicacion*>::iterator it;
    for (it = publicaciones.begin(); it != publicaciones.end(); ++it) {
        delete it->second;
    }
    publicaciones.clear();
}

int ManejadorPublicacion::generarNuevoCodigo() {
    return ++ultimoCodigoPub;
}
