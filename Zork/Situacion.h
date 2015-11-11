#pragma once
#include "stdafx.h"

#include "Opcion.h"

class Situacion {

public:
	std::string getCodigoSituacion();
	std::string getNombre();
	std::string getDescripcion();
	void imprimirSituacion();
	void elegirOpcion(std::string accion, std::string objetivo);
	virtual void cargarSituacion() = 0;

protected:
	void setCodigoSituacion(std::string nombre);
	void setNombre(std::string nombre);
	void setDescripcion(std::string descripcion);
	std::vector<Opcion*>* getOpciones();

private:
	std::string codigoSituacion;
	std::string nombre;
	std::string descripcion;
	std::vector<Opcion*> opciones;
};