#pragma once
#include "stdafx.h"

class Consola {

public:
	static void inicializar();
	static Consola& obtenerInstancia();

	void imprimirCadena(std::string cadena);
	std::string leerCadena();

protected:
	Consola();

private:
	static Consola* instancia;
};