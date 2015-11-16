#pragma once

#include "stdafx.h"

#include "Predicado.h"

class PredicadoAND : public Predicado {

public:
	PredicadoAND(Predicado* predicado1, Predicado* predicado2);
	PredicadoAND(const std::vector<Predicado*> predicados);
	virtual bool esCierto();

private:
	std::vector<Predicado*> predicados;
};