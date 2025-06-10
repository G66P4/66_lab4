#ifndef IOBSERVER_H
#define IOBSERVER_H

class IObserver{
    public:
        virtual void Notificar(DTNotificacion notificacion) = 0;
};

#endif