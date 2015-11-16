#pragma once

#include "stdafx.h"

#include "Predicado.h"

class PredicadoOR : public Predicado {

public:
	PredicadoOR(Predicado* predicado1, Predicado* predicado2);
	PredicadoOR(const std::vector<Predicado*> predicados);
	virtual bool esCierto();

private:
	std::vector<Predicado*> predicados;
};