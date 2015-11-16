#pragma once

#include "stdafx.h"

#include "Predicado.h"

class AccionAlternativa : public Accion {

public:
	AccionAlternativa(Predicado* condicion, Accion* onCierto, Accion* onFalso);
	virtual bool realizarAccion(const std::string objetivo);
	virtual void imprimirAccion();

private:
	Predicado* condicion;
	Accion* onCierto;
	Accion* onFalso;
};