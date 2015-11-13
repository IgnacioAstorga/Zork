#pragma once
#include "stdafx.h"

#include "Accion.h"

class Opcion {

public:
	Opcion(std::string descripcion, std::vector<std::string> accionesCompatibles);
	virtual ~Opcion();
	std::string getDescripcion();
	bool accionCompatible(std::string accion);
	void imprimirOpcion();
	void elegirOpcion(std::string objetivo);
	void addAccion(Accion* accion);

protected:
	std::string descripcion;
	std::vector<std::string> accionesCompatibles;
	std::vector<Accion*> acciones;
};