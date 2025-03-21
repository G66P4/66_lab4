#include "../include/ArticuloRevista.h"
#include <iostream>

//constructor
ArticuloRevista::ArticuloRevista(std::string doi, std::string tit, DTFecha f,std::string revista, std::string extracto):Publicacion(doi, tit, f){
    this->revista = revista;
    this->extracto = extracto;
};

//destructor
ArticuloRevista::~ArticuloRevista(){
};

//getters
std::string ArticuloRevista::getRevista(){
    return revista;
}
std::string ArticuloRevista::getExtracto(){
    return extracto;
}

bool ArticuloRevista:: contienePalabra(std::string palabra){
    bool b = extracto.find(palabra) != std::string::npos;
    return b;
};
