#include "../include/DTFecha.h"
#include <sstream>
#include <iostream>
#include <ctime>


DTFecha::DTFecha(int dia, int mes, int anio) {
    this->anio = anio;
    this->mes = mes;
    this->dia = dia;
}

DTFecha::DTFecha(DTFecha* fecha){
    this->anio = fecha->anio;
    this->mes = fecha->mes;
    this->dia = fecha->dia;
}

bool DTFecha::operator>=(DTFecha* fecha) {
    return (
        this->anio > fecha->anio || 
        (this->anio == fecha->anio && this->mes > fecha->mes) ||
        (this->anio == fecha->anio && this->mes == fecha->mes && this->dia >= fecha->dia)
    );
}


bool DTFecha::operator<(DTFecha* fecha) {
    if (fecha == NULL) return false;
    if (this->anio != fecha->anio) return this->anio < fecha->anio;
    if (this->mes != fecha->mes) return this->mes < fecha->mes;
    return this->dia < fecha->dia;
}

bool DTFecha::operator<(DTFecha fecha) {
    if (fecha == NULL) return false;
    if (this->anio != fecha.anio) return this->anio < fecha.anio;
    if (this->mes != fecha.mes) return this->mes < fecha.mes;
    return this->dia < fecha.dia;
}

bool DTFecha::operator==(DTFecha* fecha) {
    if (fecha == NULL) return false;
    return this->anio == fecha->anio && 
            this->mes == fecha->mes && 
            this->dia == fecha->dia;
}

bool DTFecha::operator==(DTFecha fecha) {
    return this->anio == fecha.anio && 
            this->mes == fecha.mes && 
            this->dia == fecha.dia;
}

std::string DTFecha::toString(){
    std::stringstream ss;
    ss << this->dia << "/" << this->mes << "/" << this->anio;
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, DTFecha* fecha) {
    os << fecha->toString();
    return os;
}

DTFecha* DTFecha::obtenerFechaActual() {
    time_t tiempoActual = time(nullptr);
    tm* fechaLocal = localtime(&tiempoActual);

    int dia = fechaLocal->tm_mday;
    int mes = fechaLocal->tm_mon + 1;
    int anio = fechaLocal->tm_year + 1900;

    return new DTFecha(dia, mes, anio);
}