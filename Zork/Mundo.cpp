#include "stdafx.h"

#include "SituacionInicial.cpp"

#include <unordered_map>

//************ VARIABLES *************
Mundo* Mundo::instancia = NULL;

std::unordered_map<std::string, Situacion*> mapaSituaciones;

//********** CONSTRUCTORES ***********

Mundo::Mundo() {
	// Carga la situaci�n inicial
	Situacion* situacion = new SituacionInicial();
	situacion->cargarSituacion();
	addSituacion(*situacion);

	// Establece la situaci�n inicial
	setSituacionActual(*situacion);
}

//************** M�TODOS *************

// Est�ticos
void Mundo::inicializar() {
	if (instancia == NULL) {
		instancia = new Mundo();
	}
}

Mundo& Mundo::obtenerInstancia()
{
	return *instancia;
}

// Propios
void Mundo::addSituacion(Situacion& situacion) {
	mapaSituaciones[situacion.getCodigoSituacion()] = &situacion;
}

Situacion& Mundo::getSituacion(std::string identificadorSituacion)
{
	return *mapaSituaciones[identificadorSituacion];
}

Situacion& Mundo::getSituacionActual()
{
	return *situacionActual;
}

void Mundo::setSituacionActual(Situacion& situacion)
{
	situacionActual = &situacion;
}