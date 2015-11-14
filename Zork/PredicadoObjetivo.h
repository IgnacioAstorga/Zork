#pragma once

#include "stdafx.h"

#include "Predicado.h"

class PredicadoObjetivo : public Predicado {

public:
	PredicadoObjetivo(std::string objetivo);
	PredicadoObjetivo(std::string objetivo, bool cierto);
	virtual bool esCierto();

private:
	std::string objetivo;
	bool cierto;
};