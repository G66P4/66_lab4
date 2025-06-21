#include <iostream>
#include "../include/Menu.h"
#include "../include/CargaDatos.h"
#include "../include/TipoInmueble.h"
#include "../include/TipoPublicacion.h"
#include "../include/TipoTecho.h"
#include "../include/Factory.h"
#include "../include/DTApartamento.h"
#include "../include/DTCasa.h"
#include "../include/DTFecha.h"
#include "../include/DTInmueble.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTPublicacion.h"
#include "../include/DTUsuario.h"
#include "../include/IControladorUsuario.h"
#include "../include/IControladorFechaActual.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorInmueble.h"
#include "../include/ManejadorPublicacion.h"

#include <cstdlib> 
#include <string>
#include <set>
#include <vector>
#include <algorithm>

void mostrarMenu() {
    std::cout << "=== Menu de Operaciones ===" << std::endl;
    std::cout << "1. Alta de Usuario" << std::endl;
    std::cout << "2. Alta de Publicacion" << std::endl;
    std::cout << "3. Consulta de Publicaciones" << std::endl;
    std::cout << "4. Eliminar Inmueble" << std::endl;
    std::cout << "5. Suscribirse a Notificaciones" << std::endl;
    std::cout << "6. Consulta de Notificaciones" << std::endl;
    std::cout << "7. Eliminar Suscripciones" << std::endl;
    std::cout << "8. Alta de Administracion de Propiedad" << std::endl;
    std::cout << "9. Cargar Datos" << std::endl;
    std::cout << "10. Ver fecha actual" << std::endl;
    std::cout << "11. Asignar fecha actual" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Ingrese el codigo de operacion: ";
}

int obtenerOpcion() {
    int opcion;
    std::cin >> opcion;
    std::cin.ignore();
    return opcion;
}

void ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            std::cout << " - ALTA DE USUARIO - " << std::endl;
            altaUsuario();
            break;
        case 2:
            std::cout << " - ALTA DE PUBLICACION - " << std::endl;
            altaPublicacion();
            break;
        case 3:
            std::cout << " - CONSULTA DE PUBLICACIONES - " << std::endl;
            consultaPublicaciones();
            break;
        case 4:
            std::cout << " - ELIMINAR INMUEBLE - " << std::endl;
            eliminarInmueble();
            break;
        case 5:
            std::cout << " - SUSCRIBIRSE A NOTIFICACIONES - " << std::endl;
            suscribirseNotificaciones();
            break;
        case 6:
            std::cout << " - CONSLTAR NOTIFICACIONES - " << std::endl;
            consultaNotificaciones();
            break;
        case 7:
            std::cout << " - ELIMINAR SUSCRIPCIONES - " << std::endl;
            eliminarSuscripciones();
            break;
        case 8:
            std::cout << " - ALTA ADMINISTRACION DE PROPIEDAD - " << std::endl;
            altaAdministracionPropiedad();
            break;
        case 9:
            std::cout << " - CARGAR DATOS - " << std::endl;
            cargarDatos();
            break;
        case 10:
            std::cout << " - VER FECHA ACTUAL - " << std::endl;
            verFechaActual();
            break;
        case 11:
            std::cout << " - ASIGNAR FECHA ACTUAL - " << std::endl;
            asignarFechaActual();
            break;
        case 0:{
            std::cout << "Saliendo del programa..." << std::endl;
            ManejadorInmueble::liberarInstancia();
            ManejadorUsuario::liberarInstancia();
            ManejadorPublicacion::liberarInstancia();
            IControladorInmueble* CI = Factory::getInstance()->getIControladorInmueble();
            delete CI;
            IControladorUsuario* CU = Factory::getInstance()->getIControladorUsuario();
            delete CU;
            IControladorPublicacion* CP = Factory::getInstance()->getIControladorPublicacion();
            delete CP;
            IControladorFechaActual* CFecha = Factory::getInstance()->getIControladorFechaActual();
            delete CFecha;
            Factory::liberarInstancia();
            exit(0);
        }
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
    }
}

