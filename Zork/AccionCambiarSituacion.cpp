#include "stdafx.h"

#include "AccionCambiarSituacion.h"

AccionCambiarSituacion::AccionCambiarSituacion(std::string codigoSituacion)
	: AccionCambiarSituacion("", codigoSituacion) {}

AccionCambiarSituacion::AccionCambiarSituacion(std:: string p_mensaje, std::string p_codigoSituacion)
	: AccionConMensaje(p_mensaje)
{
	codigoSituacion = p_codigoSituacion;
}

bool AccionCambiarSituacion::realizarAccion(std::string objetivo)
{
	Situacion* situacion = &Mundo::obtenerInstancia().getSituacion(codigoSituacion);
	if (situacion != NULL) {
		Mundo::obtenerInstancia().setSituacionActual(*situacion);
		return true;
	}
	else
		return false;
}