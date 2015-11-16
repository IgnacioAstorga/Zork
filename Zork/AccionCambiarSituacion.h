#pragma once

#include "stdafx.h"

#include "AccionConMensaje.h"

class AccionCambiarSituacion : public AccionConMensaje {

public:
	AccionCambiarSituacion(const std::string codigoSituacion);
	AccionCambiarSituacion(const std::string mensaje, const std::string codigoSituacion);
	virtual bool realizarAccion(const std::string objetivo);

private:
	std::string codigoSituacion;
};