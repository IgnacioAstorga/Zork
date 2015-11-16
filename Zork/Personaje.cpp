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

void Personaje::removeObjeto(Objeto* objeto)
{
	inventario.erase(objeto->getCodigoObjeto());
}

bool Personaje::tieneObjeto(std::string codigoObjeto)
{
	return inventario.count(codigoObjeto) > 0;
}

bool Personaje::tieneObjetoConNombre(std::string nombre)
{
	std::unordered_map<std::string, Objeto*>::iterator it;
	for (it = inventario.begin(); it != inventario.end(); ++it)
		if (it->second != NULL && it->second->tieneNombre(nombre))
			return true;
	return false;
}

Objeto* Personaje::getObjeto(std::string codigoObjeto)
{
	if (!tieneObjeto(codigoObjeto))
		return NULL;
	else
		return inventario[codigoObjeto];
}

Objeto* Personaje::getObjetoPorNombre(std::string nombre)
{
	std::unordered_map<std::string, Objeto*>::iterator it;
	for (it = inventario.begin(); it != inventario.end(); ++it)
		if (it->second != NULL && it->second->tieneNombre(nombre))
			return it->second;
	return NULL;
}
