#include <iostream>
#include "../include/DTFecha.h"
//constructor
DTFecha::DTFecha(){

};

DTFecha::DTFecha(int d, int m, int a) {
    this->dia = d;
    this->mes = m;
    this->anio = a;
};
//destructor
DTFecha::~DTFecha() {
};
//geters
int DTFecha::get_dia() const {
    return this->dia;
};

int DTFecha::get_mes() const {
    return this->mes;
};

int DTFecha::get_anio() const {
    return this->anio;
};

bool DTFecha::operator> (DTFecha fecha) {
    if (this->anio > fecha.get_anio()) {
        return true;
    } else if (this->anio == fecha.get_anio()) {
        if (this->mes > fecha.get_mes()) {
            return true;
        } else if (this->mes == fecha.get_mes()) {
            if (this->dia > fecha.get_dia()) {
                return true;
            }
        }
    }
    return false;
};

bool DTFecha::operator< (DTFecha fecha) {
    if (this->anio < fecha.get_anio()) {
        return true;
    } else if (this->anio == fecha.get_anio()) {
        if (this->mes < fecha.get_mes()) {
            return true;
        } else if (this->mes == fecha.get_mes()) {
            if (this->dia < fecha.get_dia()) {
                return true;
            }
        }
    }
    return false;
};

bool DTFecha::operator== (DTFecha fecha) {
    if (this->anio == fecha.get_anio() && this->mes == fecha.get_mes() && this->dia == fecha.get_dia()) {
        return true;
    }
    return false;
};

bool DTFecha::operator!= (DTFecha fecha) {
    if (this->anio != fecha.get_anio() || this->mes != fecha.get_mes() || this->dia != fecha.get_dia()) {
        return true;
    }
    return false;
};

bool DTFecha::operator>= (DTFecha fecha) {
    if (this->anio > fecha.get_anio()) {
        return true;
    } else if (this->anio == fecha.get_anio()) {
        if (this->mes > fecha.get_mes()) {
            return true;
        } else if (this->mes == fecha.get_mes()) {
            if (this->dia >= fecha.get_dia()) {
                return true;
            }
        }
    }
    return false;
};

bool DTFecha::operator<= (DTFecha fecha) {
    if (this->anio < fecha.get_anio()) {
        return true;
    } else if (this->anio == fecha.get_anio()) {
        if (this->mes < fecha.get_mes()) {
            return true;
        } else if (this->mes == fecha.get_mes()) {
            if (this->dia <= fecha.get_dia()) {
                return true;
            }
        }
    }
    return false;
};


