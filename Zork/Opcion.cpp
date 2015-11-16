#include "stdafx.h"

#include "Opcion.h"

//********** CONSTRUCTORES ***********

Opcion::Opcion(std::vector<std::string> p_accionesCompatibles) {
	accionesCompatibles = p_accionesCompatibles;
}

Opcion::~Opcion() {
	// No necesita hacer nada
}

//************** MÉTODOS *************

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
	unsigned int i;
	for (i = 0; i < acciones.size(); ++i)
		acciones[i]->imprimirAccion();
}

void Opcion::elegirOpcion(std::string objetivo)
{
	unsigned int i;
	bool algunaCorrecta = false;
	for (i = 0; i < acciones.size(); ++i)
		algunaCorrecta |= acciones[i]->realizarAccion(objetivo);
	if (!algunaCorrecta)
		Consola::obtenerInstancia().imprimirCadena("\n-> " + objetivo + " is not a valid target.\n");
}

void Opcion::addAccion(Accion* accion)
{
	acciones.push_back(accion);
}