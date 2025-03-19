#ifndef PUBLICACION
#define PUBLICACION 
#include <iostream>
#include "DTRefer.h"
#include "DTFecha.h"
class Publicacion {
    private:
        std::string DOI;
        std::string titulo;
        DTFecha fecha;
    
    public:
        Publicacion(std::string doi, std::string tit, DTFecha f);
        ~Publicacion(); 
        std::string getDOI() const;   
        std::string getTitulo() const;   
        DTFecha getFecha() const;
        DTRefer getDT();
        virtual bool contienePalabra(std::string palabra) = 0;
    };

    #endif