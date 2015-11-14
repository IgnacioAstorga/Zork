#include "stdafx.h"

#include "PredicadoObjetivo.h"

PredicadoObjetivo::PredicadoObjetivo(std::string p_objetivo)
	: PredicadoObjetivo(p_objetivo, true) {}

PredicadoObjetivo::PredicadoObjetivo(std::string p_objetivo, bool p_cierto)
{
	objetivo = p_objetivo;
	cierto = p_cierto;
}

bool PredicadoObjetivo::esCierto()
{
	bool resultado = Mundo::obtenerInstancia().getObjetivoActual() == objetivo;
	return cierto ? resultado : !resultado;
}
