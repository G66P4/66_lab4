#ifndef MANEJADORPUBLICACION_H
#define MANEJADORPUBLICACION_H

#include <map>
#include "Publicacion.h"

class ManejadorPublicacion {
private:
    std::map<int, Publicacion*> publicaciones;

    // singleton
    static ManejadorPublicacion* instancia;
    ManejadorPublicacion();

public:
    static ManejadorPublicacion* getInstancia();

    void agregarPublicacion(Publicacion* pub);
    Publicacion* find(int codigo);
    std::map<int, Publicacion*> getPublicaciones() const;
    void eliminarPublicacion(int codigo);
    bool existe(int codigo) const;
    
    ~ManejadorPublicacion();
};

#endif