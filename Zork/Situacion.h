#pragma once
#include "stdafx.h"

#include <unordered_map>

#include "Opcion.h"

class Situacion {

public:
	const std::string getCodigoSituacion();
	const std::string getNombre();
	const std::string getDescripcion();
	void imprimirSituacion();
	void elegirOpcion(const std::string accion, const std::string objetivo);
	void addObjeto(Objeto* objeto);
	void removeObjeto(Objeto* objeto);
	Objeto* getObjeto(const std::string codigoObjeto);
	Objeto* getObjetoPorNombre(const std::string nombre);
	void setFlag(const std::string flag, int valor);
	int getFlag(const std::string flag);
	virtual void cargarSituacion() = 0;
	void cargarOpcionesDeObjetos();

protected:
	void setCodigoSituacion(const std::string nombre);
	void setNombre(const std::string nombre);
	void setDescripcion(const std::string descripcion);
	std::vector<Opcion>* getOpciones();

private:
	std::string codigoSituacion;
	std::string nombre;
	std::string descripcion;
	std::vector<Opcion> opciones;
	std::unordered_map<std::string, int> mapaFlags;
	std::unordered_map<std::string, Objeto*> objetos;
};