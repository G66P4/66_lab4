#include "../include/DTInmuebleListado.h"

DTInmuebleListado::DTInmuebleListado(int codigo, std::string direccion, std::string propietario)
{
    this->codigo = codigo;
    this->direccion = direccion;
    this->propietario = propietario;
}

int DTInmuebleListado::getCodigo()
{
    return codigo;
}

bool DTInmuebleListado::operator<(DTInmuebleListado *DT)
{
    if (DT == NULL)
        return false;
    if (this->codigo < DT->codigo)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string DTInmuebleListado::getDireccion()
{
    return direccion;
}

std::string DTInmuebleListado::getPropietario()
{
    return propietario;
}