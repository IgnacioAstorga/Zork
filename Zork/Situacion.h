#pragma once
#include "stdafx.h"

#include <unordered_map>

#include "Opcion.h"

class Situacion {

public:
	std::string getCodigoSituacion();
	std::string getNombre();
	std::string getDescripcion();
	void imprimirSituacion();
	void elegirOpcion(std::string accion, std::string objetivo);
	void setFlag(std::string flag, int valor);
	int getFlag(std::string flag);
	virtual void cargarSituacion() = 0;

protected:
	void setCodigoSituacion(std::string nombre);
	void setNombre(std::string nombre);
	void setDescripcion(std::string descripcion);
	std::vector<Opcion>* getOpciones();

private:
	std::string codigoSituacion;
	std::string nombre;
	std::string descripcion;
	std::vector<Opcion> opciones;
	std::unordered_map<std::string, int> mapaFlags;
};