void altaUsuario(){

    Factory* factory = Factory::getInstance();

    std::cout << "Ingrese el tipo de usuario (0: Cliente, 1: Inmobiliaria, 2: Propietario): ";
    int tipoUsuario;
    std::cin >> tipoUsuario;
    std::cin.ignore();
    if (tipoUsuario < 0 || tipoUsuario > 2){
        std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        return;
    }

    bool usuarioOk = false;
    
    std::string nickname;
    std::string contrasena;
    std::string nombre;
    std::string email;
    std::string apellido;
    std::string documento;
    std::string url;
    std::string telefono;
    std::string direccion;
    std::string cuentaBancaria;
    
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Contrasena: ";
    std::getline(std::cin, contrasena);
    while (contrasena.length() < 6){
        std::cout << "La contraseña debe tener al menos 6 caracteres" << std::endl;
        std::getline(std::cin, contrasena);
    };
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Email: ";
    std::getline(std::cin, email);

    IControladorUsuario* IConUsu = factory->getIControladorUsuario();

    if (tipoUsuario == 0){
        std::cout << "Apellido: ";
        std::getline(std::cin, apellido);
        std::cout << "Documento: ";
        std::getline(std::cin, documento);
        usuarioOk = IConUsu->altaCliente(nickname, contrasena, nombre, email, apellido, documento);

    }else if (tipoUsuario == 1){
        std::cout << "Direccion: ";
        std::getline(std::cin, direccion);
        std::cout << "URL: ";
        std::getline(std::cin, url);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        usuarioOk = IConUsu->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);

    }else if (tipoUsuario == 2){
        std::cout << "Cuenta Bancaria: ";
        std::getline(std::cin, cuentaBancaria);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        usuarioOk = IConUsu->altaPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);

    }
    if (usuarioOk){
        if (tipoUsuario == 1 || tipoUsuario == 2){
            int salir = 1;
            std::cout << "¿Quiere ingresar los datos relacionados? (1: Si, 0: No): ";
            std::cin >> salir;
            std::cin.ignore();
            std::string inmuebleDireccion;
            int numeroPuerta;
            int superficie;
            int anoConstruccion;
            while (salir != 0){
                if (tipoUsuario == 1){
                    std::cout << "Lista de Propietarios:\n";
                    std::set<DTUsuario*> Propietarios = IConUsu->listarPropietarios();
                    //Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
                    for(std::set<DTUsuario*>::iterator it = Propietarios.begin(); it != Propietarios.end(); ++it) {
                        DTUsuario* dtu = *it;
                        std::cout << "- Nickname: " << dtu->getNickname() << ", Nombre: " << dtu->getNombre() << std::endl;
                        delete dtu;
                    }
                    if(Propietarios.empty()) {
                        std::cout << "No hay propietarios registrados." << std::endl;
                    }else{
                    std::cout << "Nickname propietario a representar: ";
                    std::string nicknamePropietario;
                    std::getline(std::cin, nicknamePropietario);
                    IConUsu->representarPropietario(nickname, nicknamePropietario);
                    }
                }else if (tipoUsuario == 2){
                    int tipoInmueble;
                    std::cout << "Indique el tipo de inmueble (1: Casa, 0: Apartamento): ";
                    std::cin >> tipoInmueble;
                    std::cin.ignore();
    
                    std::cout << "Direccion: ";
                    std::getline(std::cin, inmuebleDireccion);
                    std::cout << "Numero de Puerta: ";
                    std::cin >> numeroPuerta;
                    std::cin.ignore(); 
                    std::cout << "Superficie: ";
                    std::cin >> superficie;
                    std::cin.ignore();
                    std::cout << "Ano de Construccion: ";
                    std::cin >> anoConstruccion;
                    std::cin.ignore();

                    if (tipoInmueble == 1){
                        std::cout << "Es PH (1 para si, 0 para no): ";
                        int inEsPH;
                        std::cin >> inEsPH;
                        bool esPH = (inEsPH == 1);
                        std::cin.ignore();
                        std::cout << "Tipo de Techo (0: Liviano 1: A dos aguas, 2: Plano): ";
                        int inTipoTecho;
                        std::cin >> inTipoTecho;
                        std::cin.ignore();
                        TipoTecho techo = Liviano;
                        if(inTipoTecho == 1){
                            techo = A_dos_aguas;
                        }else if (inTipoTecho == 2){
                            techo = Plano;
                        }
                        //TODO: controlador->altaCasa(direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
                        IControladorInmueble* icontroladorInm = factory->getIControladorInmueble();
                        icontroladorInm->altaCasa(inmuebleDireccion, numeroPuerta, superficie, anoConstruccion, esPH, techo, nickname);
                    }else{
                        int piso;
                        std::cout << "Piso: ";
                        std::cin >> piso;
                        std::cin.ignore();
                        std::cout << "Tiene Ascensor (1 para si, 0 para no): ";
                        int inTieneAscensor;
                        std::cin >> inTieneAscensor;
                        bool tieneAscensor = (inTieneAscensor == 1);
                        std::cin.ignore();
                        std::cout << "Gastos Comunes: ";
                        float gastosComunes;
                        std::cin >> gastosComunes;
                        std::cin.ignore();
                        //TODO: controlador->altaApartamento(direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes)
                        IControladorInmueble* icontrolador = factory->getIControladorInmueble();
                        icontrolador->altaApartamento(inmuebleDireccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes, nickname);
                    }
                }
                std::cout << "¿Quiere seguir ingresando? (1: Si, 0: No): ";
                std::cin >> salir;
                std::cin.ignore();
            }
        }
    }else{
        std::cout << "Error al crear el usuario" << std::endl;
    }
}

