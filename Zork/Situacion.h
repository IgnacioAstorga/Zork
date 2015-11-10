#pragma once
#include "stdafx.h"

#include "Opcion.h"

class Situacion {

public:
	Situacion();
	Situacion(std::string nombre, std::string descripcion, std::vector<Opcion*> opciones);
	~Situacion();
	std::string getNombre();
	std::string getDescripcion();
	void elegirOpcion(std::string accion, std::string objetivo);

private:
	std::string nombre;
	std::string descripcion;
	std::vector<Opcion*> opciones;
};