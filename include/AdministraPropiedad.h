#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include "DTFecha.h"

class AdministraPropiedad {
    private:
        DTFecha* fecha;

    public:
        AdministraPropiedad(DTFecha* fecha);
        ~AdministraPropiedad();
};

#endif