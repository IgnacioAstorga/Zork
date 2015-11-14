#pragma once

#include "stdafx.h"

#include "Predicado.h"

class AccionCondicional : public Accion {

public:
	AccionCondicional(Predicado* condicion, Accion* onExito);
	AccionCondicional(Predicado* condicion, Accion* onExito, Accion* onFallo);
	virtual bool realizarAccion(std::string objetivo);

private:
	Predicado* condicion;
	Accion* onExito;
	Accion* onFallo;
};