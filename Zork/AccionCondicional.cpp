#include "stdafx.h"

#include "AccionCondicional.h"

AccionCondicional::AccionCondicional(Predicado* p_condicion, Accion* p_acciones)
{
	condicion = p_condicion;
	acciones = { p_acciones };
}

AccionCondicional::AccionCondicional(Predicado * p_condicion, std::vector<Accion*> p_acciones)
{
	condicion = p_condicion;
	acciones = p_acciones;
}

bool AccionCondicional::realizarAccion(std::string p_objetivo)
{
	bool cierto = condicion->esCierto();
	if (cierto) {
		unsigned int i = 0;
		for (i = 0; i < acciones.size(); ++i)
			if (acciones[i] != NULL)
				cierto &= acciones[i]->realizarAccion(p_objetivo);
	}

	return cierto;
}

void AccionCondicional::imprimirAccion()
{
	unsigned int i = 0;
	for (i = 0; i < acciones.size(); ++i)
		acciones[i]->imprimirAccion();
}