void altaPublicacion(){

    Factory* factory = Factory::getInstance();

    std::cout << "Lista de Inmobiliarias:\n";
    //TODO: Coleccion de DTUsuario = controlador->listarInmobiliarias();
    //Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
    IControladorUsuario* IControladorUsu = factory->getIControladorUsuario();
    std::set<DTUsuario*> inmobiliarias = IControladorUsu->listarInmobiliarias();
    for(std::set<DTUsuario*>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        DTUsuario* dtu = *it;
        std::cout << "- Nickname: " << dtu->getNickname() << ", Nombre: " << dtu->getNombre() << std::endl;
        delete dtu;
    }
    if(inmobiliarias.empty()) {
        std::cout << "No hay inmobiliarias registradas." << std::endl;
        
    }else{
        std::cout << "Nickname de la inmobiliaria: ";
        std::string nicknameInmobiliaria;
        std::getline(std::cin, nicknameInmobiliaria);
        //TODO: Coleccion de DTInmuebleAdministrado = controlador->listarInmueblesAdministrados(nicknameInmobiliaria);
        //Recorrer la coleccion Mostrar "- Codigo: xx, Direccion: yy, Propietario: zzz"
        std::set<DTInmuebleAdministrado*> inmueblesAdministrados = IControladorUsu->listarInmueblesAdministrados(nicknameInmobiliaria);
        if (inmueblesAdministrados.empty()) {
            std::cout << "La inmobiliaria no administra ningún inmueble actualmente." << std::endl;
        }else{
        for(std::set<DTInmuebleAdministrado*>::iterator it = inmueblesAdministrados.begin(); it != inmueblesAdministrados.end(); ++it) {
            DTInmuebleAdministrado* dti = *it;
            std::cout << "- Codigo: " << dti->getCodigo() << ", Direccion: " << dti->getDireccion() << ", Fecha comienzo administracion: " << dti->getFechaComienzo() << std::endl;
            delete dti;
        }
        int codigoInmueble;
        std::cout << "Inmueble: ";
        std::cin >> codigoInmueble;
        std::cin.ignore();
        int inTipoPublicacion;
        std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
        std::cin >> inTipoPublicacion;
        TipoPublicacion tipoPublicacion = Alquiler;
        if(inTipoPublicacion == 1){
            tipoPublicacion = Venta;
        }
        std::cin.ignore();
        std::cout << "Texto: ";
        std::string texto;
        std::getline(std::cin, texto);
        std::cout << "Precio: ";
        float precio;
        std::cin >> precio;
        std::cin.ignore();
        //TODO:Controlador->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio)
        IControladorPublicacion* controladorPub = factory->getIControladorPublicacion();
        controladorPub->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio);
        //agregar notificar
        std::cout << "Publicacion creada exitosamente." << std::endl;
        }
    }
}

