#ifndef ARTICULOREVISTA
#define ARTICULOREVISTA
#include <iostream>
#include "Publicacion.h"
#include "DTFecha.h"

class ArticuloRevista: public Publicacion{
    private:
        std::string revista;
        std::string extracto; 
    public:
        ArticuloRevista(std::string, std::string, DTFecha, std::string, std::string);
        std::string getRevista();
        std::string getExtracto();
        virtual bool contienePalabra(std::string);
};

#endif
