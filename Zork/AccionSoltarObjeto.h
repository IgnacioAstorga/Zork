#pragma once

#include "stdafx.h"

#include "AccionConMensaje.h"

class AccionSoltarObjeto : public AccionConMensaje {

public:
	AccionSoltarObjeto();
	AccionSoltarObjeto(const std::string mensaje);
	AccionSoltarObjeto(const std::string mensaje, const std::string codigoSituacion);
	virtual bool realizarAccion(const std::string objetivo);

private:
	std::string codigoSituacion;
};