void consultaPublicaciones(){

    Factory* factory = Factory::getInstance();
    
    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler)";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if(inTipoPublicacion == 1){
        tipoPublicacion = Venta;
    }
    std::cin.ignore();
    std::cout << "Precio (Min): ";
    float precioMinimo;
    std::cin >> precioMinimo;
    std::cin.ignore();
    std::cout << "Precio (Max): ";
    float precioMaximo;
    std::cin >> precioMaximo;
    std::cin.ignore();
    int inTipoInmueble;
    std::cout << "Tipo de Inmueble: (1: Casa, 2: Apartamento, 0: Todos)";
    std::cin >> inTipoInmueble;
    std::cin.ignore();
    TipoInmueble tipoInmueble = Todos;
    if(inTipoInmueble == 1){
        tipoInmueble = casa;
    }else if(inTipoInmueble == 2){
        tipoInmueble = apartamento;
    }
    std::cout << "Publicaciones encontradas:\n";
    //TODO: Coleccion de DTPublicacion = Controlador->listarPublicacion(tipoPublicacion, precionMinimo, precioMaximo, tipoInmueble);
    //Recorrer la coleccion Mostrar "- Codigo: xx, fecha: dd/mm/yyyy, texto: zzz, precio: aaa, inmobiliaria: bbb";
    IControladorPublicacion* controladorPub = factory->getIControladorPublicacion();
    std::set<DTPublicacion*> publicaciones = controladorPub->listarPublicacion(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble);
    std::set<int> codigosPublicaciones;
  
    for(std::set<DTPublicacion*>::iterator it = publicaciones.begin(); it != publicaciones.end(); ++it) {
        DTPublicacion* dtp = *it;
        codigosPublicaciones.insert(dtp->getCodigo());
        std::cout << "- Codigo: " << dtp->getCodigo() << ", Fecha: " << dtp->getFecha() << ", Texto: " << dtp->getTexto() 
                  << ", Precio: " << dtp->getPrecio() << ", Inmobiliaria: " << dtp->get_Inmobiliaria() << std::endl;
        delete dtp;
    }
    int verDetalle;
    std::cout << "Ver detalle de la publicacion: (1: Si, 0: No)";
    std::cin >> verDetalle;
    std::cin.ignore();
    if (verDetalle == 1){
        std::cout << "Codigo de publicacion: ";
        int codigoPublicacion;
        std::cin >> codigoPublicacion;
        std::cin.ignore();
        if(codigosPublicaciones.find(codigoPublicacion) == codigosPublicaciones.end()) {
            std::cout << "Codigo de publicacion no encontrado." << std::endl;
        }else{
        std::cout << "Detalle del inmueble:\n";
        //TODO: DTInmueble = Controlador->detalleInmueblePublicacion(codigoPublicacion): DTInmueble
        //Mostrarlo:
        // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
        // Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
        IControladorInmueble* controladorInmueble = factory->getIControladorInmueble();
        DTInmueble* inmueble = controladorInmueble->detalleInmueblePublicacion(codigoPublicacion);
        std::cout << "Codigo: " << inmueble->getCodigo() 
                  << ", Direccion: " << inmueble->getDireccion() 
                  << ", Numero de Puerta: " << inmueble->getNumeroPuerta() 
                  << ", Superficie: " << inmueble->getSuperficie() 
                  << " m2, Ano Construccion: " << inmueble->getAnioConstruccion() << std::endl;
            if (dynamic_cast<DTApartamento*>(inmueble)) {
                DTApartamento* apto = dynamic_cast<DTApartamento*>(inmueble);
                std::cout << "Piso: " << apto->getPiso()
                        << ", Ascensor: " << (apto->getTieneAscensor() ? "Si" : "No")
                        << ", Gastos Comunes: " << apto->getGastosComunes() << std::endl;
            } else if (dynamic_cast<DTCasa*>(inmueble)) {
                DTCasa* casa = dynamic_cast<DTCasa*>(inmueble);
                std::cout << "Es PH: " << (casa->getEsPH() ? "Si" : "No")
                << ", Tipo de Techo: " << (casa->getTecho() == Liviano ? "Liviano" : (casa->getTecho() == A_dos_aguas ? "A dos aguas" : "Plano")) << std::endl;
            }
        delete inmueble;
        }
    }
}

