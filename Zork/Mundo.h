#pragma once
#include "stdafx.h"

#include "Situacion.h"

class Mundo {

public:
	static void inicializar();
	static Mundo& obtenerInstancia();
	Situacion getSituacion(std::string identificadorSituacion);
	Situacion getSituacionActual();
	void setSituacionActual(Situacion situacion);


protected:
	Mundo();

private:
	static Mundo* instancia;
	Situacion situacionActual;
	void addSituacion(std::string clave, Situacion situacion);
};