#include "../include/CargaDatos.h"
#include <cstddef>

CargaDatos* CargaDatos::instance = NULL;

CargaDatos::CargaDatos() {
    Factory* factory = Factory::getInstance();
    IControladorUsuario* controladorUsuario = factory->getIControladorUsuario();
    IControladorInmueble* controladorInmueble = factory->getIControladorInmueble();
    IControladorPublicacion* controladorPublicacion = factory->getIControladorPublicacion();
    IControladorFechaActual* controladorFechaActual = factory->getIControladorFechaActual();

    // Caso usuario cliente
    controladorUsuario->altaCliente("luisito23","qweasd12","Luis","luisito23@gmail.com","Pérez","46859342");
    controladorUsuario->altaCliente("anarojo88","claveAna1","Ana","anarojo88@hotmail.com","Rojo","31287465");

    //caso usuario propietario
    controladorUsuario->altaPropietario("marcelom", "banco123", "Marcelo", "marcelo.m@gmail.com", "123456789012", "099876543");
    controladorUsuario->altaPropietario("robertarce", "pass456", "Roberto", "roberto.a@yahoo.com", "987654321001", "091234567");
    controladorUsuario->altaPropietario("soledadf", "sole789", "Soledad", "soledad.f@gmail.com", "654321987654", "092345678");
    controladorUsuario->altaPropietario("martagal", "martA01", "Marta", "marta.galvez@outlook.com", "321098765432", "098765432");
    controladorUsuario->altaPropietario("jorge88", "jorgepass88", "Jorge", "jorge.rivera@uy.com", "890123456789", "097654321");

    // Caso usuario inmobiliaria
    controladorUsuario->altaInmobiliaria("casasur123", "casasur99", "Casa Sur", "contacto@casasur.com", "Canelones 2345", "https://casasur.com.uy", "24012345");
    controladorUsuario->altaInmobiliaria("idealhome", "home2025", "IHome","info@idealhome.uy", "Av. Italia 4567","https://idealhome.uy", "099123456");
    controladorUsuario->altaInmobiliaria("vivaurbana", "viva4567", "Viva Urbana", "contacto@vivaurbana.com", "18 de Julio 7890", "https://vivaurbana.com", "29109876");

    //caso inmueble
    // ── Casas ─────────────────────────────────────────────────────────────
    controladorInmueble->altaCasa("Av. Rivera",       1011, 120, 1995,  true,  TipoTecho::Plano,   "marcelom");
    controladorInmueble->altaCasa("Camino Maldonado", 1540,  95, 1988,  false, TipoTecho::Plano,   "robertarce");
    controladorInmueble->altaCasa("Juan Paullier",     801, 110, 200,  true,  TipoTecho::Liviano, "martagal");
    controladorInmueble->altaCasa("Cno. Carrasco",    1576, 140, 2007,  true,  TipoTecho::Plano,   "jorge88");
    // ── Apartamentos ──────────────────────────────────────────────────────
    controladorInmueble->altaApartamento("Av. Brasil",     2031,  75, 1980, 5,  true,  3500.0f, "marcelom");
    controladorInmueble->altaApartamento("Colonia",        1542,  60, 1978, 12, true,  2800.0f, "soledadf");
    controladorInmueble->altaApartamento("Bulevar Artigas",  871,  68, 2002, 3,  false, 2200.0f, "jorge88");
    controladorInmueble->altaApartamento("Sarmiento",      1476,  80, 2008, 6,  true,  3100.0f, "jorge88");

    //caso inmobiliaria representa propietario
    controladorUsuario->representarPropietario("casasur123", "marcelom");
    controladorUsuario->representarPropietario("idealhome",  "marcelom");
    controladorUsuario->representarPropietario("vivaurbana", "robertarce");
    controladorUsuario->representarPropietario("vivaurbana", "soledadf");
    controladorUsuario->representarPropietario("idealhome",  "martagal");
    controladorUsuario->representarPropietario("casasur123", "jorge88");
    controladorUsuario->representarPropietario("idealhome",  "jorge88");
    controladorUsuario->representarPropietario("vivaurbana", "jorge88");
    //caso inmobiliaria administra propiedad
    controladorFechaActual->setNewFechaActual(12, 12, 2015);
    controladorInmueble->altaAdministraPropiedad(2, "casasur123");   // 12/12/2015
    controladorFechaActual->setNewFechaActual(25, 9, 2023);
    controladorInmueble->altaAdministraPropiedad(1, "idealhome");    // 25/09/2023
    controladorFechaActual->setNewFechaActual(20, 7, 2022);
    controladorInmueble->altaAdministraPropiedad(3, "vivaurbana");   // 20/07/2022
    controladorFechaActual->setNewFechaActual(1, 1, 2022);
    controladorInmueble->altaAdministraPropiedad(4, "vivaurbana");   // 01/01/2022
    controladorFechaActual->setNewFechaActual(3, 7, 2010);
    controladorInmueble->altaAdministraPropiedad(5, "idealhome");    // 03/07/2010
    controladorFechaActual->setNewFechaActual(4, 11, 2019);
    controladorInmueble->altaAdministraPropiedad(6, "casasur123");   // 04/11/2019
    controladorFechaActual->setNewFechaActual(19, 5, 2020);
    controladorInmueble->altaAdministraPropiedad(6, "vivaurbana");   // 19/05/2020
    controladorFechaActual->setNewFechaActual(19, 7, 2024);
    controladorInmueble->altaAdministraPropiedad(6, "idealhome");    // 19/07/2024
    controladorFechaActual->setNewFechaActual(18, 9, 2023);
    controladorInmueble->altaAdministraPropiedad(7, "idealhome");    // 18/09/2023
    controladorFechaActual->setNewFechaActual(19, 5, 2022);
    controladorInmueble->altaAdministraPropiedad(8, "vivaurbana");   // 19/05/2022
    //caso alta publicacion
    // ── Publicaciones ────────────────────────────────────────────────────
controladorPublicacion->altaPublicacion("idealhome",   5, TipoPublicacion::Venta, "Casa al fondo Juan Paullier con 110 m fondo y techo liviano.", 47000.0f);
controladorPublicacion->altaPublicacion("casasur123",  2, TipoPublicacion::Alquiler, "Oportunidad en Av. Brasil: apartamento de 75 m piso 5 con ascensor.", 28000.0f);
controladorPublicacion->altaPublicacion("casasur123",  2, TipoPublicacion::Alquiler, "Apartamento luminoso en Av. Brasil piso alto con excelentes servicios.", 29500.0f);
controladorPublicacion->altaPublicacion("idealhome",   5, TipoPublicacion::Alquiler,"Casa ideal para familia en Juan Paullier barrio tranquilo.", 38500.0f);
controladorPublicacion->altaPublicacion("casasur123",  6, TipoPublicacion::Venta,"Apartamento en Bulevar Artigas piso 3 muy luminoso y moderno.", 375000.0f);
controladorPublicacion->altaPublicacion("casasur123",  2, TipoPublicacion::Venta, "Excelente apartamento en Av. Brasil con 75 m ideal para reforma.", 390000.0f);
controladorPublicacion->altaPublicacion("vivaurbana",  6, TipoPublicacion::Alquiler, "Apartamento 68 m en Bulevar Artigas tercer piso sin ascensor.", 23000.0f);
controladorPublicacion->altaPublicacion("vivaurbana",  4, TipoPublicacion::Alquiler, "Apartamento con ascensor en Colonia 1542 piso 12 excelente conectividad.", 26000.0f);
controladorPublicacion->altaPublicacion("vivaurbana",  3, TipoPublicacion::Alquiler, "Casa excelente en Camino Maldonado de 95 m con patio al fondo.", 27000.0f);
controladorPublicacion->altaPublicacion("idealhome",   1, TipoPublicacion::Venta, "Casa en Av. Rivera de 120 m con techo plano ideal para familia.", 520000.0f);
controladorPublicacion->altaPublicacion("idealhome",   7, TipoPublicacion::Alquiler, "Apartamento amplio en Sarmiento 1476 piso 6 con ascensor.", 32000.0f);
controladorPublicacion->altaPublicacion("idealhome",   7, TipoPublicacion::Venta, "Apartamento de 80 m en Sarmiento excelente estado y vista.", 455000.0f);
controladorPublicacion->altaPublicacion("idealhome",   7, TipoPublicacion::Alquiler, "Apartamento con gran vista a la rambla", 31000.0f);
controladorPublicacion->altaPublicacion("idealhome",   7, TipoPublicacion::Venta, "Aprtamente en excelentes condiciones de 80 m", 450000.0f);
controladorPublicacion->altaPublicacion("vivaurbana",  3, TipoPublicacion::Venta, "Venta de casa en Camino Maldonado 95 m bien distribuidos.", 430000.0f);
controladorPublicacion->altaPublicacion("idealhome",   7, TipoPublicacion::Alquiler, "Alquiler en Sarmiento 80 m piso alto con excelentes terminaciones.", 33000.0f);
controladorPublicacion->altaPublicacion("idealhome",   6, TipoPublicacion::Venta, "A estrenar en Bulevar Artigas 871 apartamento moderno.", 400000.0f);
//suscripciones
// ── Suscripciones a notificaciones ───────────────────────────────
controladorUsuario->suscribirNotificaciones("luisito23",  "casasur123");
controladorUsuario->suscribirNotificaciones("luisito23",  "idealhome");
controladorUsuario->suscribirNotificaciones("anarojo88",  "casasur123");
controladorUsuario->suscribirNotificaciones("anarojo88",  "idealhome");
controladorUsuario->suscribirNotificaciones("anarojo88",  "vivaurbana");
controladorUsuario->suscribirNotificaciones("marcelom",   "idealhome");
controladorUsuario->suscribirNotificaciones("robertarce", "idealhome");
controladorUsuario->suscribirNotificaciones("soledadf",   "vivaurbana");
controladorUsuario->suscribirNotificaciones("martagal",   "vivaurbana");
controladorUsuario->suscribirNotificaciones("jorge88",    "casasur123");
controladorUsuario->suscribirNotificaciones("jorge88",    "idealhome");
controladorUsuario->suscribirNotificaciones("jorge88",    "vivaurbana");


}

CargaDatos* CargaDatos::getInstance() {
    if (instance == 0) {
        instance = new CargaDatos();
    }
    return instance;
}