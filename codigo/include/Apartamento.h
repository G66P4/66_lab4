#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Inmueble.h"
#include <string>

class Apartamento : public Inmueble {
private:
    int piso;
    bool tieneAscensor;
    float gastosComunes;

public:
    Apartamento(int codigo, std::string direccion, int numeroPuerta, int superficie,
    int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes);

    ~Apartamento();
    TipoInmueble consultarTipo();
    // Getters
    int getPiso() const;
    bool getTieneAscensor() const;
    float getGastosComunes() const;

};

#endif