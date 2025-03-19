#ifndef DTREFER
#define DTREFER 
#include <iostream>
#include <set> 
#include "DTFecha.h"

class DTRefer {
	private:
		    std::string DOI;
    		std::string Titulo;
    		DTFecha Fecha;
    		std::set<std::string> Autores;
    	public:
    		DTRefer(std::string, std::string ,DTFecha ,std::set<std::string>);
    		friend std::ostream &operator<<(std::ostream &, DTRefer&);
};

#endif