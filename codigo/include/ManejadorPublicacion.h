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
    static int ultimoCodigoPub;
public:
    static ManejadorPublicacion* getInstancia();
    static void liberarInstancia();

    void agregarPublicacion(Publicacion* pub);
    Publicacion* find(int codigo);
    std::map<int, Publicacion*> getPublicaciones() const;
    void eliminarPublicacion(int codigo);
    bool existe(int codigo) const;
    int generarNuevoCodigo();
    std::map<int, Publicacion*> getPublicacionesActivas() const;
    std::map<int, Publicacion*> getPublicacionesVenta() const;
    std::map<int, Publicacion*> getPublicacionesAlquiler() const;
    ~ManejadorPublicacion();
};

#endif