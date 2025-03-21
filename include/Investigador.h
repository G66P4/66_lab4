#ifndef INVESTIGADOR_H
#define INVESTIGADOR_H

#include <string>
#include <list>
#include <set>

using namespace std;

class Publicacion;
class DTFecha;
class Investigador
{

private:
    string ORCID;
    string nombre;
    string institucion;
    list<Publicacion*> esAutor;

public:
    Investigador(string ORCID, string nombre, string institucion);
    string getORCID();
    string getNombre();
    string getInstitucion();
    void autor(Publicacion *p);
    void noAutor(Publicacion *p);
    string toString() const;
    set<string> listarPublicaciones(DTFecha desde, string palabra);
};

#endif