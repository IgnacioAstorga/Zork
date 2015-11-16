#include "stdafx.h"

#include "AccionAlternativa.h"

AccionAlternativa::AccionAlternativa(Predicado* p_condicion, Accion* p_onCierto, Accion* p_onFalso)
{
	condicion = p_condicion;
	onCierto = p_onCierto;
	onFalso = p_onFalso;
}

bool AccionAlternativa::realizarAccion(std::string objetivo)
{
	if (condicion->esCierto())
		return onCierto->realizarAccion(objetivo);
	else
		return onFalso->realizarAccion(objetivo);
}

void AccionAlternativa::imprimirAccion()
{
	onCierto->imprimirAccion();
	onFalso->imprimirAccion();
}