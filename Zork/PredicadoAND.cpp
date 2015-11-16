#include "stdafx.h"

#include "PredicadoAND.h"

PredicadoAND::PredicadoAND(Predicado * predicado1, Predicado * predicado2)
{
	predicados = { predicado1, predicado2 };
}

PredicadoAND::PredicadoAND(std::vector<Predicado*> p_predicados)
{
	predicados = p_predicados;
}

bool PredicadoAND::esCierto()
{
	bool resultado = true;
	unsigned int i;
	for (i = 0; i < predicados.size(); ++i)
		resultado &= predicados[i]->esCierto();
	return resultado;
}
