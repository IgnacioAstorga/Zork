#include "stdafx.h"

#include "Opcion.h"

//************ VARIABLES *************

//********** CONSTRUCTORES ***********
Opcion::Opcion(std::string p_descripcion, std::vector<std::string> p_accionesCompatibles) {
	descripcion = p_descripcion;
	accionesCompatibles = p_accionesCompatibles;
}

Opcion::~Opcion() {
	// No necesita hacer nada
}

//************** MÉTODOS *************

// Propios
std::string Opcion::getDescripcion()
{
	return descripcion;
}

bool Opcion::accionCompatible(std::string accion)
{
	unsigned int i = 0;
	for (i = 0; i < accionesCompatibles.size(); ++i) {
		if (compararCadenasSinMayusculas(accionesCompatibles[i], accion)) {
			return true;
		}
	}
	return false;
}
