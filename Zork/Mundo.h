#pragma once
#include "stdafx.h"

#include <unordered_map>

#include "Situacion.h"

class Mundo {

public:
	static void inicializar();
	static Mundo& obtenerInstancia();
	void addSituacion(Situacion& situacion);
	Situacion& getSituacion(const std::string identificadorSituacion);
	Situacion& getSituacionActual();
	void setSituacionActual(Situacion& situacion);
	const std::string getObjetivoActual();
	void setObjetivoActual(const std::string objetivoActual);

protected:
	Mundo();

private:
	static Mundo* instancia;
	Situacion* situacionActual;
	std::string objetivoActual;
	std::unordered_map<std::string, Situacion*> mapaSituaciones;
};