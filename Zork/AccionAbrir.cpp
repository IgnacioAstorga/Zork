#include "stdafx.h"

#include "AccionAbrir.h"

AccionAbrir::AccionAbrir(std::string p_objetivo, std::string p_destino)
{
	objetivo = p_objetivo;
	destino = p_destino;
}

bool AccionAbrir::realizarAccion(std::string p_objetivo)
{
	if (p_objetivo == objetivo) {
		Mundo::obtenerInstancia().setSituacionActual(Mundo::obtenerInstancia().getSituacion(destino));
		return true;
	}
	else {
		Consola::obtenerInstancia().imprimirCadena("-> " + objetivo + " is not a valid target.");
		return false;
	}
}