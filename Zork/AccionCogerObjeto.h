#pragma once

#include "stdafx.h"

#include "AccionConMensaje.h"

class AccionCogerObjeto : public AccionConMensaje {

public:
	AccionCogerObjeto(Objeto* objeto);
	AccionCogerObjeto(const std::string mensaje, Objeto* objeto);
	AccionCogerObjeto(const std::string mensaje, Objeto* objeto, const std::string codigoSituacion);
	virtual bool realizarAccion(const std::string objetivo);

private:
	Objeto* objeto;
	std::string codigoSituacion;
};