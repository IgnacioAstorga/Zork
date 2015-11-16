#pragma once
#include "stdafx.h"

#include "Accion.h"

class Opcion {

public:
	Opcion(std::vector<std::string> accionesCompatibles);
	virtual ~Opcion();
	bool accionCompatible(std::string accion);
	void imprimirOpcion();
	void elegirOpcion(std::string objetivo);
	void addAccion(Accion* accion);

protected:
	std::vector<std::string> accionesCompatibles;
	std::vector<Accion*> acciones;
};