#include "stdafx.h"

#include "PredicadoFlag.h"

PredicadoFlag::PredicadoFlag(std::string p_flag, int p_valor)
	: PredicadoFlag("", p_flag, p_valor, true) {}

PredicadoFlag::PredicadoFlag(std::string p_flag, int p_valor, bool p_cierto)
	: PredicadoFlag("", p_flag, p_valor, p_cierto) {}

PredicadoFlag::PredicadoFlag(std::string p_codigoSituacion, std::string p_flag, int p_valor)
	: PredicadoFlag(p_codigoSituacion, p_flag, p_valor, true) {}

PredicadoFlag::PredicadoFlag(std::string p_codigoSituacion, std::string p_flag, int p_valor, bool p_cierto)
{
	codigoSituacion = p_codigoSituacion;
	flag = p_flag;
	valor = p_valor;
	cierto = p_cierto;
}

bool PredicadoFlag::esCierto()
{
	Situacion* situacion;
	if (codigoSituacion == "")
		situacion = &Mundo::obtenerInstancia().getSituacionActual();
	else
		situacion = &Mundo::obtenerInstancia().getSituacion(codigoSituacion);

	if (situacion != NULL) {
		bool resultado = situacion->getFlag(flag) == valor;
		return cierto ? resultado : !resultado;
	}
	else
		return false;
}
