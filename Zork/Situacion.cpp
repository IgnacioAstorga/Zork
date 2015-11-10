#include "stdafx.h"

//************ VARIABLES *************

//********** CONSTRUCTORES ***********
Situacion::Situacion() {
	// Este constructor no deber�a utilizarse
}

Situacion::Situacion(std::string p_nombre, std::string p_descripcion, std::vector<Opcion*> p_opciones) {
	nombre = p_nombre;
	descripcion = p_descripcion;
	opciones = p_opciones;
}

Situacion::~Situacion() {
	// No necesita hacer nada
}

//************** M�TODOS *************

// Propios
std::string Situacion::getNombre()
{
	return std::string();
}

std::string Situacion::getDescripcion()
{
	return std::string();
}

void Situacion::elegirOpcion(std::string accion, std::string objetivo)
{
	unsigned int i;
	for (i = 0; i < opciones.size(); ++i) {
		Opcion* opcion = opciones[i];
		if (opcion->accionCompatible(accion)) {
			opcion->elegirOpcion(objetivo);
			break;
		}
	}
}