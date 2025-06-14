#ifndef IOBSERVER_H
#define IOBSERVER_H
#include "DTNotificacion.h"

class IObserver{
    public:
        virtual void Notificar(DTNotificacion* notificacion) = 0;
        virtual ~IObserver() {}
        virtual std::string getNicknameO() = 0; // Método para obtener el nickname del usuario
};

#endif