void eliminarInmueble(){

    Factory* factory = Factory::getInstance();
    std::cout << "Listado de inmuebles:\n";
    //TODO: Coleccion de DTInmuebleListado = Controlador->listarInmuebles();
    //Recorrer la coleccion Mostrar "- Codigo: xx, direccion: xxxx, propietario: bbbbb";
    IControladorInmueble* controladorInm = factory->getIControladorInmueble();
    std::set<DTInmuebleListado*> inmuebles = controladorInm->listarInmuebles();
    for(std::set<DTInmuebleListado*>::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it) {
        DTInmuebleListado* dti = *it;
        std::cout << "- Codigo: " << dti->getCodigo() << ", Direccion: " << dti->getDireccion() << ", Propietario: " << dti->getPropietario() << std::endl;
        delete dti;
    }
    if(inmuebles.empty()) {
        std::cout << "No hay inmuebles registrados." << std::endl;
        return;
    }else{
        std::cout << "Codigo del inmueble a eliminar: ";
        int codigoInmueble;
        std::cin >> codigoInmueble;
        std::cin.ignore();
        if(!ManejadorInmueble::getInstance()->existeInmueble(codigoInmueble)) {
            std::cout << "Codigo de inmueble no encontrado." << std::endl;
            return;
        }else{
            std::cout << "Detalle del inmueble:\n";
            //TODO: DTInmueble = Controlador->detalleInmueble(codigoInmueble)
            //Mostrarlo:
            // Si es apartamento-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, piso: xx, ascensor: Si/No, gastos comunes: yyy"
            // Si es casa-> "Codigo: aaa, direccion: bbb, nro. puerta: ccc, superficie: xx m2, consturccion: dddd, PH: Si/No, Tipo de techo: Liviano/A dos aguas/Plano"
            DTInmueble* inmueble = controladorInm->detalleInmueble(codigoInmueble);
            std::cout << "Codigo: " << inmueble->getCodigo() 
                    << ", Direccion: " << inmueble->getDireccion() 
                    << ", Numero de Puerta: " << inmueble->getNumeroPuerta() 
                    << ", Superficie: " << inmueble->getSuperficie() 
                    << " m2, Ano Construccion: " << inmueble->getAnioConstruccion() << std::endl;
                if (dynamic_cast<DTApartamento*>(inmueble)) {
                    DTApartamento* apto = dynamic_cast<DTApartamento*>(inmueble);
                    std::cout << "Piso: " << apto->getPiso()
                            << ", Ascensor: " << (apto->getTieneAscensor() ? "Si" : "No")
                            << ", Gastos Comunes: " << apto->getGastosComunes() << std::endl;
                } else if (dynamic_cast<DTCasa*>(inmueble)) {
                        DTCasa* casa = dynamic_cast<DTCasa*>(inmueble);
                        std::cout << "Es PH: " << (casa->getEsPH() ? "Si" : "No")
                        << ", Tipo de Techo: " << (casa->getTecho() == Liviano ? "Liviano" : (casa->getTecho() == A_dos_aguas ? "A dos aguas" : "Plano")) << std::endl;
                }
            delete inmueble;
            int deseaEliminar;
            std::cout << "¿Desea eliminar?: (1: Si, 0: No)";
            std::cin >> deseaEliminar;
            std::cin.ignore();
            if (deseaEliminar == 1){
                //TODO: Controlador->eliminarInmueble(codigoInmueble)
                controladorInm->eliminarInmueble(codigoInmueble);
            }
        }
    }
}

