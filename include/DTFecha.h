class DTFecha {
    private:
        int dia, mes, anio;
    public:
    DTFecha();
    DTFecha(int,int,int);
    ~DTFecha();
    int get_dia();
    int get_mes();
    int get_anio();
    bool operator> (DTFecha);
    bool operator< (DTFecha); 
    bool operator== (DTFecha);
    bool operator!= (DTFecha);
    bool operator>= (DTFecha);
    bool operator<= (DTFecha);
};