principal : main.o ArticuloRevista.o DTFecha.o DTRefer.o Investigador.o Libro.o PaginaWeb.o Publicacion.o
	@gcc main.o ArticuloRevista.o DTFecha.o DTRefer.o Investigador.o Libro.o PaginaWeb.o Publicacion.o -o principal

main.o : main.cpp
	@gcc -c main.cpp

ArticuloRevista.o : ArticuloRevista.cpp
	@gcc -c ArticuloRevista.cpp

DTFecha.o : DTFecha.cpp	
	@gcc -c DTFecha.cpp	

DTRefer.o : DTRefer.cpp
	@gcc -c DTRefer.cpp

Investigador.o : Investigador.cpp
	@gcc -c Investigador.cpp

Libro.o : Libro.cpp
	@gcc -c Libro.cpp

PaginaWeb.o : PaginaWeb.cpp
	@gcc -c PaginaWeb.cpp

Publicacion.o : Publicacion.cpp
	@gcc -c Publicacion.cpp

