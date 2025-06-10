#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include <string>


class DTInmobiliaria {
private:
    std::string url;
    std::string direccion;
    std::string telefono;
    std::string nickname;
public:
    DTInmobiliaria(std::string url, std::string direccion, std::string telefono);
    std::string getUrl();
    std::string getDireccion();
    std::string getTelefono();
    std::string getNickname();
    bool operator<(DTInmobiliaria& other);
};

#endif