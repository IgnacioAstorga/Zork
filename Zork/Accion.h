#pragma once
#include "stdafx.h"

class Accion {

public:
	virtual bool realizarAccion(std::string objetivo) = 0;
	virtual void imprimirAccion() = 0;
};