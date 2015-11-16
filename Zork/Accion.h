#pragma once
#include "stdafx.h"

class Accion {

public:
	virtual bool realizarAccion(const std::string objetivo) = 0;
	virtual void imprimirAccion() = 0;
};