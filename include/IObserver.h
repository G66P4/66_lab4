#ifndef IOBSERVER_H
#define IOBSERVER_H
#include "DTNotificacion.h"

class Inmobiliaria;

class IObserver{
    public:
        virtual void Notificar(DTNotificacion* notificacion) = 0;
        virtual ~IObserver() {}
        virtual std::string getNicknameO() = 0; 
        virtual void agregarSuscripcion(Inmobiliaria* inmobiliaria) = 0; 
        virtual void eliminarSuscripcion(Inmobiliaria* inmobiliaria) = 0; 
        virtual void eliminarNotificaciones(std::string NickInmo) = 0;
};

#endif