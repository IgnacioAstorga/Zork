#pragma once

#include "stdafx.h"

#include "Predicado.h"

class PredicadoObjetivo : public Predicado {

public:
	PredicadoObjetivo(std::vector<std::string> objetivos);
	PredicadoObjetivo(std::vector<std::string> objetivos, bool cierto);
	virtual bool esCierto();

private:
	std::vector<std::string> objetivos;
	bool cierto;
};