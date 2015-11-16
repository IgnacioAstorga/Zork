#pragma once

#include "stdafx.h"

#include "Predicado.h"

class PredicadoNOT : public Predicado {

public:
	PredicadoNOT(Predicado* predicado);
	virtual bool esCierto();

private:
	Predicado* predicado;
};