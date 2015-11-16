#pragma once
#include "stdafx.h"

#include "Accion.h"

class Opcion {

public:
	Opcion(std::vector<std::string> accionesCompatibles);
	virtual ~Opcion();
	bool accionCompatible(const std::string accion);
	void imprimirOpcion();
	void elegirOpcion(const std::string objetivo);
	void addAccion(Accion* accion);

protected:
	std::vector<std::string> accionesCompatibles;
	std::vector<Accion*> acciones;
};