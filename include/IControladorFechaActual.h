#ifndef ICONTROLADORFECHAACTUAL_H
#define ICONTROLADORFECHAACTUAL_H

#include "DTFecha.h"

class IControladorFechaActual {
    public:
        virtual DTFecha* getFechaActual() = 0;
        virtual void setNewFechaActual(int dia, int mes, int anio) = 0;
};

#endif