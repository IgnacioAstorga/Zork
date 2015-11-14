#include "stdafx.h"

#include "AccionMoverse.h"

AccionMoverse::AccionMoverse(std::string p_norte, std::string p_sur, std::string p_este, std::string p_oeste, std::string p_arriba, std::string p_abajo)
{
	norte = p_norte;
	sur = p_sur;
	este = p_este;
	oeste = p_oeste;
	arriba = p_arriba;
	abajo = p_abajo;
}

bool AccionMoverse::realizarAccion(std::string objetivo)
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
		Consola::obtenerInstancia().imprimirCadena("\n-> " + objetivo + " is not a valid direction.\n");
		return false;
	}
	Mundo::obtenerInstancia().setSituacionActual(*situacion);
	return true;
}