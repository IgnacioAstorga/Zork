#pragma once
#include "stdafx.h"

#include <unordered_map>

#include "Situacion.h"

class Mundo {

public:
	static void inicializar();
	static Mundo& obtenerInstancia();
	void addSituacion(Situacion& situacion);
	Situacion& getSituacion(std::string identificadorSituacion);
	Situacion& getSituacionActual();
	void setSituacionActual(Situacion& situacion);

protected:
	Mundo();

private:
	static Mundo* instancia;
	Situacion* situacionActual;
	std::unordered_map<std::string, Situacion*> mapaSituaciones;
};