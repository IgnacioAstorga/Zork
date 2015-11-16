#pragma once

#include "stdafx.h"

#include "AccionConMensaje.h"

class AccionPerder : public AccionConMensaje {

public:
	AccionPerder(const std::string mensajeDerrota);
	AccionPerder(const std::string mensaje, const std::string mensajeDerrota);
	virtual bool realizarAccion(const std::string objetivo);

private:
	std::string mensajeDerrota;
};