#include <string>
#includE "Investigador.h"
using namespace std;
/*
class Investigador
{
private:
    string ORCID;
    string nombre;
    string institucion;
*/

Investigador::Investigador(string ORCID, string nombre, string institucion))
{
    this->ORCID = ORCID;
    this->nombre = nombre;
    this->institucion = institucion;
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

string Investigador::toString()
{
    return ORCID + "->" + nombre + "/" + institucion;
}