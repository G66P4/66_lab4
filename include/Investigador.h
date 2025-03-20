#ifndef INVESTIGADOR_H
#define INVESTIGADOR_H

#include <string>
#include <vector>
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
    vector<Publicacion *> esAutor;

public:
    Investigador(string ORCID, string nombre, string institucion);
    string getORCID();
    string getNombre();
    string getInstitucion();
    void setEsAutor(Publicacion *p);
    string toString() const;
    set<string> listarPublicaciones(DTFecha desde, string palabra);
};

#endif