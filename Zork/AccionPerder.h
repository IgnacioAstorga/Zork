#pragma once

#include "stdafx.h"

#include "AccionConMensaje.h"

class AccionPerder : public AccionConMensaje {

public:
	AccionPerder(std::string mensajeDerrota);
	AccionPerder(std::string mensaje, std::string mensajeDerrota);
	virtual bool realizarAccion(std::string objetivo);

private:
	std::string mensajeDerrota;
};