#include "stdafx.h"

#include <unordered_map>

//************ VARIABLES *************
Mundo* Mundo::instancia = NULL;

std::unordered_map<std::string, Situacion> mapaSituaciones;

//********** CONSTRUCTORES ***********
Mundo::Mundo() {
	// Añadir todas las situaciones del juego al mapa de situaciones
	// TODO	addSituacion("situacion_inicial", new SituacionInicial());
	
	setSituacionActual(getSituacion("situacion_inicial"));
}

void Mundo::addSituacion(std::string clave, Situacion situacion) {
	mapaSituaciones[clave] = situacion;
}

//************** MÉTODOS *************

// Estáticos
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
Situacion Mundo::getSituacion(std::string identificadorSituacion)
{
	return mapaSituaciones[identificadorSituacion];
}

Situacion Mundo::getSituacionActual()
{
	return situacionActual;
}

void Mundo::setSituacionActual(Situacion situacion)
{
	situacionActual = situacion;
}