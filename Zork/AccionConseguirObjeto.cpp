#include "stdafx.h"

#include "AccionConseguirObjeto.h"

AccionConseguirObjeto::AccionConseguirObjeto(Objeto * objeto)
	: AccionConseguirObjeto("", objeto) {}

AccionConseguirObjeto::AccionConseguirObjeto(std::string p_mensaje, Objeto* p_objeto)
	: AccionConMensaje(p_mensaje)
{
	objeto = p_objeto;
}

bool AccionConseguirObjeto::realizarAccion(std::string objetivo)
{
	Personaje::obtenerInstancia().addObjeto(objeto);
	return true;
}
