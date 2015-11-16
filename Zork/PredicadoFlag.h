#pragma once

#include "stdafx.h"

#include "Predicado.h"

class PredicadoFlag : public Predicado {

public:
	PredicadoFlag(const std::string flag, int valor);
	PredicadoFlag(const std::string flag, int valor, bool cierto);
	PredicadoFlag(const std::string codigoSituacion, const std::string flag, int valor);
	PredicadoFlag(const std::string codigoSituacion, const std::string flag, int valor, bool cierto);
	virtual bool esCierto();

private:
	std::string codigoSituacion;
	std::string flag;
	int valor;
	bool cierto;
};