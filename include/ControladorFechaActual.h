#ifndef CONTROLADORFECHAACTUAL_H
#define CONTROLADORFECHAACTUAL_H

#include "DTFecha.h"
#include "IControladorFechaActual.h"

class ControladorFechaActual : public IControladorFechaActual  {
    private:
        static ControladorFechaActual* instance;
        DTFecha* fechaActual;
        ControladorFechaActual();

    public:
        static ControladorFechaActual* getInstance();
        DTFecha* getFechaActual();
        void setNewFechaActual(int dia, int mes, int anio);
        ~ControladorFechaActual();
};

#endif