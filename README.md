 — Finger Bienes Raíces — 
=
Este repositorio contiene el desarrollo del sistema Finger Bienes Raíces©, una plataforma para la gestión de bienes inmuebles que permite la interacción entre clientes, p
ropietarios e inmobiliarias en procesos de compra, venta y alquiler de propiedades.
Este proyecto fue realizado como parte del Laboratorio 1 de Programación 4 (2025) de la Facultad de Ingeniería - Universidad de la República (UDELAR).

Funcionalidades principales del sistema
=
  Gestión de usuarios, diferenciando entre:

    Clientes

    Propietarios

    Inmobiliarias

  Alta de inmuebles (casas o apartamentos), con sus respectivos atributos:

    Casas: propiedad horizontal, tipo de techo

    Apartamentos: piso, ascensor, gastos comunes

  Administración de inmuebles por inmobiliarias, incluyendo fechas de inicio

  Generación de publicaciones (venta o alquiler) con historial y reglas de unicidad por tipo

  Agenda de visitas a inmuebles por parte de los clientes

  Sistema de suscripciones para que clientes y propietarios puedan seguir a inmobiliarias

  Notificaciones automáticas cada vez que una inmobiliaria realiza una nueva publicación

  Consulta y borrado de notificaciones por parte de clientes y propietarios

Tecnologías y ejecución
=

  Lenguaje: C++
  
  Plataforma de desarrollo: Linux
  
  Compilación: mediante Makefile incluido en el repositorio

Instrucciones:
=
En la carpeta documentacion se encuentran los diagramas, contratos y documentación previa a la implementación del sistema.
La carpeta codigo contiene todo el sistema junto con un archivo Makefile para simplificar su compilación.
Una vez descargado el proyecto, debe posicionarse en el directorio donde se guardó y ejecutar el comando make all. El sistema se compilará y ejecutará automáticamente.
