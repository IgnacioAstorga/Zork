#include "stdafx.h"

#include "SituacionInicial.h"
#include "SEntradaCasa.h"
#include "SInteriorCasa.h"
#include "SPasilloCasa.h"

//************ VARIABLES *************
Mundo* Mundo::instancia = NULL;

//********** CONSTRUCTORES ***********

Mundo::Mundo() {
	// Carga las situaciones del juego
	addSituacion(*new SituacionInicial());
	addSituacion(*new SEntradaCasa());
	addSituacion(*new SInteriorCasa());
	addSituacion(*new SPasilloCasa());
}

//************** MÉTODOS *************

// Estáticos
void Mundo::inicializar() {
	instancia = new Mundo();
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