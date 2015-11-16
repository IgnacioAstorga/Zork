#include "stdafx.h"

#include "AccionFlag.h"

AccionFlag::AccionFlag(std::string codigoSituacion, std::string flag, int valor)
	: AccionFlag("", codigoSituacion, flag, valor) {}

AccionFlag::AccionFlag(std::string p_mensaje, std::string p_codigoSituacion, std::string p_flag, int p_valor)
	: AccionConMensaje(p_mensaje)
{
	codigoSituacion = p_codigoSituacion;
	flag = p_flag;
	valor = p_valor;
}

bool AccionFlag::realizarAccion(std::string p_objetivo)
{
	Situacion* situacion = &Mundo::obtenerInstancia().getSituacion(codigoSituacion);
	if (situacion == NULL)
		return false;

	situacion->setFlag(flag, valor);
	return true;
}