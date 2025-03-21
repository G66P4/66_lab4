#include "../include/Publicacion.h"  
#include "../include/Investigador.h"
#include "../include/ArticuloRevista.h"
#include "../include/DTFecha.h"
#include "../include/DTRefer.h"
#include "../include/PaginaWeb.h"
#include "../include/Libro.h"
#include <iostream>
#include <list>
#include <map>

std::list<Publicacion*> publicaciones;
std::map<std::string, Publicacion*> map_publicaciones;

std::list<Investigador*> investigadores;
std::map<std::string, Investigador*> map_investigadores;

void coleccion_guardarPublicacion(Publicacion* pub){
	publicaciones.push_back(pub);
	std::pair<std::string, Publicacion*> entry(pub->getDOI(), pub);
    map_publicaciones.insert(entry);
}
void coleccion_eliminarPublicacion(Publicacion* pub){
	publicaciones.remove(pub);
	map_publicaciones.erase(pub->getDOI());
}

void coleccion_guardarInvestigador(Investigador* inv){
	investigadores.push_back(inv);
	std::pair<std::string, Investigador*> entry(inv->getORCID(), inv);
    map_investigadores.insert(entry);
}

Investigador* coleccion_getInvestigador(std::string ORCID){
	return map_investigadores[ORCID];
}

Publicacion* coleccion_getPublicacion(std::string DOI){
	return map_publicaciones[DOI];
}

void parte_a(){
	/* //Creacion de articulos de revista
	ArticuloRevista *ar1= new ArticuloRevista("10.1234/abc123", "Fundamentos de POO", DTFecha(15,5,2023), "Programación Avanzada", "Introduccion a los principios fundamentales de la programacion orientada a objetos, explicando sus conceptos clave como clases, objetos, herencia y polimorfismo.");
	ArticuloRevista *ar2 = new ArticuloRevista("10.4567/jkl012", "Utilidad de diagramas UML", DTFecha(10,2,2024), "Modelado de Software", "Ejercicio empirico de como los diagramas UML pueden ayudar en el proceso y documentacion de software, cubriendo los tipos masimportantes utilizados, como clases.");
	//Se agregan a la coleccion
	coleccion_guardarPublicacion(ar1);
	coleccion_guardarPublicacion(ar2); */
}

void parte_b(){
/* 	//Creacion de Libros
	Libro *l1 = new Libro("10.2345/def456", "Patrones de Diseno en c++", DTFecha(20,8,2022), "Software Design",{ "Diseno", "OOP", "Class" });
	Libro *l2 = new Libro("10.5678/mno345", "Guia de UML", DTFecha(20,8,2022), "IEEE", { "UML", "Diagramas", "Software", "Modelado" });
	//Se agregan a la coleccion
	coleccion_guardarPublicacion(l1);
	coleccion_guardarPublicacion(l2); */
}

void parte_c(){
	//Creacion de Paginas Web
	PaginaWeb *pw1 = new PaginaWeb("10.3456/ghi789", "Diagramas para Principiantes", DTFecha(20,10,2024), "http://www.umlparaprincipiantes.com", "En esta pagina web se presenta una gui completa sobre los diagramas UML, abordando los diagramas de casos de uso, de clases, de secuencia y de actividades.");
	//Se agrega a la coleccion
	coleccion_guardarPublicacion(pw1);
}

void parte_d(){
	for (list<Publicacion*>::iterator it = publicaciones.begin(); it != publicaciones.end(); ++it){
			std::cout << (*it)->getDOI() << std::endl;
    }
}

void parte_e(){
	//Creacion de Investigadores
	Investigador *inv1 = new Investigador("0000-0003-1234-5678", "Carla Oliveri", "Universidad de la Republica");
	Investigador *inv2 = new Investigador("0000-0001-8765-4321", "Alberto Santos", "Instituto Tecnico");
	//Se agregan a la coleccion
	coleccion_guardarInvestigador(inv1);
	coleccion_guardarInvestigador(inv2);
}

void parte_f(){
	for (list<Investigador*>::iterator it = investigadores.begin(); it != investigadores.end(); ++it){
		std::cout << (*it)->toString() << std::endl;
	}
}

void parte_g(){
	//Asignacion de investigador a publicaciones
	coleccion_getInvestigador("0000-0003-1234-5678")->autor(coleccion_getPublicacion("10.1234/abc123"));
	coleccion_getInvestigador("0000-0003-1234-5678")->autor(coleccion_getPublicacion("10.4567/jkl012"));
	coleccion_getInvestigador("0000-0003-1234-5678")->autor(coleccion_getPublicacion("10.5678/mno345"));
	coleccion_getInvestigador("0000-0003-1234-5678")->autor(coleccion_getPublicacion("10.3456/ghi789"));
	coleccion_getInvestigador("0000-0001-8765-4321")->autor(coleccion_getPublicacion("10.1234/abc123"));
	coleccion_getInvestigador("0000-0001-8765-4321")->autor(coleccion_getPublicacion("10.2345/def456"));
	coleccion_getInvestigador("0000-0001-8765-4321")->autor(coleccion_getPublicacion("10.4567/jkl012"));
	//Asignacion de publicacion a investigadores
	//en produccion
}

void parte_h(){
	//Listar publicaciones de un investigador 0000-0003-1234-5678
	set<string> publicacionesInv1 = coleccion_getInvestigador("0000-0003-1234-5678")->listarPublicaciones(DTFecha(1,1,2023), "UML");
	for (set<string>::iterator it = publicacionesInv1.begin(); it != publicacionesInv1.end(); ++it){
		std::cout << *it << std::endl;
	}
}

void parte_i(){
	Publicacion *pub = coleccion_getPublicacion("10.4567/jkl012");
	coleccion_eliminarPublicacion(pub);
	pub->~Publicacion();
}

void parte_j(){
	set<string> publicacionesInv1 = coleccion_getInvestigador("0000-0003-1234-5678")->listarPublicaciones(DTFecha(1,1,2020), "UML");
	for (set<string>::iterator it = publicacionesInv1.begin(); it != publicacionesInv1.end(); ++it){
		std::cout << *it << std::endl;
	}
}

void parte_k(){
	parte_d();
}

void cleanUp(){

}
int main() {
	std::cout << "parte_a" <<  std::endl;
	parte_a();
	std::cout << "parte_b" <<  std::endl;
	parte_b();
	std::cout << "parte_c" <<  std::endl;
	parte_c();
	std::cout << "parte_d" <<  std::endl;
	parte_d();
	std::cout << "parte_e" <<  std::endl;
	parte_e();
	std::cout << "parte_f" <<  std::endl;
	parte_f();
	std::cout << "parte_g" <<  std::endl;
	parte_g();
	std::cout << "parte_h" <<  std::endl;
	parte_h();
	std::cout << "parte_i" <<  std::endl;
	parte_i();
	std::cout << "parte_j" <<  std::endl;
	parte_j();
	std::cout << "parte_k" <<  std::endl;
	parte_k();
	std::cout << "cleanUp" <<  std::endl;
	cleanUp();
	std::cout << "fin" <<  std::endl;

	return 0;
}
