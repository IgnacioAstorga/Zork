#include "stdafx.h"

#include "PredicadoNOT.h"

PredicadoNOT::PredicadoNOT(Predicado * p_predicado)
{
	predicado = p_predicado;
}

bool PredicadoNOT::esCierto()
{
	return !predicado->esCierto();
}
