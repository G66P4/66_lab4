#ifndef PUBLICACION
#define PUBLICACION 
#include <iostream>
#include "../include/DTRefer.h"
#include "../include/DTFecha.h"
#include "../include/Investigador.h"
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

    #endif