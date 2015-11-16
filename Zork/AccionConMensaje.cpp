#include "stdafx.h"

#include "AccionConMensaje.h"

AccionConMensaje::AccionConMensaje(std::string p_mensaje)
{
	mensaje = p_mensaje;
}

void AccionConMensaje::imprimirAccion()
{
	if (mensaje != "")
		Consola::obtenerInstancia().imprimirCadena(mensaje);
}
