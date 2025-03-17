#ifndef PAGINAWEB
#define PAGINAWEB 
#include <iostream>
#include "Publicacion.h"
#include "DTFecha.h"
class PaginaWeb: public Publicacion{
	private:
		std::string url;
		std::string contenidoExtraido;
	public:
		PaginaWeb(std::string,std::string,DTFecha,std::string,std::string);
		std::string getUrl();
		std::string getContenidoExtraido();
		bool contienePalabra(std::string);
};

#endif
