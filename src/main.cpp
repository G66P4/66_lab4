#include "../include/Menu.h"
#include <iostream>

int main() {
    while (true) {
        mostrarMenu();
        int opcion = obtenerOpcion();
        ejecutarOpcion(opcion);
        std::cout << std::endl;
    }
    return 0;
}