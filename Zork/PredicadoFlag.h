#pragma once

#include "stdafx.h"

#include "Predicado.h"

class PredicadoFlag : public Predicado {

public:
	PredicadoFlag(std::string flag, int valor);
	PredicadoFlag(std::string flag, int valor, bool cierto);
	PredicadoFlag(std::string codigoSituacion, std::string flag, int valor);
	PredicadoFlag(std::string codigoSituacion, std::string flag, int valor, bool cierto);
	virtual bool esCierto();

private:
	std::string codigoSituacion;
	std::string flag;
	int valor;
	bool cierto;
};