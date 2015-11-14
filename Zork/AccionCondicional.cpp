#include "stdafx.h"

#include "AccionCondicional.h"

AccionCondicional::AccionCondicional(Predicado* p_condicion, Accion* p_onExito)
	: AccionCondicional(p_condicion, p_onExito, NULL) {}

AccionCondicional::AccionCondicional(Predicado* p_condicion, Accion* p_onExito, Accion* p_onFallo)
{
	onFallo = p_onFallo;
}

bool AccionCondicional::realizarAccion(std::string p_objetivo)
{
	if (condicion->esCierto() && onExito != NULL) {
		return onExito->realizarAccion(p_objetivo);
	}
	else if (!condicion->esCierto() && onFallo != NULL) {
		return onFallo->realizarAccion(p_objetivo);
	}
	else {
		return true;	// Las situaciones condicionales no producen errores por no cumplirse
	}
}