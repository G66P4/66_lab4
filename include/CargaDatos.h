#ifndef CARGADATOS_H
#define CARGADATOS_H

class CargaDatos {
    private:
        static CargaDatos* instance;
        CargaDatos();

    public:
        static CargaDatos* getInstance();
        ~CargaDatos();
};

#endif