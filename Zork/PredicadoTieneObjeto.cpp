#include "stdafx.h"

#include "PredicadoTieneObjeto.h"

PredicadoTieneObjeto::PredicadoTieneObjeto(std::string p_codigoObjeto)
	: PredicadoTieneObjeto(p_codigoObjeto, true) {}

PredicadoTieneObjeto::PredicadoTieneObjeto(std::string p_codigoObjeto, bool p_cierto)
{
	codigoObjeto = p_codigoObjeto;
	cierto = p_cierto;
}

bool PredicadoTieneObjeto::esCierto()
{
	if (Personaje::obtenerInstancia().tieneObjeto(codigoObjeto))
		return cierto;
	else
		return !cierto;
}
