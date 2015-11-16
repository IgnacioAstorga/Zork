#pragma once
#include "stdafx.h"

class Personaje {

public:
	static void inicializar();
	static Personaje& obtenerInstancia();

	void addObjeto(Objeto* objeto);
	void removeObjeto(Objeto* objeto);
	bool tieneObjeto(const std::string codigoObjeto);
	bool tieneObjetoConNombre(const std::string nombre);
	Objeto* getObjeto(const std::string codigoObjeto);
	Objeto* getObjetoPorNombre(const std::string nombre);

protected:
	Personaje();

private:
	static Personaje* instancia;
	std::unordered_map<std::string, Objeto*> inventario;
};