#include "../include/PaginaWeb.h"
#include <iostream>


//constructor
PaginaWeb::PaginaWeb(std::string doi,std::string tit, DTFecha f,std::string url,std::string contenidoExtraido):Publicacion(doi,tit,f){
	this->url=url;
	this->contenidoExtraido=contenidoExtraido;
}

//getters
std::string PaginaWeb::getUrl(){
	return url;
}

std::string PaginaWeb::getContenidoExtraido(){
	return contenidoExtraido;
}

bool PaginaWeb::contienePalabra(std::string palabra){
	return contenidoExtraido.find(palabra) != std::string::npos;
}