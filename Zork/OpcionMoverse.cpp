#include "stdafx.h"

#include "OpcionMoverse.h"

OpcionMoverse::OpcionMoverse(std::string descripcion, std::string norte, std::string sur, std::string este, std::string oeste, std::string arriba, std::string abajo)
	: Opcion(descripcion)
{
	accionesCompatibles.push_back("go");
	accionesCompatibles.push_back("travel");
}

void OpcionMoverse::elegirOpcion(std::string objetivo)
{
	Situacion* situacion = &Mundo::obtenerInstancia().getSituacionActual();
	if (objetivo == "north" && norte != "") {
		situacion = &Mundo::obtenerInstancia().getSituacion(norte);
	}
	else if (objetivo == "south" && sur != "") {
		situacion = &Mundo::obtenerInstancia().getSituacion(sur);
	}
	else if (objetivo == "east" && este != "") {
		situacion = &Mundo::obtenerInstancia().getSituacion(este);
	}
	else if (objetivo == "west" && oeste != "") {
		situacion = &Mundo::obtenerInstancia().getSituacion(oeste);
	}
	else if (objetivo == "up" && arriba != "") {
		situacion = &Mundo::obtenerInstancia().getSituacion(arriba);
	}
	else if (objetivo == "down" && abajo != "") {
		situacion = &Mundo::obtenerInstancia().getSituacion(abajo);
	}
	else {
		Consola::obtenerInstancia().imprimirCadena("-> " + objetivo + " is not a valid direction.");
	}
	Mundo::obtenerInstancia().setSituacionActual(*situacion);
}