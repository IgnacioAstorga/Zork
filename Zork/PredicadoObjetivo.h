#pragma once

#include "stdafx.h"

#include "Predicado.h"

class PredicadoObjetivo : public Predicado {

public:
	PredicadoObjetivo(const std::vector<std::string> objetivos);
	PredicadoObjetivo(const std::vector<std::string> objetivos, bool cierto);
	virtual bool esCierto();

private:
	std::vector<std::string> objetivos;
	bool cierto;
};