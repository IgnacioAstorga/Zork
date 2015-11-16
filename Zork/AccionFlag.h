#pragma once

#include "stdafx.h"

#include "AccionConMensaje.h"

class AccionFlag : public AccionConMensaje {

public:
	AccionFlag(const std::string codigoSituacion, const std::string flag, int valor);
	AccionFlag(const std::string mensaje, const std::string codigoSituacion, const std::string flag, int valor);
	virtual bool realizarAccion(const std::string objetivo);

private:
	std::string codigoSituacion;
	std::string flag;
	int valor;
};