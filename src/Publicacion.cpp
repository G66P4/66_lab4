#include "../include/DTRefer.h"
#include "../include/Investigador.h"
#include "../include/DTFecha.h"
#include <iostream>
#include <string>
#include <set>  

class Investigador;

class Publicacion {
private:
    std::string DOI;
    std::string titulo;
    DTFecha fecha;
    std::set<Investigador*> investigadores;

public:
    Publicacion(std::string doi, std::string tit, DTFecha f);
    virtual ~Publicacion(); 
    std::string getDOI() const;   
    std::string getTitulo() const;   
    DTFecha getFecha() const;
    DTRefer getDT();
    virtual bool contienePalabra(std::string palabra) = 0;
    void agregarAutor(Investigador* autor);
};

// constructor
Publicacion::Publicacion(std::string doi, std::string tit, DTFecha f) {
    this->DOI = doi;
    this->titulo = tit;
    this->fecha = f;
}

// destructor
Publicacion::~Publicacion() {
    for (std::set<Investigador*>::iterator it = investigadores.begin(); it != investigadores.end(); ++it) {
        (*it)->noAutor(this);  
    }
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
    
    for (std::set<Investigador*>::iterator it = investigadores.begin();
         it != investigadores.end(); ++it) {
        nombresAutores.insert((*it)->getNombre());
    }
    
    return DTRefer(DOI, titulo, fecha, nombresAutores);
}

void Publicacion::agregarAutor(Investigador* autor) {
    investigadores.insert(autor);
}
