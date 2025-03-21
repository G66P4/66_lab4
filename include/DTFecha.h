
#ifndef DTFECHA_H
#define DTFECHA_H


class DTFecha {
    private:
        int dia, mes, anio;
    public:
    DTFecha();
    DTFecha(int,int,int);
    ~DTFecha();
    int get_dia() const;
    int get_mes() const;
    int get_anio() const;
    bool operator> (DTFecha);
    bool operator< (DTFecha); 
    bool operator== (DTFecha);
    bool operator!= (DTFecha);
    bool operator>= (DTFecha);
    bool operator<= (DTFecha);
};
#endif

