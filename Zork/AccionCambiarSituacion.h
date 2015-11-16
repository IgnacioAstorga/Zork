#pragma once

#include "stdafx.h"

#include "AccionConMensaje.h"

class AccionCambiarSituacion : public AccionConMensaje {

public:
	AccionCambiarSituacion(std::string codigoSituacion);
	AccionCambiarSituacion(std::string mensaje, std::string codigoSituacion);
	virtual bool realizarAccion(std::string objetivo);

private:
	std::string codigoSituacion;
};