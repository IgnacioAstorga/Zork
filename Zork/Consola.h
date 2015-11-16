#pragma once
#include "stdafx.h"

class Consola {

public:
	static void inicializar();
	static Consola& obtenerInstancia();

	void imprimirCadena(const std::string cadena);
	const std::string leerCadena();

protected:
	Consola();

private:
	static Consola* instancia;
};