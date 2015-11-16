#include "stdafx.h"

#include "AccionSoltarObjeto.h"

AccionSoltarObjeto::AccionSoltarObjeto()
	: AccionSoltarObjeto("", "") {}

AccionSoltarObjeto::AccionSoltarObjeto(std::string p_mensaje)
	: AccionSoltarObjeto(p_mensaje, "") {}

AccionSoltarObjeto::AccionSoltarObjeto(std::string p_mensaje, std::string p_codigoSituacion)
	: AccionConMensaje(p_mensaje)
{
	codigoSituacion = p_codigoSituacion;
}

bool AccionSoltarObjeto::realizarAccion(std::string objetivo)
{
	Situacion* situacion;
	if (codigoSituacion == "")
		situacion = &Mundo::obtenerInstancia().getSituacionActual();
	else
		situacion = &Mundo::obtenerInstancia().getSituacion(codigoSituacion);

	if (Personaje::obtenerInstancia().tieneObjetoConNombre(objetivo)) {
		Objeto* objeto = Personaje::obtenerInstancia().getObjetoPorNombre(objetivo);
		situacion->addObjeto(objeto);
		Personaje::obtenerInstancia().removeObjeto(objeto);
		Consola::obtenerInstancia().imprimirCadena("\n-> You drop the " + objetivo + ".\n");
		return true;
	}
	else
		return false;
}
