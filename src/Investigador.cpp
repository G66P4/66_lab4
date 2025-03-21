#include "../include/Investigador.h"
#include "../include/Publicacion.h"
#include "../include/DTFecha.h"

Investigador::Investigador(string ORCID, string nombre, string institucion)
{
    this->ORCID = ORCID;
    this->nombre = nombre;
    this->institucion = institucion;
}

Investigador::~Investigador()
{
    esAutor.clear();
}
string Investigador::getORCID()
{
    return ORCID;
}

string Investigador::getNombre()
{
    return nombre;
}

string Investigador::getInstitucion()
{
    return institucion;
}

void Investigador::autor(Publicacion *p)
{
    esAutor.push_back(p);
}

void Investigador::noAutor(Publicacion *p)
{   
    esAutor.remove(p);
}

string Investigador::toString() const
{
    return ORCID + "->" + nombre + "/" + institucion;
}

set<string> Investigador::listarPublicaciones(DTFecha desde, string palabra)
{
    set<string> publicaciones;
    
    for (list<Publicacion*>::iterator it = esAutor.begin(); it != esAutor.end(); ++it){
        if ((*it)->getFecha() > desde && (*it)->contienePalabra(palabra))
        {
            publicaciones.insert((*it)->getDOI());
        }
    }
    return publicaciones;
}