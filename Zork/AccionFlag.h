#pragma once

#include "stdafx.h"

#include "AccionConMensaje.h"

class AccionFlag : public AccionConMensaje {

public:
	AccionFlag(std::string codigoSituacion, std::string flag, int valor);
	AccionFlag(std::string mensaje, std::string codigoSituacion, std::string flag, int valor);
	virtual bool realizarAccion(std::string objetivo);

private:
	std::string codigoSituacion;
	std::string flag;
	int valor;
};