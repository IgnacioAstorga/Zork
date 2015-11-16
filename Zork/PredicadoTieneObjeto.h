#pragma once

#include "stdafx.h"

#include "Predicado.h"

class PredicadoTieneObjeto : public Predicado {

public:
	PredicadoTieneObjeto(const std::string codigoObjeto);
	PredicadoTieneObjeto(const std::string codigoObjeto, bool cierto);
	virtual bool esCierto();

private:
	std::string codigoObjeto;
	bool cierto;
};