void suscribirseNotificaciones(){
    Factory* factory = Factory::getInstance();
    IControladorUsuario* conUsu = factory->getIControladorUsuario();

    std::cout << "Que Tipo de Usuario desea Suscribir: (0: Cliente, 1:Propietario)";
    int tipoUsuario;
    std::cin >> tipoUsuario;
    std::cin.ignore();

    std::set<DTUsuario*> usuarioSet;
    if (tipoUsuario < 0 || tipoUsuario > 1){
        std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        return;
    }else if (tipoUsuario == 0){
        std::cout <<"Lista de Clientes:\n";
        usuarioSet = conUsu->listarClientes();
    }else if (tipoUsuario == 1){
        std::cout <<"Lista de Propietarios:\n";
        usuarioSet = conUsu->listarPropietarios();
    }
    for(std::set<DTUsuario*>::iterator it = usuarioSet.begin(); it != usuarioSet.end(); ++it) {
        DTUsuario* dtu = *it;
        std::cout << "- Nickname: " << dtu->getNickname() << ", Nombre: " << dtu->getNombre() << std::endl;
        delete dtu;
    }
    if(usuarioSet.empty()) {
        std::cout << "No hay usuarios registrados." << std::endl;
    }else{

        std::cout << "Nickname del usuario: ";
        std::string nicknameUsuario;
        std::getline(std::cin, nicknameUsuario);
        if(ManejadorUsuario::getInstance()->existeUsuario(nicknameUsuario) == false) {
            std::cout << "Usuario no encontrado. Intente de nuevo." << std::endl;
        }else{
            std::cout << "Lista de Inmobiliarias no Suscrito:\n";
            std::set<Inmobiliaria*> inmoNoSuscrito = conUsu->listarInmobiliariasNoSuscrito(nicknameUsuario);
            for(std::set<Inmobiliaria*>::iterator it = inmoNoSuscrito.begin(); it != inmoNoSuscrito.end(); ++it) {
                    Inmobiliaria* inm = *it;
                    std::cout << "- Nickname: " << inm->getNickname() << ", Nombre: " << inm->getNombre() << std::endl;
                }
                if(inmoNoSuscrito.empty()) {
                    std::cout << "No hay inmobiliarias disponibles para suscribirse." << std::endl;
                }else{
                int salir = 1;
                while(salir != 0){
                    std::cout << "Nickname Inmobiliaria a suscribir: ";
                    std::string nicknameInmobiliaria;
                    std::getline(std::cin, nicknameInmobiliaria);
                    if(ManejadorUsuario::getInstance()->existeUsuario(nicknameInmobiliaria) == false) {
                        std::cout << "Inmobiliaria no encontrada. Intente de nuevo." << std::endl;
                        continue;
                    }
                    conUsu->suscribirNotificaciones(nicknameUsuario, nicknameInmobiliaria);
                    
                    std::cout << "¿Desea seguir suscribiendose? (1: Si, 0: No): ";
                    std::cin >> salir;
                    std::cin.ignore();
                    std::set<Inmobiliaria*> inmoNoSuscrito = conUsu->listarInmobiliariasNoSuscrito(nicknameUsuario);
                    if(inmoNoSuscrito.empty()) {
                        std::cout << "No hay inmobiliarias disponibles para suscribirse." << std::endl;
                        return;
                    }
                }
            }
        }
    }
}

void consultaNotificaciones(){
    Factory* factory = Factory::getInstance();
    IControladorUsuario* conUsu = factory->getIControladorUsuario();
     std::cout << "Que Tipo de Usuario desea Consultar Suscripciones: (0: Cliente, 1:Propietario)";
    int tipoUsuario;
    std::cin >> tipoUsuario;
    std::cin.ignore();

    std::set<DTUsuario*> usuarioSet;
    if (tipoUsuario < 0 || tipoUsuario > 1){
        std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        return;
    }else if (tipoUsuario == 0){
        std::cout <<"Lista de Clientes:\n";
        usuarioSet = conUsu->listarClientes();
    }else if (tipoUsuario == 1){
        std::cout <<"Lista de Propietarios:\n";
        usuarioSet = conUsu->listarPropietarios();
    }
    for(std::set<DTUsuario*>::iterator it = usuarioSet.begin(); it != usuarioSet.end(); ++it) {
        DTUsuario* dtu = *it;
        std::cout << "- Nickname: " << dtu->getNickname() << ", Nombre: " << dtu->getNombre() << std::endl;
        delete dtu;
    }
    if(usuarioSet.empty()) {
        std::cout << "No hay usuarios registrados." << std::endl;
    }else{
    std::cout << "Ingrese el nickname del usuario a consultar: ";
    std::string nicknameUsuario;
    std::getline(std::cin, nicknameUsuario);
    std::list<DTNotificacion*> notificaciones = conUsu->listarNotificaciones(nicknameUsuario);
    if (notificaciones.empty()) {
        if(ManejadorUsuario::getInstance()->existeUsuario(nicknameUsuario) == false) {
            std::cout << "Usuario no encontrado. Intente de nuevo." << std::endl;
        }else{
        std::cout << "No hay notificaciones para el usuario " << nicknameUsuario << std::endl;
        return;
        }
    }else{
        std::cout << "Notificaciones para el usuario " << nicknameUsuario << ":\n";
        for (std::list<DTNotificacion*>::iterator it = notificaciones.begin(); it != notificaciones.end(); ++it) {
            DTNotificacion* dtn = *it;
            std::cout << "- Codigo: " << dtn->getCodigoPublicacion() 
                      << ", Fecha: " << dtn->getFechaPublicacion() 
                      << ", Texto: " << dtn->getTextoPublicacion() 
                      << ", Tipo Publicacion: " << (dtn->getTipoPublicacion() == Venta ? "Venta" : "Alquiler")
                      << ", Tipo Inmueble: " << (dtn->getTipoInmuebl() == casa ? "Casa" : "Apartamento")
                      << ", Inmobiliaria: " << dtn->getNickInmobiliaria() 
                      << std::endl;
        }
    }
  }
}

