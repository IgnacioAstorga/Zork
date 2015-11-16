#pragma once

#include "stdafx.h"

class AccionConMensaje : public Accion {

public:
	AccionConMensaje(std::string mensaje);
	virtual void imprimirAccion();

private:
	std::string mensaje;
};