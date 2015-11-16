#pragma once
#include "stdafx.h"

class Personaje {

public:
	static void inicializar();
	static Personaje& obtenerInstancia();

	void addObjeto(Objeto* objeto);

protected:
	Personaje();

private:
	static Personaje* instancia;
	std::unordered_map<std::string, Objeto*> inventario;
};