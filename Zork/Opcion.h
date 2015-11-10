#pragma once
#include "stdafx.h"

#include "Situacion.h"

class Opcion {

public:
	Opcion(std::string descripcion, std::vector<std::string> accionesCompatibles);
	virtual ~Opcion();
	std::string getDescripcion();
	bool accionCompatible(std::string accion);
	virtual void elegirOpcion(std::string objetivo) = 0;

protected:
	std::string descripcion;
	std::vector<std::string> accionesCompatibles;
};