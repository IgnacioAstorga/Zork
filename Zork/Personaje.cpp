#include "stdafx.h"

//************ VARIABLES *************

Personaje* Personaje::instancia = NULL;

//********** CONSTRUCTORES ***********

Personaje::Personaje() {};

//************** MÉTODOS *************

// Estáticos
void Personaje::inicializar() {
	instancia = new Personaje();
}

Personaje& Personaje::obtenerInstancia()
{
	return *instancia;
}

// Propios
void Personaje::addObjeto(Objeto* objeto)
{
	inventario[objeto->getCodigoObjeto()] = objeto;
}

bool Personaje::tieneObjeto(std::string codigoObjeto)
{
	return inventario.count(codigoObjeto) > 0;
}

Objeto* Personaje::getObjeto(std::string codigoObjeto)
{
	if (!tieneObjeto(codigoObjeto))
		return NULL;
	else
		return inventario[codigoObjeto];
}
