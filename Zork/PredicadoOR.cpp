#include "stdafx.h"

#include "PredicadoOR.h"

PredicadoOR::PredicadoOR(Predicado * predicado1, Predicado * predicado2)
{
	predicados = { predicado1, predicado2 };
}

PredicadoOR::PredicadoOR(std::vector<Predicado*> p_predicados)
{
	predicados = p_predicados;
}

bool PredicadoOR::esCierto()
{
	bool resultado = false;
	unsigned int i;
	for (i = 0; i < predicados.size(); ++i)
		resultado |= predicados[i]->esCierto();
	return resultado;
}
