#ifndef DTINMUEBLELISTADO_H
#define DTINMUEBLELISTADO_H
#include <string>

class DTInmuebleListado {
    private:
        int codigo;
        std::string direccion;
        std::string propietario;

    public:
        DTInmuebleListado(int codigo, std::string direccion, std::string propietario);
        int getCodigo();
        std::string getDireccion();
        std::string getPropietario();
};

#endif