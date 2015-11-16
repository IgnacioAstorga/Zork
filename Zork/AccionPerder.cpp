#include "stdafx.h"

#include "AccionPerder.h"

AccionPerder::AccionPerder(std::string mensajeDerrota)
	: AccionPerder("", mensajeDerrota) {}

AccionPerder::AccionPerder(std::string p_mensaje, std::string p_mensajeDerrota)
	: AccionConMensaje(p_mensaje)
{
	mensajeDerrota = p_mensajeDerrota;
}

bool AccionPerder::realizarAccion(std::string objetivo)
{
	Juego::obtenerInstancia().perder(mensajeDerrota);
	return true;
}