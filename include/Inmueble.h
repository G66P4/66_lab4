#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>

class Inmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anoConstruccion;

    public:
        Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
        int getCodigo();
        std::string getDireccion();
        DTFecha* getFechaComienzo();
        ~Inmueble();
};

#endif