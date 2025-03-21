#ifndef LIBRO
#define LIBRO
#include <iostream>
#include "Publicacion.h"
#include "DTFecha.h"

class Libro: public Publicacion{
    private:
        std::string editorial;
        std::set<std::string> palabrasDestacadas;
    public:
        Libro(std::string, std::string, DTFecha, std::string, std::set<std::string>);
        std::string getEditorial();
        std::set<std::string> getPalabrasDestacadas();
        virtual bool contienePalabra(std::string);
};

#endif
