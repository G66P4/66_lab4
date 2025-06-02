#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Inmueble.h"


class Apartamento : public Inmueble {
    private:
        int piso;
        bool tieneAscensor;
        float gastosComunes;

    public:
        Apartamento(int piso, bool tieneAscensor, float gastosComunes);
        ~Apartamento();
};

#endif