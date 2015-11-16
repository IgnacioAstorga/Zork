#include "stdafx.h"

#include "AccionCogerObjeto.h"

AccionCogerObjeto::AccionCogerObjeto(Objeto* p_objeto)
	: AccionCogerObjeto("", p_objeto, "") {}

AccionCogerObjeto::AccionCogerObjeto(std::string p_mensaje, Objeto* p_objeto)
	: AccionCogerObjeto(p_mensaje, p_objeto, "") {}

AccionCogerObjeto::AccionCogerObjeto(std::string p_mensaje, Objeto* p_objeto, std::string p_codigoSituacion)
	: AccionConMensaje(p_mensaje)
{
	objeto = p_objeto;
	codigoSituacion = p_codigoSituacion;
}

bool AccionCogerObjeto::realizarAccion(std::string objetivo)
{
	Situacion* situacion;
	if (codigoSituacion == "")
		situacion = &Mundo::obtenerInstancia().getSituacionActual();
	else
		situacion = &Mundo::obtenerInstancia().getSituacion(codigoSituacion);

	if (objeto != NULL) {
		Personaje::obtenerInstancia().addObjeto(objeto);
		situacion->removeObjeto(objeto);
		Consola::obtenerInstancia().imprimirCadena("\n-> You pick the " + objeto->getNombres()[0] + ".\n");
		return true;
	}
	else
		return false;
}
