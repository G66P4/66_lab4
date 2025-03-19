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
int DTFecha::get_dia() {
    return this->dia;
};

int DTFecha::get_mes() {
    return this->mes;
};

int DTFecha::get_anio() {
    return this->anio;
};



