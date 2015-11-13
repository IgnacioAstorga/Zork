#include "stdafx.h"

#include "Opcion.h"

//********** CONSTRUCTORES ***********

Opcion::Opcion(std::string p_descripcion, std::vector<std::string> p_accionesCompatibles) {
	descripcion = p_descripcion;
	accionesCompatibles = p_accionesCompatibles;
}

Opcion::~Opcion() {
	// No necesita hacer nada
}

//************** MÉTODOS *************

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

void Opcion::imprimirOpcion() {
	Consola consola = Consola::obtenerInstancia();

	consola.imprimirCadena(getDescripcion());
}

void Opcion::elegirOpcion(std::string objetivo)
{
	unsigned int i;
	for (i = 0; i < acciones.size(); ++i) {
		if (!acciones[i]->realizarAccion(objetivo))
			break;
	}
}

void Opcion::addAccion(Accion* accion)
{
	acciones.push_back(accion);
}