#include "stdafx.h"

//************ VARIABLES *************

Personaje* Personaje::instancia = NULL;

//********** CONSTRUCTORES ***********

Personaje::Personaje() {};

//************** M�TODOS *************

// Est�ticos
void Personaje::inicializar() {
	if (instancia == NULL) {
		instancia = new Personaje();
	}
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