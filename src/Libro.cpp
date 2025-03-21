#include "../include/Libro.h"
#include <iostream>
#include <set>

//constructor
Libro::Libro(std::string doi, std::string tit, DTFecha f, std::string editorial, std::set<std::string> palabrasDestacadas):Publicacion(doi, tit, f){
    this->editorial = editorial;
    this->palabrasDestacadas = palabrasDestacadas;
};

//destructor
Libro::~Libro(){    
};

//getters
std::string Libro::getEditorial(){
    return editorial;
};
std::set<std::string> Libro::getPalabrasDestacadas(){
    return palabrasDestacadas;
};

bool Libro::contienePalabra(std::string palabra){
    bool b= palabrasDestacadas.find(palabra) != palabrasDestacadas.end();
    return b;
};
