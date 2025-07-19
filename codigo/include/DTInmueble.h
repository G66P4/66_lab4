#ifndef DTINMUEBLE_H
#define DTINMUEBLE_H
#include <string>

class DTInmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anioConstruccion;

    public:
        DTInmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion);
        int getCodigo();
        std::string getDireccion();
        int getNumeroPuerta();
        int getSuperficie();
        int getAnioConstruccion();
        virtual ~DTInmueble();
};

#endif