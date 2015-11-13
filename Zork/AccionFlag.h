#pragma once

#include "stdafx.h"

class AccionFlag : public Accion {

public:
	AccionFlag(std::string codigoSituacion, std::string flag, int valor);
	virtual bool realizarAccion(std::string objetivo);

private:
	std::string codigoSituacion;
	std::string flag;
	int valor;
};