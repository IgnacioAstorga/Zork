#include "stdafx.h"

#include "SituacionInicial.cpp"
#include "SEntradaCasa.cpp"

//************ VARIABLES *************
Mundo* Mundo::instancia = NULL;

//********** CONSTRUCTORES ***********

Mundo::Mundo() {
	// Carga las situaciones del juego
	addSituacion(*new SituacionInicial());
	addSituacion(*new SEntradaCasa());
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

std::string Mundo::getObjetivoActual()
{
	return objetivoActual;
}

void Mundo::setObjetivoActual(std::string p_objetivoActual)
{
	objetivoActual = p_objetivoActual;
}