#include "DTRefer.h"
#include "Investigador.h"
#include "DTFecha.h"
#include <iostream>
#include <string>
#include <set>  


class Publicacion {
private:
    std::string DOI;
    std::string titulo;
    DTFecha fecha;
    std::set<Investigador*> investigadores;

public:
    Publicacion(std::string doi, std::string tit, DTFecha f);
    ~Publicacion(); 
    std::string getDOI() const;   
    std::string getTitulo() const;   
    DTFecha getFecha() const;
    DTRefer getDT();
    virtual bool contienePalabra(std::string palabra) = 0;
};

// constructor
Publicacion::Publicacion(std::string doi, std::string tit, DTFecha f) {
    this->DOI = doi;
    this->titulo = tit;
    this->fecha = f;
}

// destructor
Publicacion::~Publicacion() {
}

// getters
std::string Publicacion::getDOI() const {
    return DOI;
}

std::string Publicacion::getTitulo() const {
    return titulo;
}

DTFecha Publicacion::getFecha() const {
    return fecha;
}

DTRefer Publicacion::getDT() {
    std::set<std::string> nombresAutores;
    
    // Recorremos el set de investigadores y obtenemos sus nombres
    for (std::set<Investigador*>::iterator it = investigadores.begin();
         it != investigadores.end(); ++it) {
        nombresAutores.insert((*it)->get_Nombre());
    }
    
    return DTRefer(DOI, titulo, fecha, nombresAutores);
}
