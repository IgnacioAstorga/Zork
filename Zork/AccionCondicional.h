#pragma once

#include "stdafx.h"

#include "Predicado.h"

class AccionCondicional : public Accion {

public:
	AccionCondicional(Predicado* condicion, Accion* acciones);
	AccionCondicional(Predicado* condicion, const std::vector<Accion*> acciones);
	virtual bool realizarAccion(const std::string objetivo);
	virtual void imprimirAccion();

private:
	Predicado* condicion;
	std::vector<Accion*> acciones;
};