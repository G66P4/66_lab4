TARGET = principal
CC = g++

$(TARGET) : main.o ArticuloRevista.o DTFecha.o DTRefer.o Investigador.o Libro.o PaginaWeb.o Publicacion.o
	@g++ main.o ArticuloRevista.o DTFecha.o DTRefer.o Investigador.o Libro.o PaginaWeb.o Publicacion.o -o principal

main.o : main.cpp
	@g++ -c main.cpp

ArticuloRevista.o : ArticuloRevista.cpp
DTFecha.o : DTFecha.cpp	
DTRefer.o : DTRefer.cpp
Investigador.o : Investigador.cpp
Libro.o : Libro.cpp
PaginaWeb.o : PaginaWeb.cpp
Publicacion.o : Publicacion.cpp

.PHONY: clean
clean:
	rm -f *.o principal