void eliminarSuscripciones(){
    Factory* factory = Factory::getInstance();
    IControladorUsuario* conUsu = factory->getIControladorUsuario();

    std::cout << "Que Tipo de Usuario desea Eliminar Suscripciones: (0: Cliente, 1:Propietario)";
    int tipoUsuario;
    std::cin >> tipoUsuario;
    std::cin.ignore();

    std::set<DTUsuario*> usuarioSet;
    if (tipoUsuario < 0 || tipoUsuario > 1){
        std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        return;
    }else if (tipoUsuario == 0){
        std::cout <<"Lista de Clientes:\n";
        usuarioSet = conUsu->listarClientes();
    }else if (tipoUsuario == 1){
        std::cout <<"Lista de Propietarios:\n";
        usuarioSet = conUsu->listarPropietarios();
    }
    for(std::set<DTUsuario*>::iterator it = usuarioSet.begin(); it != usuarioSet.end(); ++it) {
        DTUsuario* dtu = *it;
        std::cout << "- Nickname: " << dtu->getNickname() << ", Nombre: " << dtu->getNombre() << std::endl;
        delete dtu;
    }
    if(usuarioSet.empty()) {

        std::cout << "No hay usuarios registrados." << std::endl;

    }else{
        std::cout << "Nickname del usuario: ";
        std::string nicknameUsuario;
        std::getline(std::cin, nicknameUsuario);
        if(ManejadorUsuario::getInstance()->existeUsuario(nicknameUsuario) == false) {

            std::cout << "Usuario no encontrado. Intente de nuevo." << std::endl;

            return;

        }else{
            std::cout << "Lista de Inmobiliarias suscrito:\n";
            std::set<Inmobiliaria*> inmoSuscrito = conUsu->listarInmobiliariasSuscrito(nicknameUsuario);
            std::set<std::string> inmobiliariasSuscritas;
            for(std::set<Inmobiliaria*>::iterator it = inmoSuscrito.begin(); it != inmoSuscrito.end(); ++it) {
                Inmobiliaria* inm = *it;
                inmobiliariasSuscritas.insert(inm->getNickname());
                std::cout << "- Nickname: " << inm->getNickname() << ", Nombre: " << inm->getNombre() << std::endl;
            }
            int salir = 1;
            while(salir != 0){
                std::cout << "Nickname Inmobiliaria a eliminar suscripcion: ";
                std::string nicknameInmobiliaria;
                std::getline(std::cin, nicknameInmobiliaria);
                if(ManejadorUsuario::getInstance()->existeUsuario(nicknameInmobiliaria) == false) {

                    std::cout << "Inmobiliaria no encontrada. Intente de nuevo." << std::endl;

                    continue;

                }

                if(inmobiliariasSuscritas.find(nicknameInmobiliaria) == inmobiliariasSuscritas.end()) {

                    std::cout << "Inmobiliaria no suscrita. Intente de nuevo." << std::endl;

                    continue;

                }
                conUsu->eliminarSuscripcion(nicknameUsuario, nicknameInmobiliaria);

                std::cout << "¿Desea seguir eliminando suscripciones? (1: Si, 0: No): ";
                std::cin >> salir;
                std::cin.ignore();
            }
        }
    }
}

