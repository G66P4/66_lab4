#include "../include/DTRefer.h"

//constructor
DTRefer::DTRefer(std::string doi, std::string titulo, DTFecha fecha,std::set<std::string> autores){
	this->DOI=doi;
	this->Titulo=titulo;
	this->Fecha=fecha;
	this->Autores=autores;

}

std::ostream &operator<<(std::ostream &o, const DTRefer &refer) {
	o << refer.DOI << "->" << refer.Titulo << "(" << refer.Fecha.get_dia() << "/" <<refer.Fecha.get_mes() << "/" <<refer.Fecha.get_anio() << ")/";
	
	std::set<std::string>::const_iterator inicio= refer.Autores.begin();
	std::set<std::string>::const_iterator  final= refer.Autores.end();
    
	if(inicio!=final){
		o << *inicio ;
		inicio++;
	}
	
	while(inicio!=final){
		o << ", " << *inicio;
		inicio++;
	}
	return o;
}

