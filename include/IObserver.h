#ifndef IOBSERVER_H
#define IOBSERVER_H
#include "DTNotificacion.h"

class IObserver{
    public:
        virtual void Notificar(DTNotificacion* notificacion) = 0;
};

#endif