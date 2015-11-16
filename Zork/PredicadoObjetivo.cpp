#include "stdafx.h"

#include "PredicadoObjetivo.h"

PredicadoObjetivo::PredicadoObjetivo(std::vector<std::string> p_objetivos)
	: PredicadoObjetivo(p_objetivos, true) {}

PredicadoObjetivo::PredicadoObjetivo(std::vector<std::string> p_objetivos, bool p_cierto)
{
	objetivos = p_objetivos;
	cierto = p_cierto;
}

bool PredicadoObjetivo::esCierto()
{
	unsigned int i = 0;
	for (i = 0; i < objetivos.size(); ++i) {
		if (Mundo::obtenerInstancia().getObjetivoActual() == objetivos[i])
			return cierto;
	}
	return !cierto;
}