void altaAdministracionPropiedad(){
    Factory* factory = Factory::getInstance();

    std::cout << "Lista de Inmobiliarias:\n";
    //TODO: Coleccion de DTUsuario = controlador->listarInmobiliarias();
    //Recorrer la coleccion Mostrar "- Nickname: xx, Nombre: zz";
    IControladorUsuario* IControladorUsu = factory->getIControladorUsuario();
    std::set<DTUsuario*> inmobiliarias = IControladorUsu->listarInmobiliarias();
    for(std::set<DTUsuario*>::iterator it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        DTUsuario* dtu = *it;
        std::cout << "- Nickname: " << dtu->getNickname() << ", Nombre: " << dtu->getNombre() << std::endl;
        delete dtu;
    }
    if(inmobiliarias.empty()) {

        std::cout << "No hay inmobiliarias registradas." << std::endl;

    }else{
        std::cout << "Nickname de la inmobiliaria: ";
        std::string nicknameInmobiliaria;
        std::getline(std::cin, nicknameInmobiliaria);
        //TODO: Coleccion de DTInmuebleListado = Controlador->listarInmueblesNoAdministradosInmobiliaria(nicknameInmobiliaria);
        //Recorrer la coleccion Mostrar "- Codigo: xx, direccion: xxxx, propietario: bbbbb";
        IControladorInmueble* IControladorInm = factory->getIControladorInmueble();
        std::set<DTInmuebleListado*> inmueblesNoAdministrados = IControladorUsu->listarInmueblesNoAdministrados(nicknameInmobiliaria);
        std::vector<DTInmuebleListado*> inmueblesVec(inmueblesNoAdministrados.begin(), inmueblesNoAdministrados.end());

        std::sort(inmueblesVec.begin(), inmueblesVec.end(), [](DTInmuebleListado* a, DTInmuebleListado* b) {
            return a->getCodigo() < b->getCodigo();
        });

        std::cout << "Inmuebles no administrados por la inmobiliaria " << nicknameInmobiliaria << ":\n";
        std::set<int> codigosInmueblesNoAdministrados;
        for (DTInmuebleListado* dti : inmueblesVec) {
            codigosInmueblesNoAdministrados.insert(dti->getCodigo());
            std::cout << "- Codigo: " << dti->getCodigo() << ", Direccion: " << dti->getDireccion()
                    << ", Propietario: " << dti->getPropietario() << std::endl;
            delete dti;
        }
        if(inmueblesNoAdministrados.empty()) {

            std::cout << "No hay inmuebles no administrados por la inmobiliaria." << std::endl;

        }else{
            std::cout << "Codigo del inmueble a administrar: ";
            int codigoInmueble;
            std::cin >> codigoInmueble;
            std::cin.ignore();
            //TODO: Controlador->altaAdministraPropiedad(nicknameInmobiliaria, codigoInmueble);
            if(codigosInmueblesNoAdministrados.find(codigoInmueble) == codigosInmueblesNoAdministrados.end()) {
                if(ManejadorInmueble::getInstance()->existeInmueble(codigoInmueble) == false) {
                    std::cout << "Inmueble no encontrado." << std::endl;
                }else{
                    std::cout << "El inmueble ya esta administrado por la inmobiliaria" << std::endl;
                }
            }else{
                IControladorInm->altaAdministraPropiedad(codigoInmueble, nicknameInmobiliaria);
            }
        }
    }
}

void cargarDatos(){
    CargaDatos::getInstance();
    CargaDatos::getInstance()->liberarInstancia();
    
}

 void verFechaActual(){
    Factory* factory = Factory::getInstance();
    IControladorFechaActual* cfecha = factory->getIControladorFechaActual();
    DTFecha* fechaActual = cfecha->getFechaActual();
    std::cout << "fecha actual: " << fechaActual;
    delete fechaActual;
 }

 void asignarFechaActual(){
    Factory* factory = Factory::getInstance();
    IControladorFechaActual* cfecha = factory->getIControladorFechaActual();
    std::cout << "dia: ";
    int dia;
    std::cin >> dia;
    std::cin.ignore();
    std::cout << "mes: ";
    int mes;
    std::cin >> mes;
    std::cin.ignore();
    std::cout << "ano: ";
    int ano;
    std::cin >> ano;
    std::cin.ignore();
    cfecha->setNewFechaActual(dia, mes, ano);
 }